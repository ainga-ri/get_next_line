/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainga-ri <ainga-ri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:38:42 by ainga-ri          #+#    #+#             */
/*   Updated: 2022/08/17 12:43:26 by ainga-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str || *str == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = ft_substr(str, 0, i + 1);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_clean(char *str)
{
	char	*rest;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	rest = ft_substr(str, i + 1, ft_strlen(str));
	free(str);
	if (!rest)
		return (NULL);
	return (rest);
}

static _Bool	ft_concatenation(int fd, int *i, char *buffer, char **concat)
{
	size_t	first_join;
	size_t	second_join;
	
	*i = read(fd, buffer, BUFFER_SIZE);
	if (*i == -1)
	{
		if (*concat && **concat)
		{
			//**concat = 0;
			//printf("\n%s\n", *concat);
			//printf("pointer %p\n", *concat);
			free(*concat);
		}
		free(buffer);
		return (0);
	}
	else if (*i > 0)
	{
		buffer[*i] = '\0';
		first_join = 0;
		second_join = 0;
		*concat = ft_strjoin(*concat, buffer, first_join, second_join);
		if (!*concat)
		{	
			free(buffer);
			return (0);
		}
	}
	return (1);
}

char	*ft_finish_and_clean(char *line, char **concat)
{
	if (line)
	{	
		*concat = ft_clean(*concat);
		return (line);
	}
	else
	{
		if (*concat)
		{
			free(*concat);
			*concat = NULL;
		}	
		return (NULL);
	}
}

char	*get_next_line(int fd)
{	
	char		*buffer;
	static char	*concat[OPEN_MAX];
	int			i;
	char		*line;
	
	i = 1;
	buffer = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
	{
		if (concat[fd])
			free(concat[fd]);
		return (NULL);
	}
	while (!ft_strchr(buffer, '\n') && i > 0)
	{
		if (!ft_concatenation(fd, &i, buffer, &concat[fd]))
			return (NULL);
	}
	free(buffer);
	line = ft_get_line(concat[fd]);
	return (ft_finish_and_clean(line, &concat[fd]));
}
