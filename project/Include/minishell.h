/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasik <hasik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:29:16 by hasik             #+#    #+#             */
/*   Updated: 2023/03/19 19:29:17 by hasik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include "macros.h"
# include "tables.h"
# include "utilits.h"
# include "lexer.h"
# include "expander.h"
# include "parser.h"
# include "executer.h"

t_core	g_core;

void	free_for_loop(void);
void	free_core(void);
void	signals(int sig);
void	exit_signal_check(void);

#endif
