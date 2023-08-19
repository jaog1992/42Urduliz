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

void sendHexadecimal(unsigned long num, int pid) {
    char hex_string[13]; // 12 caracteres hexadecimales + nulo
    sprintf(hex_string, "%012lx", num);

    printf("Hexadecimal value: %s\n", hex_string);

    for (int i = 0; hex_string[i] != '\0'; i++) {
        char hex_char = hex_string[i];
        int value = (hex_char >= '0' && hex_char <= '9') ? (hex_char - '0') : (hex_char - 'a' + 10);
        for (int j = 3; j >= 0; j--) {
            int bit = (value >> j) & 1;
            if (bit == 0) {
                printf("Sending 0 bit to server\n");
                kill(pid, SIGUSR1);
            } else {
                printf("Sending 1 bit to server\n");
                kill(pid, SIGUSR2);
            }
            usleep(50000); // Esperar medio segundo
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <PID_server> <string>\n", argv[0]);
        return 1;
    }

    int pid_dest = atoi(argv[1]); // Obtener el PID del servidor
    char *str = argv[2];
    char *ptr = str;

    unsigned long address_numeric = (unsigned long)ptr;
    sendHexadecimal(address_numeric, pid_dest); // Enviar valor hexadecimal como señales

    printf("Value at address: %s\n", ptr);

    return 0;
}
