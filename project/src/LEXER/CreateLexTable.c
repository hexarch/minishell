/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreateLexTable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasik <hasik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:26:13 by hasik             #+#    #+#             */
/*   Updated: 2023/03/19 19:26:15 by hasik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

void	parse_cmd(char **cmd_line, t_lexlist *last_node)
{
	size_t	count;
	char	*holder_content;

	count = get_cmdlen(*cmd_line);
	holder_content = (char *)malloc(sizeof(char) * (count) + 1);
	last_node->content = holder_content;
	holder_content[count] = 0;
	while (count--)
		*(holder_content++) = *((*cmd_line)++);
}

void	create_lexlist(char *cmdline, t_lexlist **lex_table)
{
	t_lexlist	*last_node;

	trim_spaces(&cmdline);
	if (!cmdline || !*cmdline)
		return ;
	last_node = add_new_lex_node(lex_table);
	parse_cmd(&cmdline, last_node);
	create_lexlist(cmdline, lex_table);
}
