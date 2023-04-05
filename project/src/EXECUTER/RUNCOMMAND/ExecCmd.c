/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExecCmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasik <hasik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:28:18 by hasik             #+#    #+#             */
/*   Updated: 2023/03/19 19:28:20 by hasik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

void	exec_command(t_cmdlist *cmd_node, int *fd, int fd_index)
{
	char	*cmd;
	int		builtin_index;

	if (cmd_node && !cmd_node->cmd)
		return ;
	cmd = get_cmd(cmd_node->cmd);
	builtin_index = is_builtin(cmd);
	if (builtin_index)
		run_builtin(cmd_node, builtin_index, fd, fd_index);
	else
		run_execve(cmd_node, fd, fd_index);
}

char	*get_cmd(char *cmd)
{
	int		command_len;

	command_len = 0;
	while (*cmd)
	{
		command_len++;
		if (*cmd == '/')
			command_len = 0;
		cmd++;
	}
	return (cmd - command_len);
}
