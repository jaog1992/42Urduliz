/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:29:31 by marvin            #+#    #+#             */
/*   Updated: 2023/08/10 21:29:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "minitalk.h"

// Usamos operador de bit >>, que equivale a dividir por 2 n veces: c >> n
// Así conseguimos ir traduciendo los 8 bits del char a binario, moviendo sus
// valores n posiciones a la derecha y evaluando el que queda en posicion LSB
// ejemplo: 75 en binario es == 00101110.(MSB ... LSB) 
//          El >> devuelve el valor del bit que se encuentra en el LSB 
//          c >> 7 desplaza 7 posiciones a la derecha: x x x x x x 0
//          c >> 6 desplaza 6 posiciones a la derecha: x x x x x 0 0
//          c >> 5 desplaza 5 posiciones a la derecha: x x x x 0 0 1
//          c >> 4 desplaza 4 posiciones a la derecha: x x x 0 0 1 0
//          ...
//          c >> 1 desplaza 4 posiciones a la derecha: x 0 0 1 0 1 1

unsigned long bit_paridad = 0;

int sendCharacter(char c, int pid) 
{
    int i;
    int bit;
    int check_paridad;

    i = 0;
    check_paridad = 0;
    while (i < 8) 
    {
        bit = (c >> (7 - i)) & 1;
        check_paridad += (int)bit;
        if (bit == 0) 
            kill(pid, SIGUSR1);
        else 
            kill(pid, SIGUSR2);
        usleep(5000);
        i++;
    }
    if  (check_paridad % 2 == 0 || check_paridad == 0)
        kill(pid, SIGUSR1);
    else 
        kill(pid, SIGUSR2); 
    return (check_paridad % 2);
}

void sendPid(int pid)
{
    char    *pid;
    int     i;

    i = 0;
    pid = ft_atoi(getpid());
    while (pid[i] != '\0')
    {
        sendCharacter(pid[i], pid_dest);
        i++;
    }  
}

int handleParitySIGUSR(int sig) 
{
    int received_paridad;
    if (sig == SIGUSR1)
        received_paridad = 0;
    else if (sig == SIGUSR2)
        received_paridad = 1;
    if (received_paridad == bit_paridad)
        return 1;
    else
        return = 0;
}

int main(int argc, char *argv[]) 
{
    int i;

    i = 0;
    if (argc != 3) 
    {
        write(1, "Wrong argument count (!= 3): <client> <PID_server> <string>\n", 61);
        return 1;
    }
    int pid_dest = ft_atoi(argv[1]);
    char *str = argv[2];
    if (i = 0)
        sendPid(pid_dest);
    while (str[i] != '\0')
    {
        bit_paridad = sendCharacter(str[i], pid_dest);
        usleep(100);
        i += signal(SIGUSR1, handleSIGUSR);
        i += signal(SIGUSR2, handleSIGUSR);
    }
    return 0;
}


