/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtreviza <gtreviza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 06:52:35 by gtreviza          #+#    #+#             */
/*   Updated: 2022/10/27 06:53:25 by gtreviza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test_text.txt", O_RDONLY);
	line = "";
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