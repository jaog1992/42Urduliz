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

#include "minitalk.h"

void	ft_handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				i = -1;
	static unsigned char	c;

	(void)ucontent;
	(void)info;
	if (i < 0)
		i = 7;
	if (signum == SIGUSR1)
		c |= (1 << i);
	i--;
	if (i < 0 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		return ;
	}
}

int	main(void)
{
	ft_printf("\nServer PID --> \033[0;92m%d\033[0;97m\n\n", getpid());
	while (1)
		config_signals(NULL, ft_handle_sigusr);
	return (EXIT_SUCCESS);
}
