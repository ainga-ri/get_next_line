#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_change(char *str1, char *str2)
{
	char	*newstr;
	int	i;

	i = 0;
	newstr = (char *) malloc((strlen(str1) + strlen(str2)) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (str1[i])
	{
		newstr[i] = str1[i];
		i++;
	}
	i = 0;
	while (str2[i])
	{
		newstr[strlen(str1) + i] = str2[i];
	i++;
	}
	return (newstr);

}
int main(void)
{
	// TEST PARA VER COMO FUNCIONA EL FREE
	char	*str0;
	char	*str1 = "";
	char	*str2 = "alfred";
	//Allocating in a function
	str0 = ft_change(str1, str2);
	if (str0)
	{
		printf("%p\n", str0);
		free(str0);
		if (str0)
			printf("%p\n", str0);
	}
	return (0);
}
