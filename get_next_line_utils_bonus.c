/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainga-ri <ainga-ri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:32:48 by ainga-ri          #+#    #+#             */
/*   Updated: 2022/08/16 16:12:20 by ainga-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *tic, char *bff, size_t i, size_t j)
{
	char		*nstr;

	if (!tic)
	{
		tic = ft_calloc(1, sizeof(char));
		if (!tic)
			return (NULL);
		nstr = ft_calloc(1 + ft_strlen(bff), sizeof(char));
	}
	else
		nstr = ft_calloc(ft_strlen(tic) + ft_strlen(bff) + 1, sizeof(char));
	if (!nstr)
		return (NULL);
	while (tic[i])
	{
		nstr[i] = tic[i];
		i++;
	}
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
	if (size > 0)
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
