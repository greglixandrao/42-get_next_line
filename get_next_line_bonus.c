/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtreviza <gtreviza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 03:07:36 by gtreviza          #+#    #+#             */
/*   Updated: 2022/11/27 23:18:09 by gtreviza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read(int int_fd, char *line)
{
	char	*buffer;
	int		nbr_bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!line)
	{
		line = malloc(1);
		line[0] = '\0';
	}
	nbr_bytes_read = 1;
	while (nbr_bytes_read != 0)
	{
		nbr_bytes_read = read(int_fd, buffer, BUFFER_SIZE);
		if (nbr_bytes_read == -1)
			return (0);
		buffer[nbr_bytes_read] = '\0';
		line = ft_strjoin_free(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}

static char	*ft_return_line(char *line)
{
	int		i;
	char	*print_line;

	i = 0;
	print_line = "";
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	print_line = malloc((i + 2) * 1);
	if (!print_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		print_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		print_line[i] = line[i];
		i++;
	}
	print_line[i] = '\0';
	return (print_line);
}

static char	*rested_line(char *line)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if ((line[i] == '\n' && line[i + 1] == '\0') || !line[i])
	{
		free(line);
		return (NULL);
	}
	rest = malloc((ft_strlen(line) - i + 1) * 1);
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		rest[j++] = line[i++];
	rest[j] = '\0';
	free(line);
	return (rest);
}

char *get_next_line(int fd)
{
	static char	*line[1024];
	char		*print_line;

	print_line = "";
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line[fd] = ft_read(fd, line[fd]);
	if (!*line[fd])
	{
		free(line[fd]);
		line[fd] = NULL;
		return (line[fd]);
	}
	print_line = ft_return_line(line[fd]);
	line[fd] = rested_line(line[fd]);
	return (print_line);
}
