/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoh <myoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:26:13 by myoh              #+#    #+#             */
/*   Updated: 2020/09/10 17:51:05 by myoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "./get_next_line/get_next_line_bonus.h"

/* 프롬프트 만들고 pwd부터 구현하기
현재 디렉토리 구하는 함수: getcwd (unistd에 있다)*/

void	display_prompt(void)
{
	char	buf[1024]; /*얼마를 넣어야 하나?*/
	char	*cwd; /*경로 */

	cwd = getcwd(buf, 1024);
	printf("cwd\n");
}

int		main(int ac, char **av, char **env)
{
	while (1)
	{
		display_prompt();
		/* get_next_line( ); */		
	}
}