/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:36:45 by adiehl-b          #+#    #+#             */
/*   Updated: 2025/08/31 15:58:13 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	return (envp[i] + 5);
}

static char	*build_and_check_path(char *dir, char *cmd)
{
	char	*part_path;
	char	*full_path;

	part_path = ft_strjoin(dir, "/");
	if (!part_path)
		return (NULL);
	full_path = ft_strjoin(part_path, cmd);
	free(part_path);
	if (!full_path)
		return (NULL);
	if (access(full_path, F_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

static char	*search_in_paths(char **paths, char *cmd)
{
	char	*result;
	int		i;

	i = 0;
	while (paths[i])
	{
		result = build_and_check_path(paths[i], cmd);
		if (result)
			return (result);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_env;
	char	*result;

	path_env = get_path_env(envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	result = search_in_paths(paths, cmd);
	free_array(paths);
	return (result);
}

void	execute(char *cmd, char **envp)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd || !s_cmd[0])
	{
		free_array(s_cmd);
		exit(ft_putstr_fds2("Command not found\n", 2));
	}
	if (access(s_cmd[0], X_OK) == 0)
		execve(s_cmd[0], s_cmd, envp);
	path = find_path(s_cmd[0], envp);
	if (!path)
	{
		free_array(s_cmd);
		exit(ft_putstr_fds2("Command not found\n", 2));
	}
	if (execve(path, s_cmd, envp) == -1)
	{
		free(path);
		free_array(s_cmd);
		error("Error");
	}
	free(path);
	free_array(s_cmd);
}
