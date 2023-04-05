/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasik <hasik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:20:44 by hasik             #+#    #+#             */
/*   Updated: 2023/03/19 19:20:48 by hasik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	free_core(void)
{
	free_metachars();
	free_envtable();
	rl_clear_history();
}

void	free_for_loop(void)
{
	if (g_core.cmd)
	{
		free(g_core.cmd);
		g_core.cmd = NULL;
	}
	if (g_core.lex_table)
		free_lexer();
	if (g_core.cmd_table)
		free_parser();
	close_heradoc_file();
}
