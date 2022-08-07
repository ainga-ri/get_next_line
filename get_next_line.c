/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainga-ri <ainga-ri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:38:42 by ainga-ri          #+#    #+#             */
/*   Updated: 2022/08/07 17:35:37 by ainga-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	char	*line;
	int 	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		line = ft_substr(str, 0, i + 1);
	else
		line = ft_substr(str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_clean(char *str)
{
	char *rest;
	int 	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	rest = ft_substr(str, i + 1, ft_strlen(str));
	free(str);
	if (!rest)
		return (NULL);
	return (rest);
}


char	*get_next_line(int fd)
{	
	char	*buffer;
	static char	*concat= "";
	int		i;
	char	*line;

	i = 1;
	buffer = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && i > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (i > 0)
		{
			concat = ft_strjoin(concat, buffer);
			if (!concat)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	free(buffer);
	line = ft_get_line(concat);
	if (ft_strlen(concat) > 0)
	{	
		concat = ft_clean(concat);
		return (line);
	}
	else
	{
		free(line);
		return (NULL);
	}
}
