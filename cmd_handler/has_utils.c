/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoh <myoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:53:45 by myoh              #+#    #+#             */
/*   Updated: 2020/12/06 21:22:11 by myoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int		is_char_here(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		is_instr(char c, char *str)
{
	if (is_char_here(c, str) >= 0)
		return (1);
	return (0);
}

int			has_pipes(char *option)
{
	int		res;

	res = 0;
	if (!option)
		return (res);
	while (*option)
	{
		if (*option == '|')
			res++;
		option++;
	}
	ft_printf("pipe개수: %d\n", res);
	return (res);
}

int			has_redirs(char *option)
{
	int		res;

	res = 0;
	if (!option)
		return (res);
	while (*option)
	{
		if (ft_strchr("<>", *option))
			res++;
		option++;
	}
	ft_printf("redirs개수: %d\n", res);
	return (res);
}

int		has_dollar(char *str)
{
	int	res;

	res = 0;
	while (str[res])
	{
		if (str[res] == '$')
			return (res);
		res++;
	}
	ft_printf("$있는가: %d\n", res);

	return (0);
}
int ft_isquote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int		has_quotes(char *str)
{
	int isdouble;
	int isquote;
	int i;

	isdouble = 0;
	isquote = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isquote(str[i]) == 1) //34
			isquote++;
		if (ft_isquote(str[i]) == 1) //39
			isdouble++;
		i++;
		if (isquote == 2 || isdouble == 2 || isdouble == 2)
			return (i);}

int		ft_is_alnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
	|| ft_isdigit(c))
		return (1);
	return (0);
}

int		has_env(char *str)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (i == 0 && (ft_isdigit(str[i]) || str[i] == '='))
			return (0);
		if (!ft_is_alnum(str[i]) && str[i] != '_' && str[i] != '='
			&& str[i] != '+' && str[i] != '\'' && str[i] != '\"')
			return (0);
		if ((str[i] == '\'' || str[i] == '\"') && cnt < 1)
			return (0);
		if (cnt == 0 && str[i] == '+' && str[i + 1] != '=')
			return (0);
		if (str[i] == '=')
			cnt++;
		i++;
	}
	if (cnt)
		return (1);
	return (0);
}