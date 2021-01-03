/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:21:33 by myoh              #+#    #+#             */
/*   Updated: 2021/01/03 21:16:07 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		init_num(t_minishell *minishell)
{
	g_pipe_num = 0;
	minishell->redir_num = 0;
}

int			check_last_token(char *input)
{
	char	*s;

	s = ft_trim(input);
	if (s[ft_strlen(s) - 1] == '|' || s[ft_strlen(s) - 1] == '>'
		|| s[ft_strlen(s) - 1] == '<')
	{
		ft_printf("올바르게 다시 입력하세요\n");
		free(input);
		free(s);
		return (-1);
	}
	free(g_input);
	g_input = NULL;
	g_input = ft_strdup(s);
	free(input);
	input = NULL;
	input = ft_strdup(s);
	free(s);
	s = NULL;
	return (1);
}

int			check_token(t_minishell *minishell, t_cmd *curr)
{
	char	*input;
	int		i;

	init_num(minishell);
	input = ft_strdup(g_input);
	i = 0;
	if (exceptions(input) < 0)
		return (0);
	if (check_last_token(input) < 0)
		return (0);
	while (input[i])
	{
		if (input[i] == '|')
			g_pipe_num++;
		else if (input[i] == '>' || input[i] == '<')
			minishell->redir_num++;
		i++;
	}
	free(input);
	input = NULL;
	return (1);
}

void		free_globals(void)
{
	free(g_input);
	g_input = NULL;
	if (g_cmd_array)
	{
		free_arr(g_cmd_array);
		g_cmd_array = NULL;
	}
}

void		clear_scmd(t_cmd *cmd, t_minishell *minishell)
{
	while (cmd)
	{
		if (cmd->command)
		{
			free(cmd->command);
			cmd->command = NULL;
		}
		if (cmd->pipe_bin)
			free(cmd->pipe_bin);
		if (cmd->pipe_array)
			free_arr(cmd->pipe_array);
		if (cmd->option)
			ft_strdel(&cmd->option);
		if (cmd->type)
			cmd->type = 0;
		if (cmd->typestr)
			free(cmd->typestr);
		cmd->fd = 0;
		cmd->argc = 0;
		cmd = cmd->next;
	}
}
