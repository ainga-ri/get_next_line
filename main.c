#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char	*get_next_line(int fd);
int main (void)
{
	/*
	int fd;
	char *buf;
	char *concat;
	ssize_t bytes;
	static int	i;
	
	fd = open("/Users/alfred/Desktop/CAMPUS42/cursus/get_next_line/test", O_RDONLY);
	if (fd == -1)
		printf("error reading the file");
	else
	{
		bytes = 0;
		i = 0;
		while (i < 6)
		{
			bytes = read(fd, buf, 2);
			concat = concat + buf;
			printf("El number de char es: %d, el contenido es: %s\n", (int)bytes, buf);
			i++;
		}
		//bytes = read(fd, buf, 10);
		close(fd);
		if (fd == 0)
			printf("archive empty");
		else
			printf("El number de char es: %d, el contenido es: %s\n", (int)bytes, buf);
	}
	*/
	/*
	char *var1 = "Marina i ";
	char *var2 = "Eevee";
	char  *new;
	var1 = (char *) malloc((strlen(var1) + strlen(var2)) * sizeof(char));
	strcat(var1, var2);
	printf("%s\n", var1);
	return (0);
	*/
	int	fd;

	fd = open ("test", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);

}
