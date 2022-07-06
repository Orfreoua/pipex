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

char	**load_cmds(int argc, char **argv)
{
	char	**cmds;
	int		i;
	
	cmds = malloc(sizeof(char *) * (argc - 2));
	if (!cmds)
		ft_putstr_fd("Malloc failed\n", 2);
	else
	{
		i = 2;
		while (i < (argc - 1))
		{
			cmds[i - 2] = ft_strdup(argv[i]);
			i++;
		}
		cmds[i - 1] = 0;
	}
	return (cmds);
}

//< infile cmd1 cmd2 > outfile

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if ((!BONUS && argc != 5) || argc < 5)
	{
		ft_putstr_fd("error wrong number of arguments\n", 2);
		//return (0);
	}
	if (load_files(&data, argc, argv) == FALSE)
		ft_putstr_fd("error the file descriptor miss loading\n", 2);
	data.cmds = load_cmds(argc, argv);
	if (!data.cmds)
		return (1);
	/*
	if (execve(argv[2], data.cmds, env) < 0)
		write(2, "error\n", 6);
	exit(0);*/
	int id = fork();
	if (id)
		printf("i'm parent %d\n", getpid());
	else
		printf("i'm child %d\n", getpid());
	
	int coucou[2];
	pipe(coucou);
	return (0);
}