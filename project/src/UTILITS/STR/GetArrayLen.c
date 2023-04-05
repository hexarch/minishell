/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetArrayLen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasik <hasik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:23:23 by hasik             #+#    #+#             */
/*   Updated: 2023/03/19 19:23:25 by hasik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

int	get_array_len(char **array)
{
	int	count;

	count = 0;
	while (array && *(array++))
		count++;
	return (count);
}
