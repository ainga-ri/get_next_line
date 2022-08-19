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

#include "get_next_line.h"

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

static _Bool ft_concatenation(int fd, int *i,  char *buffer, char **concat)
{
	while (!ft_strchr(buffer, '\n') && i > 0)
	{
		*i = read(fd, buffer, BUFFER_SIZE);
		if (*i == -1)
		{
		if (*concat)
				free(*concat);
			free(buffer);
			return (0);
		}
		else if (i > 0)
		{
			buffer[*i] = '\0';
			*concat = ft_strjoin(*concat, buffer);
			if (!*concat)
			{
				if (*concat)
					free(*concat);
				free(buffer);
				return (0);
			}
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
		free(line);
		if (*concat)
			free(*concat);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{	
	char		*buffer;
	static char	*concat;
	int			i;
	char		*line;

	i = 1;
	buffer = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
	{
		if (concat)
			free(concat);
		return (NULL);
	}
	if (!ft_concatenation(fd, &i, buffer, &concat))
		return (NULL);
	/*
	while (!ft_strchr(buffer, '\n') && i > 0)
	{
		if (!ft_concatenation(fd, &i, buffer, &concat))
			return (NULL);
		
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			if (concat)
				free(concat);
			free(buffer);
			return (NULL);
		}
		else if (i > 0)
		{
			buffer[i] = '\0';
			concat = ft_strjoin(concat, buffer);
			if (!concat)
			{
				if (concat)
					free(concat);
				free(buffer);
				return (NULL);
			}
		}
		
	}*/
	free(buffer);
	line = ft_get_line(concat);
	return (ft_finish_and_clean(line, &concat));
}
