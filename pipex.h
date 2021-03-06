#ifndef PIPEX_H
# define PIPEX_H

#ifndef BONUS
#define BONUS 0
#endif

# define TRUE 0
# define FALSE 1
# define ERROR_FD -1

typedef struct s_data
{
	int		fd[2];
	int		fd_in;
	int		count;
	pid_t	pid;
	char	**cmds;

}	t_data;

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);

#endif