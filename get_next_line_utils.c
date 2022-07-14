#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*nstr;
	size_t		i;

	i = 0;
	nstr = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!nstr)
		return (0);
	while (i < ft_strlen(s1))
	{
		nstr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		nstr[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	nstr[ft_strlen(s1) + i] = '\0';
	return (nstr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
