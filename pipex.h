/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:35:41 by echiu             #+#    #+#             */
/*   Updated: 2024/04/22 19:00:17 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include "sys/types.h"
# include "sys/wait.h"
# include <fcntl.h>

typedef struct s_data
{
	int		f1;
	int		f2;
	char	*path_line;
	char	*cmd1;
	char	*cmd2;
	char	**envp;
	char	**arg1;
	char	**arg2;
	char	**path_arr;
}	t_data;

void	execute_cmd1(t_data *data);
void	execute_cmd2(t_data *data);
void	ft_free_char2(char **tofree);
void	free_all(t_data *data);

#endif
