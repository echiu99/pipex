/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:47:18 by echiu             #+#    #+#             */
/*   Updated: 2024/04/22 18:59:45 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmd(char **argv, char **envp, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			j = 0;
			while (envp[i][j] && envp[i][j] != '=')
				j++;
			data->envp = envp;
			data->path_line = envp[i];
			data->path_line += j + 1;
			data->path_arr = ft_split(data->path_line, ':');
			data->arg1 = ft_split(argv[2], ' ');
			data->arg2 = ft_split(argv[3], ' ');
			data->cmd1 = ft_strjoin("/", data->arg1[0]);
			data->cmd2 = ft_strjoin("/", data->arg2[0]);
		}
		i++;
	}
}

void	first_process(t_data *data, int *end, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd < 0)
	{
		perror("File 1 cannot open");
		close(fd);
		free_all(data);
		exit(EXIT_FAILURE);
	}
	dup2(fd, 0);
	dup2(end[1], 1);
	close(end[0]);
	close(fd);
	execute_cmd1(data);
}

void	child_process(t_data *data, int *end, char **argv, int index)
{
	int		fd;

	if (index == 0)
		first_process(data, end, argv);
	if (index == 1)
	{
		fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd < 0)
		{
			perror("File 2 cannot open");
			close(fd);
			free_all(data);
			exit(EXIT_FAILURE);
		}
		dup2(fd, 1);
		dup2(end[0], 0);
		close(end[1]);
		close(fd);
		execute_cmd2(data);
	}
}

void	pipex(t_data *data, char **argv)
{
	int		status;
	int		child_index;
	int		end[2];
	pid_t	parent;

	pipe(end);
	child_index = 0;
	while (child_index < 2)
	{
		parent = fork();
		if (parent < 0)
			return (perror("Fork Error"));
		if (!parent)
			child_process(data, end, argv, child_index);
		child_index++;
	}
	waitpid(-1, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc == 5)
	{
		init_cmd(argv, envp, &data);
		pipex(&data, argv);
		free_all(&data);
	}
	else
	{
		perror("./pipex file1 cmd1 cmd2 file2");
		exit(EXIT_FAILURE);
	}
}
