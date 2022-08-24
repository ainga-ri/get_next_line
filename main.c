/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainga-ri <ainga-ri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:38:42 by ainga-ri          #+#    #+#             */
/*   Updated: 2022/08/17 12:43:26 by ainga-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "get_next_line_bonus.h"

void populate_expected(char *buffer, int n)
{
	int i = 0;
	while (i < n)
	{
		i += sprintf(buffer + i, "0123456789");
	}
	buffer[n] = 0;
}

int	main(void)
{
	//char *name = "lines_around_10.txt";
	int fd_4 = open("giant_line_nl.txt", O_RDONLY);
	char expected[20000 + 2];
	populate_expected(expected, 20000);
	expected[20000] = '\n';
	expected[20001] = 0;
	printf("%s", get_next_line(fd_4));
	printf("%s", get_next_line(fd_4));
	printf("%s", get_next_line(fd_4));
	printf("%s", get_next_line(fd_4));
	//printf("%s", expected);
	return (0);
	/*
	char	*name = "lines_around_10.txt";
	int fd = open(name, O_RDONLY);
	get_next_line(30);
	get_next_line(fd);
	close(fd);
	char	*temp;
	do
	{
		temp = get_next_line(fd);
		free(temp);
	} while (temp != NULL);
	get_next_line(fd);
	return (0);
	
	int		fd;
	char	*tmp;

	fd = open("algo.txt", O_RDONLY);
	tmp = get_next_line(fd);
	if (!tmp)
		return (0);
	while (tmp)
	{
		printf("%s", tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (0);
	*/
}
