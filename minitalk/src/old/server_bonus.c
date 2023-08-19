/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:29:44 by jde-orma          #+#    #+#             */
/*   Updated: 2023/08/10 21:29:44 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

unsigned long bit_count = 0;
char received_binary_string[9]; // 8 bits + nulo

int calculateParityBit(char c) 
{
    int parity = 0;
    int i = 0;

    while (i < 8)
    {
        parity ^= (c >> i) & 1;
        i++;
    }
    return parity;
}

void sendACK(int pid) 
{
    int pid_value = getpid();
    int i = 0;
    
    while (pid_value > 0 && i < 5) {
        char pid_digit = (pid_value % 10) + '0';
        int j = 0;
        while (j < 8) {
            int bit = (pid_digit >> (7 - j)) & 1;
            if (bit == 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(1000);
            j++;
        }
        i++;
        pid_value /= 10;
    }
}

void handleSIGUSR(int sig) {
    if (sig == SIGUSR1)
        received_binary_string[bit_count] = '0';
    else if (sig == SIGUSR2)
        received_binary_string[bit_count] = '1';
    bit_count++;

    if (bit_count >= 8) {
        received_binary_string[8] = '\0';
        char received_char = strtol(received_binary_string, NULL, 2);

        int received_parity = (received_char >> 7) & 1;
        int calculated_parity = calculateParityBit(received_char);

        if (received_parity == calculated_parity) 
        {
            write(1, &received_char, 1);
            sendACK(getppid());
        } 
        else
        {
            write(1, "!", 1);
            sendACK(getppid());
        }
        bit_count = 0;
    }
}

int main() {
    printf("%d\n", getpid());
    signal(SIGUSR1, handleSIGUSR);
    signal(SIGUSR2, handleSIGUSR);
    while (1)
        sleep(1);
    return 0;
}
