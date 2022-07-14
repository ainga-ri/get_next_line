/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:14:58 by msindreu          #+#    #+#             */
/*   Updated: 2022/07/14 14:05:45 by ainga-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	
	static char	*guardado;
	int		i;
	char	*line;
	
	line = "";
	guardado = (char *)malloc(BUFFER_SIZE *  sizeof(char));
	if (!guardado)
		return (NULL);
	i = read(fd, guardado, BUFFER_SIZE);
	if (i == -1)
	{
		if (guardado)
			free(guardado);
		return (NULL);
	}
	while (!ft_strchr(guardado, '\n'))
	{	
		line = ft_strjoin(line, guardado);
		if (!line)
			return (NULL);
		i = read(fd, guardado, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		printf("%s\n", line);

	}

	printf("Mida del retorn del read: %d\n", i);

	return (line);
}
