#include "get_next_line.h"

int main (void)
{
	int	fd;
	char tmp[1000000];

	fd = open("test", O_RDONLY);
	tmp = get_next_line(fd);
	if (!tmp)
		return (0);
	while (tmp)
	{
		printf("%s\n", tmp);
		free(tmp);
		//printf("hola???");
		tmp = get_next_line(fd);
		//printf("hola");
	}
	close(fd);
	return (0);

}
