/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:44:36 by plefevre          #+#    #+#             */
/*   Updated: 2022/03/18 01:14:33 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "get_next_line.h"

int	g_exit_status = 0;

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	t_cmd	*cmd;

	(void) av;
	(void) ac;
	data.env = parse_env(envp);
	add_pwd(&data);
	print_header(0);
	add_shlvl(&data);
	while (42)
	{
		get_cmd_signal();
		cmd = get_cmd(&data);
		if (cmd)
			exec_cmds(cmd, cmd, &data);
		else
			cmd_exit(cmd, cmd, &data);
		free_cmd(cmd);
	}
	exit_clean(&data, NULL);
	return (0);
}
