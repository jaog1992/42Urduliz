/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:29:31 by jde-orma          #+#    #+#             */
/*   Updated: 2023/08/10 21:29:31 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int ack_received = 0;

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

// Función para recibir la señal de ack del servidor
void handleACK(int sig)
{
    if (sig == SIGUSR1) 
        ack_received = 1;
    else if (sig == SIGUSR2)
        ack_received = 0;
}

void sendCharacter(char c, int pid_dest) 
{
    int i = 0;
    int parityBit;
    int bit;

    parityBit = calculateParityBit(c);
    c |= (parityBit << 7); // Agregar el bit de paridad
    while (i < 8)
    {
        bit = (c >> (7 - i)) & 1;
        if (bit == 0)
            kill(pid_dest, SIGUSR1);
        else
            kill(pid_dest, SIGUSR2);
        usleep(5000);
        i++;
    }
}

int main(int argc, char *argv[]) 
{
    int i = 0;
    int pid_dest;
    int retries;
    char *str;

    if (argc != 3) 
        return  (write(1, "Wrong argument count (!= 3): <client> <PID_server> <string>\n", 61));

    pid_dest = atoi(argv[1]);

    str = argv[2];
    signal(SIGUSR1, handleACK); // Configurar la señal de ack

    // Enviar el PID del cliente al servidor
    int pid_value = getpid();
    int j = 0;
    while (pid_value > 0 && j < 5) {
        char pid_digit = (pid_value % 10) + '0';
        int k = 0;
        while (k < 8) {
            int bit = (pid_digit >> (7 - k)) & 1;
            if (bit == 0)
                kill(pid_dest, SIGUSR1);
            else
                kill(pid_dest, SIGUSR2);
            usleep(5000);
            k++;
        }
        j++;
        pid_value /= 10;
    }

    // Envío del string desde argv[2]
    while (str[i] != '\0') 
    {
        ack_received = 0;
        retries = 0;
        while (!ack_received && retries < 3) 
        {
            sendCharacter(str[i], pid_dest);
            usleep(1000); // Esperar más tiempo por la respuesta del servidor
            retries++;
        }
        if (!ack_received) 
            return  (write(1, "Failed to send character.\n", 27));
        i++;
    }
    return 0;
}
