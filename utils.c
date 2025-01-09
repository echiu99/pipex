/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:17:32 by echiu             #+#    #+#             */
/*   Updated: 2024/04/22 18:48:57 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd1(t_data *data)
{
	int		i;
	char	*cmd;

	i = 0;
	while (data->path_arr[i])
	{
		if (access(data->arg1[0], X_OK) == 0)
			cmd = ft_strdup(data->arg1[0]);
		else
			cmd = ft_strjoin(data->path_arr[i], data->cmd1);
		if (access(cmd, X_OK) == 0)
		{
			execve(cmd, data->arg1, data->envp);
			perror("Command 1 does not work");
			free(cmd);
			free_all(data);
			exit(EXIT_FAILURE);
		}
		free(cmd);
		i++;
	}
	perror("Command 1 non existing");
	free_all(data);
	exit(EXIT_FAILURE);
}

void	execute_cmd2(t_data *data)
{
	int		i;
	char	*cmd;

	i = 0;
	while (data->path_arr[i])
	{
		if (access(data->arg2[0], X_OK) == 0)
			cmd = ft_strdup(data->arg2[0]);
		else
			cmd = ft_strjoin(data->path_arr[i], data->cmd2);
		if (access(cmd, X_OK) == 0)
		{
			execve(cmd, data->arg2, data->envp);
			perror("Command 2 does not work");
			free(cmd);
			free_all(data);
			exit(EXIT_FAILURE);
		}
		free(cmd);
		i++;
	}
	perror("Command 2 non existing");
	free_all(data);
	exit(EXIT_FAILURE);
}

void	ft_free_char2(char **tofree)
{
	int	i;

	i = 0;
	while (tofree[i])
		free(tofree[i++]);
	free(tofree);
	return ;
}

void	free_all(t_data *data)
{
	ft_free_char2(data->path_arr);
	ft_free_char2(data->arg1);
	ft_free_char2(data->arg2);
	free(data->cmd1);
	free(data->cmd2);
	return ;
}
