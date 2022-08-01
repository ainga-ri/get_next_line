/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainga-ri <ainga-ri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:38:42 by ainga-ri          #+#    #+#             */
/*   Updated: 2022/08/01 21:46:42 by ainga-ri         ###   ########.fr       */
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

char	*ft_copy(char	*src)
{
	printf("new_g en ftcopy: %s\n", src);
	char	*dst;
	int	i;

	i = 0;
	dst = (char *) ft_calloc(ft_strlen(src),sizeof(char));
	if (!dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		printf("number is %d and char is %c\n", i, dst[i]);
		i++;
	}
	printf("new_g en ftcopy AFTER WHILE: %s\n", dst);
	return (dst);
}

void ft_freecopy(char *new_guardado, char **concat)
{
	printf("new_g en freecopy: %s\n", new_guardado);
	if (ft_strlen(*concat) > 0)
		free(*concat);
	*concat = ft_copy(new_guardado);
	printf("concat vale: %s\n", *concat);
	free(new_guardado);
	new_guardado = "";
}

char	*get_next_line(int fd)
{	
	char	*guardado;
	static char	*new_guardado = "";
	int		i;
	char	*line;
	char	*concat;
	
	i = 1;
	concat = "";
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
		// change of variable, make it a function
		if (ft_strlen(new_guardado) > 0)
			ft_freecopy(new_guardado, &concat);
		if (i > 0)
		{
			new_guardado = ft_strjoin(concat, guardado);
			//printf("valor de new guardado en while %s\n", new_guardado);	
			ft_freecopy(new_guardado, &concat);
			//printf("donde %s\n", concat);
			//printf("Valor new_guardado:%s\n", new_guardado);
			if (!new_guardado)
				return (NULL);
		}
	}
	free(guardado);
	if (ft_strlen(concat) > 0)
	{
		line = ft_get_line(concat);
		//printf("Valor new_guardado before clean %s\n", new_guardado);
		//printf("Valor line:%s\n", line);
		if (ft_strlen(line) == 0)
			return (NULL);
		else
			new_guardado = ft_clean(concat);
		printf("Valor new_guardado %s\n", new_guardado);
		free(concat);
		return (line);
	}
	else
		return (NULL);
}
