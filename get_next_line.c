/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainga-ri <ainga-ri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:38:42 by ainga-ri          #+#    #+#             */
/*   Updated: 2022/08/03 19:23:41 by ainga-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	char	*line;
	int 	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
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
	while (str && str[i] && str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	rest = ft_substr(str, i + 1, ft_strlen(str));
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
	char	*aux;

	i = 1;
	buffer = (char *)calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && i > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		i = read(fd, buffer, BUFFER_SIZE);
		//printf("buffer is %s\n", buffer);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (i > 0)
		{
			//printf("concat es %s\n", concat);
			aux = strdup(concat);
			//printf("aux es %s\n", aux);
			if (!aux)
			{
				free(buffer);
				return (NULL);
			}
			if (concat[0] != '\0')
				free(concat);	
			//printf("It should be another way\n");
			concat = ft_strjoin(aux, buffer);
			//printf("concat before join es %s\n", concat);
			free(aux);
			if (!concat)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	free(buffer);
	line = ft_get_line(concat);
	//printf("line ready to deliver: %s\n", line);	
	if (ft_strlen(line) > 0)
	{	
		//printf("static before leaving out: %s\n", concat);
		aux = strdup(concat);
		//printf("valor de aux: ||| %s |||\n", aux);
		free(concat);
		concat = ft_clean(aux);
		//printf("concat cleaned: %s\n", concat);
		free(aux);
		return (line);
	}
	else
	{
		free(line);
		return (NULL);
	}
}
