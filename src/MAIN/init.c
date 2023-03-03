/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 02:08:52 by aozsayar          #+#    #+#             */
/*   Updated: 2022/12/28 02:08:52 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_core(char **env)
{
	fill_envs(env);
	set_metachars();
	// set_title();
	g_core.exec_output = 0;
	g_core.old_exec_output = 0;
	g_core.main_pid = getpid();
}
