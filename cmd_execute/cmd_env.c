/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoh <myoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 19:48:58 by myoh              #+#    #+#             */
/*   Updated: 2020/10/02 20:27:05 by myoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_env(t_minishell *minishell)
{
	int		i;
	//int		j;
	i = 0;
	while (minishell->env_set[i] != NULL)
	{
		ft_printf("%s=%s\n", minishell->env_set[i], minishell->env_set[i+1]);
		i++;
		i++;
	}
	ft_printf("\n");
}