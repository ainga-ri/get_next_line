/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainga-ri <ainga-ri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:38:42 by ainga-ri          #+#    #+#             */
/*   Updated: 2022/08/07 18:31:20 by ainga-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	char	*line;
	int 	i;

	i = 0;
	if (*str == '\0')
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
		//ft_bzero(buffer, BUFFER_SIZE);
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
	if (line)
	{	
		concat = ft_clean(concat);
		return (line);
	}
	else
	{
		// Concat se va freeando dentro de ft_clean, pero cuando acaba, no entra en ft_clean y se ha quedado 1 en el aire, entonces entra en el else, y pam, hay que freearlo
		// Hay que ver que carajo esta haciendo con un fkin char
		free(line);
		return (NULL);
	}
}
