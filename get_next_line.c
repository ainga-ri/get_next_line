/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainga-ri <ainga-ri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:38:42 by ainga-ri          #+#    #+#             */
/*   Updated: 2022/08/02 22:27:22 by ainga-ri         ###   ########.fr       */
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
		return (NULL);
	return (rest);
}

char	*ft_copy(char *new_guardado)
{
	char	*aux;
	int		i;

	i = 0;
	aux = (char *) malloc(sizeof(char) * ft_strlen(new_guardado));
	if (!aux)
		return (NULL);
	while (new_guardado[i])
	{
		aux[i] = new_guardado[i];
		i++;
	}
	return (aux);
}
char	*get_next_line(int fd)
{	
	char	*guardado;
	static char	*new_guardado = "";
	int		i;
	char	*line;
	char	*aux;

	i = 1;
	guardado = (char *)calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!guardado)
		return (NULL);
	while (!ft_strchr(guardado, '\n') && i > 0)
	{
		ft_bzero(guardado, BUFFER_SIZE);
		i = read(fd, guardado, BUFFER_SIZE);
		if (i == -1)
		{
			free(guardado);
			return (NULL);
		}
		else if (i > 0)
		{
			//printf("new guardado es %s\n", new_guardado);
			aux = ft_copy(new_guardado);
			//printf("aux es %s\n", aux);
			if (!aux)
			{
				free(guardado);
				return (NULL);
			}
			/* It should be another way */
			if (ft_strlen(new_guardado) > 0)
				free(new_guardado);
			new_guardado = ft_strjoin(aux, guardado);
			//printf("%s\n", aux);
			free(aux);
			if (!new_guardado)
			{
				free(guardado);
				return (NULL);
			}
		}
	}
	free(guardado);
	line = ft_get_line(new_guardado);	
	if (ft_strlen(line) > 0)
	{	
		//printf("static before leaving out: %s\n", aux);
		aux = ft_copy(new_guardado);
		//printf("valor de aux: %s\n", aux);
		free(new_guardado);
		new_guardado = ft_clean(aux);
		//printf("static before leaving out: %s\n", new_guardado);
		free(aux);
		return (line);
	}
	else
	{
		free(line);
		return (NULL);
	}
}
