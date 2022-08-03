#include "get_next_line.h"

char	*ft_strjoin(char *tic, char *bff)
{
	char		*nstr;
	size_t		i;
	size_t		j;

	i = 0;
	if (*tic == '\0')
	{
		tic = (char *) ft_calloc(1, sizeof(char));
		if (!tic)
			return (NULL);
		nstr = (char *) ft_calloc(1 + ft_strlen(bff), sizeof(char));
	}
	else
		nstr = (char *) ft_calloc(ft_strlen(tic) + ft_strlen(bff) + 1, sizeof(char));
	if (!nstr)
		return (NULL);
	while (tic[i])
	{
		nstr[i] = tic[i];
		i++;
	}
	j = 0;
	while (bff[j])
	{
		nstr[i + j] = bff[j];
		j++;
	}
	free(tic);
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
		return (NULL);
	while (i < (count * size))
	{
		((char *)s)[i] = '\0';
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
