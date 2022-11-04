/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtreviza <gtreviza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 06:52:35 by gtreviza          #+#    #+#             */
/*   Updated: 2022/11/04 01:12:04 by gtreviza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test_text.txt", O_RDONLY);
	line = "";
	/*line = get_next_line(fd);
	printf("line[%d]: %s\n", i, line);
	free(line);*/
	i = 1;
	while (line)
	{
		line = get_next_line(fd);
		printf("line[%d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
