#include "pipex.h"

int	load_files(t_data *data, int argc, char **argv)
{
	if (access(argv[1], F_OK))
		return (FALSE);
	data->fd[0] = open(argv[1], O_RDONLY);
	if (access(argv[argc - 1], F_OK))
	{
		data->fd[1] = creat(argv[argc - 1], 
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	}
	else
		data->fd[1] = open(argv[argc - 1], O_RDONLY);
	if (data->fd[0] == -1 || data->fd[1] == -1)
		return (ERROR_FD);
	return (TRUE);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	char	*cmd[2];

	if ((!BONUS && argc != 5) || argc < 5)
		write(1, "error\n", 6);
	else
	{
		if (load_files(&data, argc, argv) == FALSE)
			write(1, "error\n", 6);
		cmd[0] = argv[2];
		printf("%s\n", argv[2]);
		cmd[1] = argv[0];
		if (execve(argv[2], cmd, env) < 0)
			write(2, "error\n", 6);
	}
	return (0);
}