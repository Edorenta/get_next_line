#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>

int	main(int ac, char **av)
{
    char    stroke;
	char	*line;
	int		fd[3], i, j;

	fd[0] = open(av[1], O_RDONLY);
	fd[1] = open(av[2], O_RDONLY);
	fd[2] = open(av[3], O_RDONLY);
    for (i = 0; i < 3; i++)
    {
        printf("\nFile %d header:\n", i + 1);
        for (j = 0; j < 10; j++)
        {
            get_next_line(fd[i], &line);
            if (line) ft_putendl(line);
            free(line);
            stroke = '.';
            while (stroke != 32)
			    stroke = getchar();
        }
	}
    for (i = 0; i < 3; i++)
        close(fd[i]);
	return (0);
}