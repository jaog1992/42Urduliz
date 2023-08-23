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

#include "minitalk_bonus.h"

void	ft_handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				i = -1;
	static unsigned char	c;

	(void)ucontent;
	if (i < 0)
		i = 7;
	if (signum == SIGUSR1)
		c |= (1 << i);
	i--;
	if (i < 0 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			ft_print_error("Server failed to send SIGUSR2");
		return ;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_print_error("Failed to send SIGUSR1");
}

int	main(void)
{
	ft_printf("\nServer PID --> \033[0;92m%d\033[0;97m\n\n", getpid());
	while (1)
		config_signals(NULL, ft_handle_sigusr);
	return (EXIT_SUCCESS);
}
