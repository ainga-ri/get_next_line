#include "get_next_line.h"

int main (void)
{
	int	fd;
	char *tmp;

	fd = open("ana.txt", O_RDONLY);
	tmp = get_next_line(fd);
	printf("Hola?? %s\n", tmp);
	if (!tmp)
		return (0);
	while (tmp)
	{
		printf("%s\n", tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	/*
	tmp = get_next_line(fd);
	printf("%s\n", tmp);
	free(tmp);
	tmp = get_next_line(fd);
	printf("%s\n", tmp);
	free(tmp);
	tmp = get_next_line(fd);
	printf("%s\n", tmp);
	free(tmp);
	*/
	//printf("%s\n", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);

}
