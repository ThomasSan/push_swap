#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int 	i = 0;
	int 	total = 0;
	int 	fd;
	char	*line = NULL;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		total += ft_atoi(line);
		i++;
	}
	printf("average : %d/%d = %d\n", total, i, total/i);
	return (0);
}
