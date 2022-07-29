#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*nstr;
	size_t		i;

	i = 0;
	nstr = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!nstr)
		return (NULL);
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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	if (ft_strlen(s) <= start || len == 0 || ft_strlen(s) == 0)
		size = 0;
	else if (len <= ft_strlen(s) && start + len < ft_strlen(s))
		size = len;
	else
		size = ft_strlen(s) - start;
	subs = (char *) malloc(size + 1);
	if (subs == NULL)
		return (0);
	*subs = '\0';
	if (start < ft_strlen(s))
	{
		while (i < size)
		{
			subs[i] = s[start + i];
			i++;
		}
		subs[i] = '\0';
	}
	return (subs);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	i;

	i = 0;
	s = (void *) malloc(count * size);
	if (!s)
		return (0);
	while (i < (count * size))
	{
		((char *)s)[i] = 0;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ns;

	ns = s;
	i = 0;
	while (i < n)
	{
		ns[i] = '\0';
		i++;
	}
}
