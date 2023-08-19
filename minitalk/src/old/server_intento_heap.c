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
#include <stdint.h>


unsigned long received_address = 0;
unsigned long bit_count = 0;
char received_binary_string[sizeof(unsigned long) * 8 + 1];
char received_string[100];

void printBinaryArray(const char *array, size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%c", array[i]);
    }
    printf("\n");
}

void handleSIGUSR1(int sig) {
    (void)sig;
    received_address <<= 1;
    received_binary_string[bit_count] = '0'; // Marcar el bit en el array
    bit_count++;

    printf("Received 0 bit - Bits received: %lu\n", bit_count);

    if (bit_count >= 48) { // Cambiado de 47 a 48
        received_binary_string[48] = '\0'; // Terminar la cadena
        printf("Received binary address: %s\n", received_binary_string);

        unsigned long numeric_address = strtoul(received_binary_string, NULL, 2); // Convertir a número

        printf("Received numeric address: %lu\n", numeric_address);

        // Traducir a hexadecimal y mostrar el valor
        printf("Hexadecimal value at address: %lx\n", numeric_address);

        char *ptr = (char *)(uintptr_t)numeric_address;
        strcpy(received_string, ptr);

        // Invertir el array de caracteres
        int len = strlen(received_string);
        for (int i = 0; i < len / 2; i++) {
            char temp = received_string[i];
            received_string[i] = received_string[len - i - 1];
            received_string[len - i - 1] = temp;
        }

        printf("Received reversed string: %s\n", received_string);

        printf("Value at address: %s\n", received_string);

        received_address = 0;
        bit_count = 0;
    }
}

void handleSIGUSR2(int sig) {
    (void)sig;

    received_address = (received_address << 1) | 1;
    received_binary_string[bit_count] = '1';
    bit_count++;

    printf("Received 1 bit - Bits received: %lu\n", bit_count);

    if (bit_count >= 48) { // Cambiado de 47 a 48
        received_binary_string[48] = '\0'; // Terminar la cadena
        printf("Received binary address: %s\n", received_binary_string);

        unsigned long numeric_address = strtoul(received_binary_string, NULL, 2); // Convertir a número

        printf("Received numeric address: %lu\n", numeric_address);

        // Traducir a hexadecimal y mostrar el valor
        printf("Hexadecimal value at address: %lx\n", numeric_address);

        char *ptr = (char *)(uintptr_t)numeric_address;
        strcpy(received_string, ptr);

        // Invertir el array de caracteres
        int len = strlen(received_string);
        for (int i = 0; i < len / 2; i++) {
            char temp = received_string[i];
            received_string[i] = received_string[len - i - 1];
            received_string[len - i - 1] = temp;
        }

        printf("Received reversed string: %s\n", received_string);

        printf("Value at address: %s\n", received_string);

        received_address = 0;
        bit_count = 0;
    }
}

int main() {
    printf("Receiver PID: %d\n", getpid());

    signal(SIGUSR1, handleSIGUSR1);
    signal(SIGUSR2, handleSIGUSR2);

    printf("Receiving binary data...\n");

    while (1) {
        sleep(1);
    }

    return 0;
}
