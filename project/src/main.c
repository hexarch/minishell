/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasik <hasik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:21:05 by hasik             #+#    #+#             */
/*   Updated: 2023/03/19 19:21:08 by hasik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	init_core(char **env)
{
	fill_envs(env);
	set_metachars();
	g_core.exec_output = 0;
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	if (argc != 1)
	{
		printf("You do not need to enter args...\n");
		return (0);
	}
	init_core(env);
	signal(SIGINT, signals);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		g_core.cmd = readline("\033[0;34mminishell-> \033[0m");
		lexer();
		expander();
		parser();
		executer();
		add_history(g_core.cmd);
		exit_signal_check();
		free_for_loop();
	}
	free_core();
}
