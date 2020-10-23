/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoh <myoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:53:45 by myoh              #+#    #+#             */
/*   Updated: 2020/10/23 23:35:24 by myoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			has_pipes(t_cmd *curr, t_minishell *minishell)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (curr->option[i])
	{
		if (curr->option[i] == '|')
		{
			res++;
		}
		i++;
	}
	return (res);
}