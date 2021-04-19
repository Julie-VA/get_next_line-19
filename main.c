#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;
	// char	line[50];

	i = 0;
	fd = open("test.txt", O_RDONLY);
	// printf("%zd\n", read(fd, line, BUFFER_SIZE));
	if (BUFFER_SIZE != 0)
	{
		while (i < 2)
		{
			printf("%d\n", get_next_line(fd, &line));
			printf("%s\n\n", line);
			i++;
		}
		free(line);
	}
	close(fd);
	return (0);
}
