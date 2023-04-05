/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasik <hasik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:21:16 by hasik             #+#    #+#             */
/*   Updated: 2023/03/19 19:21:19 by hasik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	exit_signal_check(void)
{
	if (!g_core.cmd)
	{
		free_core();
		g_core.exit_status = 131;
		exit(131);
	}
}

void	signals(int sig)
{
	if (sig == 2)
	{
		g_core.exit_status = 130;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
