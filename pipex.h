/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:36:52 by adiehl-b          #+#    #+#             */
/*   Updated: 2025/08/31 15:57:53 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	error(char *msg);
char	*find_path(char *cmd, char **envp);
void	execute(char *cmd, char **envp);
void	free_array(char **cmd);
int		ft_putstr_fds2(char *s, int fd);

#endif