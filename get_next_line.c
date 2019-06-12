/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 10:49:45 by marvan-d          #+#    #+#             */
/*   Updated: 2019/06/10 10:49:47 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_width(int fd)
{
	char	buff[32];
	int		b_read;

	ft_memset( (void *) buff, 0, (size_t) 32);
	b_read = read(fd, (void *) buff, (size_t) 32);
	if (b_read == -1 || b_read == 0)
		return (-1);
	buff[31] = '\0';
	return (ft_atoi(buff));
}

int	get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		nbytes;

	if (fd == -1 || !(*line))
		return (-1);
	if ((nbytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbytes] = '\0';
	}
	*line = ft_strcpy(*line, buff);
	ft_putnbr(line_width(fd));
	return (1);
}
