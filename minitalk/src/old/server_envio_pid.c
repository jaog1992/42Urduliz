/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:29:44 by marvin            #+#    #+#             */
/*   Updated: 2023/08/10 21:29:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
//#include "minitalk.h"

unsigned long bit_count = 0;
char received_binary_string[9]; // 8 bits + nulo

int parityCheck (int pid)
{
    int i;
    int k;

    while (i <= 6)
    {
        k += received_binary_string[i] - 48;
        i++;
    }
    if ((k % 2) == (received_binary_string[i] - 48))
        kill(pid, SIGUSR1);
    else 
        kill(pid, SIGUSR2);
}

void handleSIGUSR(int sig) {
    if (sig == SIGUSR1)
        received_binary_string[bit_count] = '0';
    else if (sig == SIGUSR2)
        received_binary_string[bit_count] = '1';
    bit_count++;
    
    if (bit_count >= 8) 
    {
        received_binary_string[8] = '\0';
        char received_char = strtol(received_binary_string, NULL, 2);
        write(1, &received_char, 1);
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

