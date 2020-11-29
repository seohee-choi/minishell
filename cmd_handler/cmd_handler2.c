/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoh <myoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:14:48 by myoh              #+#    #+#             */
/*   Updated: 2020/11/30 00:00:42 by myoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	exec_else2(t_minishell *minishell, t_cmd *scmd, int pipe_fd[2])
{
	if (ft_strncmp(scmd->command, "echo\0", 5) == 0 && scmd->type != PIPE
		&& (!scmd->prev || scmd->prev->type != PIPE))
	{
		ft_printf("echo\n");//exit(1); //exit_cmd2(minishell, scmd, 0);
	}
	else if (ft_strncmp(scmd->command, "export\0", 7) == 0 && scmd->argv)
	{
		ft_printf("export\n");//export_cmd(minishell, scmd, 0);
	}
	else if (ft_strncmp(scmd->command, "cd\0", 3) == 0 && scmd->type != PIPE &&
		(!scmd->prev || scmd->prev->type != PIPE))
	{	//cd_cmd(minishell, scmd);
		ft_printf("cd\n");
		if (chdir(home_dir) < 0)
				return ;
	}
	else if (ft_strncmp(scmd->command, "unset\0", 5) == 0)
	{
		ft_printf("unset\n");
		//unset_cmd(minishell, scmd);
	}
	else if (!scmd->prev || (scmd->prev && !(scmd->prev->type == PIPE)))
	{
		ft_printf("pipe, redir\n");
		//exec_pipe2(minishell, scmd, pipe_fd, NULL);
	}
}

void		process_sym2(t_cmd *scmd)
{/*
	int		env;
	char	**split;

	env = 0;
	if (scmd->command && scmd->command[0] == '$')
		env = 1;
	if (scmd->command)
		scmd->command = handle_quotes(scmd->command, 1);
	if (env)
	{
		split = ft_ssplit(scmd->command, " \n");
		if (ft_count_split(split) > 1)
			add_more_args(scmd, split);
		ft_free_split(&split);
	}*/
}

void		process_sym(t_cmd *scmd)
{
	/*t_sym	*scmd_temp;
	char	**split;
	int		env;

	scmd_temp = scmd->sym_cmd;
	while (scmd_temp)
	{
		ft_printf("str:/%s/\n", scmd_temp->str);
		env = 0;
		if (scmd_temp->str && scmd_temp->str[0] == '$')
			env = 1;
		scmd_temp->str = exec_quotes(scmd_temp->str, 1);
		if (env)
		{
			split = ft_ssplit(scmd_temp->str, " \n");
			if (ft_count_split(split) > 1)
				scmd_temp = add_more_args2(scmd, &scmd_temp, split);
			ft_free_split(&split);
		}
		if (env && ft_strlen(scmd_temp->str) == 0)
			remove_redirect(scmd_temp, &scmd->sym_cmd);
		scmd = scmd->next;
	}
	process_sym2(scmd);*/
}

void	exec_scmd(t_minishell *minishell)
{
	t_cmd	*scmd;
	int		pipe_fd[2];

	scmd = minishell->scmd;
	while (scmd)
	{
		ft_printf("scmd->command: %s \n", scmd->command);
		//process_sym(scmd);
		create_redir(minishell, scmd);
		if (scmd->command && scmd->fdout != -1 && scmd->fdin != -1)
		{
			if (pipe(pipe_fd))
				return ;
			exec_else2(minishell, scmd, pipe_fd);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
		}
		if (!scmd->command && scmd->type != PIPE)
		{
			ft_printf("다음\n");
			//process_args_env(scmd);
			//add_scmd_env_variable(minishell, scmd);
		}
		while (scmd->type == PIPE)
			scmd = scmd->next;
		scmd = scmd->next;
	}
	
}