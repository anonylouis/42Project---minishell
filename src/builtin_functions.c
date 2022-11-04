/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:49:20 by lcalvie           #+#    #+#             */
/*   Updated: 2022/03/16 23:49:35 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_in_builtin(char *cmd_name)
{
	if (!cmd_name)
		return (0);
	if (!ft_memcmp(cmd_name, "echo", 5)
		|| !ft_memcmp(cmd_name, "env", 4)
		|| !ft_memcmp(cmd_name, "export", 7)
		|| !ft_memcmp(cmd_name, "unset", 6)
		|| !ft_memcmp(cmd_name, "cd", 3)
		|| !ft_memcmp(cmd_name, "42", 3)
		|| !ft_memcmp(cmd_name, "pwd", 4)
		|| !ft_memcmp(cmd_name, "exit", 5))
		return (1);
	return (0);
}

int	execute_builtin(t_cmd *cmd, t_cmd *cmd_parent, t_data *data)
{
	if (cmd->cmd_path == NULL)
		return (1);
	else if (!ft_memcmp(cmd->cmd_path, "echo", 5))
		g_exit_status = cmd_echo(cmd);
	else if (!ft_memcmp(cmd->cmd_path, "env", 4))
		g_exit_status = cmd_env(cmd, data);
	else if (!ft_memcmp(cmd->cmd_path, "export", 7))
		g_exit_status = cmd_export(cmd, data);
	else if (!ft_memcmp(cmd->cmd_path, "unset", 6))
		g_exit_status = cmd_unset(cmd, data);
	else if (!ft_memcmp(cmd->cmd_path, "cd", 3))
		g_exit_status = cmd_cd(cmd->cmd, data);
	else if (!ft_memcmp(cmd->cmd_path, "42", 3))
		g_exit_status = cmd_42(cmd);
	else if (!ft_memcmp(cmd->cmd_path, "pwd", 4))
		g_exit_status = cmd_pwd(cmd);
	else if (!ft_memcmp(cmd->cmd_path, "exit", 5))
		g_exit_status = cmd_exit(cmd, cmd_parent, data);
	else
		return (1);
	return (0);
}
