/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:14:58 by msindreu          #+#    #+#             */
/*   Updated: 2022/07/14 18:11:33 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	char	*line;
	int 	i;

	i = 0;
	while (fstr[i] == '\n')
	{
		i++;
	}
	line = ft_substr(str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	
	char	*guardado;
	static char	*new_guardado;
	int		i;
	char	*line;
	
	line = "";
	i = 1;
	guardado = (char *)calloc((BUFFER_SIZE + 1) *  sizeof(char));
	if (!guardado)
		return (NULL);
	while (!ft_strchr(guardado, '\n') && i > 0)
	{
		i = read(fd, guardado, BUFFER_SIZE);
		if (i == -1)
		{
			if (guardado)
				free(guardado);
			return (NULL);
		}
		new_guardado = ft_strjoin(new_guardado, guardado);
		if (!new_guardado)
			return (NULL);
	}
	//compiamos linea en line
	line = ft_get_line(new_guardado);
	//borramos line en new_guardado
	new_guardado = ft_clean(new_guardado);
	printf("Mida del retorn del read: %d\n", i);
	return (line);
}
