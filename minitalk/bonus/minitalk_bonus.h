/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 07:52:27 by jde-orma          #+#    #+#             */
/*   Updated: 2023/08/11 07:52:27 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include "../libft/include/libft.h"

typedef void	(*t_cli_handler)(int);
typedef void	(*t_srv_handler)(int, siginfo_t *, void *);

int	arg_error(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		return (ft_print_error("Argv count != 3: <client> <PID> <string>\n"));
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			return (ft_print_error("Non digit chars entered for PID.\n"));
	if (*argv[2] == 0)
		return (ft_print_error("Empty message. Insert a non-empty string.\n"));
	return (0);
}

void	config_signals(t_cli_handler cli_handler, t_srv_handler srv_handler)
{
	struct sigaction	sa_modsignal;

	sa_modsignal.sa_flags = SA_SIGINFO;
	if (!srv_handler)
		sa_modsignal.sa_handler = cli_handler;
	if (!cli_handler)
		sa_modsignal.sa_sigaction = srv_handler;
	if (sigaction(SIGUSR1, &sa_modsignal, NULL) == -1)
		ft_print_error("Failed to modify SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_modsignal, NULL) == -1)
		ft_print_error("Failed to modify SIGUSR2's behavior");
}

#endif
