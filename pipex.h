#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

void	error(char *msg);
char	*find_path(char *cmd, char **envp);
void	execute(char *cmd, char **envp);

#endif