#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	stroke;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		stroke = '.';
		ft_putendl(line);
		free(line);
		while (stroke != 32)
			stroke = getchar();
	}
	close(fd);
}
