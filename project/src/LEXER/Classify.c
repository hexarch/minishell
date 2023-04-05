/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasik <hasik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:26:06 by hasik             #+#    #+#             */
/*   Updated: 2023/03/19 19:26:10 by hasik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

void	classify(t_lexlist *lex_table)
{
	char	*metachars;

	if (!lex_table)
		return ;
	while (lex_table)
	{
		metachars = compare_metachars(lex_table->content);
		if (metachars)
			lex_table->type = (*metachars - 1) * ft_strlen(metachars);
		else
			lex_table->type = 0;
		lex_table = lex_table->next;
	}
}
