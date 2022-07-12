/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:14:58 by msindreu          #+#    #+#             */
/*   Updated: 2022/07/12 17:44:05 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	*guardado;
	size_t		i;

	guardado = calloc(10, sizeof(char));

	i = read(fd, guardado, BUFFER_SIZE);
	if (i == -1)
	{
		return (NULL);
	}
	printf("%zu\n", i);
	return (guardado);
}
