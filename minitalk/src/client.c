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

#include "minitalk.h"

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
	(void)signum;
}

int	main(int argc, char **argv)
{
	static size_t	i = 0;

	if (arg_error(argc, argv) > 0)
		return (EXIT_FAILURE);
	config_signals(sig_handler, NULL);
	i += send_str(ft_atoi(argv[1]), argv[2]);
	while (i < ft_strlen(argv[2]))
		pause();
	return (EXIT_SUCCESS);
}
