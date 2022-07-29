/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:14:58 by msindreu          #+#    #+#             */
/*   Updated: 2022/07/28 10:15:41 by ainga-ri         ###   ########.fr       */
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
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	rest = ft_substr(str, i + 1, ft_strlen(str));
	if (!rest)
	{
		printf("Rest existe??\n");
		return (NULL);
	}
	return (rest);
}

char	*get_next_line(int fd)
{	
	char	*guardado;
	static char	*new_guardado = "";
	int		i;
	char	*line;
	
	i = 1;
	guardado = (char *)calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!guardado)
		return (NULL);
	while (!ft_strchr(guardado, '\n') && i > 0)
	{
		ft_bzero(guardado, BUFFER_SIZE);
		i = read(fd, guardado, BUFFER_SIZE);
		//printf("Valor de guardado: %s has size: %zu\n", guardado, ft_strlen(guardado));
		//printf("valor de i: %d\n", i);
		if (i == -1)
		{
			if (guardado)
				free(guardado);
			return (NULL);
		}
		else if (i > 0)
		{
			new_guardado = ft_strjoin(new_guardado, guardado);
			//free(new_guardado);
			//printf("Valor new_guardado:%s\n", new_guardado);
			if (!new_guardado)
				return (NULL);
		}
	}

	line = ft_get_line(new_guardado);
	//printf("Valor new_guardado before clean %s\n", new_guardado);
	//printf("Valor line:%s\n", line);
	if (ft_strlen(line) == 0)
		return (NULL);
	else
		new_guardado = ft_clean(new_guardado);
	//printf("Valor new_guardado %s\n", new_guardado);
	return (line);
}
