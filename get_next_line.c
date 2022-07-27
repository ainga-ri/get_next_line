/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:14:58 by msindreu          #+#    #+#             */
/*   Updated: 2022/07/19 17:45:54 by ainga-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//hola rodolfo
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
	if (ft_strchr(str, '\0'))
		return (NULL);
	while (str[i] != '\n') // || str[i] != '\0')
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
		i = read(fd, guardado, BUFFER_SIZE);
		printf("valor i: %d\n", i);
		if (i == -1)
		{
			if (guardado)
				free(guardado);
			return (NULL);
		}
		else if (i == 1)
		{		
			printf("valor guardado: %s\n", guardado);
			new_guardado = ft_strjoin(new_guardado, guardado);
			printf("valor NEWguardado: %s\n", new_guardado);
			if (!new_guardado)
				return (NULL);
		}
	}
	//compiamos linea en line
	printf("-------- Valor de la line sin limpiar: %s ------\n", new_guardado);
	line = ft_get_line(new_guardado);
	printf("Este es el valor de line: %s\n", line);
	//borramos line en new_guardado
	new_guardado = ft_clean(new_guardado);
	printf("Resto de la line, value of new_guardado %s\n", new_guardado);
	//printf("Mida del retorn del read: %d\n", i);
	return (line);
}
