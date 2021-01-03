/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:26:22 by myoh              #+#    #+#             */
/*   Updated: 2021/01/03 16:01:41 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void			last_input(char *temp, int type, t_cmd *head)
{
	if (temp)
	{
		if (type == PIPE)
			type = LASTPIPE;
		else
			type = LASTREDIR;
		head = add_next_node(head, ft_trim(temp), type);
	}
}

void			sub_input(char **temp, char *temp3, int i, int type)
{
	temp3 = ft_strdup(*temp);
	free(*temp);
	*temp = NULL;
	if (type == 6)
	 	*temp = ft_substr(temp3, i + 2, ft_strlen(temp3) - i - 1);
	else
		*temp = ft_substr(temp3, i + 1, ft_strlen(temp3) - i);
	free(temp3);
}

void			all_parse(t_cmd *head, char *temp, char *temp2, char *temp3,
				int i, int type)
{
	while (temp[++i])
	{
		while (temp[i] == '<' || temp[i] == '>' || temp[i] == '|')
		{
			temp2 = ft_substr(temp, 0, i);
			if (temp[i] == '>' && temp[i + 1] != '>')
				type = REDIR;
			else if (temp[i] == '|')
				type = PIPE;
			else if (temp[i] == '>' && temp[i + 1] == '>')
			{
				type = DREDIR;
				i++;
			}
			else
				type = BREDIR;
			add_next_node(head, ft_trim(temp2), type);
			free(temp2);
			sub_input(&temp, temp3, i, type);
			i = -1;
		}
	}
	last_input(temp, type, head);
}

int				parse_flags(t_cmd *head, t_minishell *minishell)
{
	int			i;
	int			type;
	char		*temp;
	char		*temp2;
	char		*temp3;

	temp = ft_strdup(g_input);
	i = -1;
	if (temp != NULL)
		all_parse(head, temp, temp2, temp3, i, type);
	if (temp && temp != NULL)
	{
		free(temp);
		temp = NULL;
	}
	if (temp2 && temp2 != NULL)
	{
		free(temp2);
		temp2 = NULL;
	}
	return (1);
}