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

#include "minitalk_bonus.h"

size_t	send_str(pid_t pid_dest, char *str)
{
	unsigned char	c;
	int				nbr_bits;
	size_t			i;

	i = 0;
	while (*str)
	{
		c = *str;
		nbr_bits = 8;
		while (nbr_bits--)
		{
			if (c & (1 << 7))
				kill(pid_dest, SIGUSR1);
			else
				kill(pid_dest, SIGUSR2);
			usleep(50);
			c <<= 1;
		}
		str++;
		i++;
	}
	return (i);
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("\033[0;92m✔\033[0;97m");
}

int	main(int argc, char **argv)
{
	char			*str2;
	static size_t	i = 0;

	if (arg_error(argc, argv) > 0)
		return (EXIT_FAILURE);
	str2 = (char *)malloc(sizeof(char) * ft_strlen(argv[2]) + 1);
	if (!str2)
		return (EXIT_FAILURE);
	ft_printf("\nClient PID --> \033[0;92m%d\033[0;97m\n\n", getpid());
	ft_memcpy(str2, argv[2], ft_strlen(argv[2]) + 1);
	ft_printf("A \033[0;92m✔\033[0;97m for each correctly sent char\n\n");
	ft_printf("\033[0;94m%s\033[0;97m\n", str2);
	config_signals(sig_handler, NULL);
	i += send_str(ft_atoi(argv[1]), argv[2]);
	while (i < ft_strlen(argv[2]))
		pause();
	if (i == ft_strlen(argv[2]))
		ft_printf("\n\n");
	return (EXIT_SUCCESS);
}
