/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:34:09 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/31 18:35:55 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_file(int fd, char *buf_line)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == READ_ERROR)
			return (NULL);
		buffer[bytes_read] = '\0';
		buf_line = ft_strjoin_free(buf_line, buffer);
	}
	return (buf_line);
}

static char	*return_line(char *buf_line)
{
	char	*ret;
	char	*nl_position;
	size_t	len;

	ret = NULL;
	if (!*buf_line)
		return (NULL);
	nl_position = ft_strchr(buf_line, '\n');
	if (!nl_position)
		ret = ft_strjoin_free(ret, buf_line);
	else
	{
		len = nl_position - buf_line + 1;
		ret = ft_substr(buf_line, 0, len);
	}
	return (ret);
}

static char	*save_line(char *buf_line)
{
	char	*line;
	char	*nl_position;

	line = NULL;
	nl_position = ft_strchr(buf_line, '\n');
	if (nl_position)
		line = ft_strdup(nl_position + 1);
	free(buf_line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf_line;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	buf_line = read_file(fd, buf_line);
	if (!buf_line)
		return (NULL);
	line = return_line(buf_line);
	buf_line = save_line(buf_line);
	return (line);
}
