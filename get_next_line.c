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

/*
int	b_copy(char buff[], char **line)
{
	int ret;
	int i;

	i = -1;
	ret = 1;
	while (buff[++i] != '\0')
	{
		if (buff[i] == '\n')
			ret = 0;
		**line = buff[i];
		line++;
	}
	return (ret);
}
*/
int	get_next_line(const int fd, char **line)
{
	static	char	buff[BUFF_SIZE + 1];
	int				nbytes;

	*line = ft_strnew(999);
	ft_memset((void *) buff, 0, (size_t) BUFF_SIZE);
	if (fd == -1 || !(*line))
		return (-1);
	while ((nbytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbytes] = '\0';
		//ft_putstr(buff);
		ft_strcpy(*line, buff);
		ft_putstr(*line);
		ft_putchar('\n');
	}
	return (1);
}
