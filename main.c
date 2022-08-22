#include "get_next_line.h"
//#include "get_next_line_bonus.h"

int main (void)
{
	int	fd;
	char *tmp;

	fd = open("emptytext.txt", O_RDONLY);
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
