#include "get_next_line.h"

int main (void)
{
	int	fd;
	char *tmp;

	fd = open("alfred.txt", O_RDONLY);
	tmp = get_next_line(fd);
	if (!tmp)
		return (0);
	while (tmp)
	{
		printf("%s", tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (0);

}
