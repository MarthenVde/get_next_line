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

char *read_to_str(int fd, char *str)
{
	char	buff[BUFF_SIZE + 1];
	ssize_t	b_read;
	char	*tmp;
	
	ft_memset(buff, 0 , BUFF_SIZE);
	if (read(fd, buff, 0) < 0 || fd < 0 || BUFF_SIZE < 1)
		return (NULL);
	if (!str)
		str = ft_strnew(1);
	while (!(ft_strchr(str, '\n')))
	{
		if ((b_read = read(fd, buff, BUFF_SIZE)) < 0)
			return (NULL);
		tmp = str;
		str = ft_strjoin(str, buff);
		free(tmp);
		if (str[0] == '\0' || b_read == 0)
			break ;
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char *str;
	char		*adr_lf;
	char		*tmp;

	*line = NULL;
	if (!(str = read_to_str(fd, str)) || !line)
		return (-1);
	adr_lf = ft_strchr(str, '\n');
	if (adr_lf != NULL)
	{
		if (!(*line = (ft_strndup(str, adr_lf - str))))
			return (-1);
		tmp = str;
		str = ft_strdup(adr_lf + 1);
		free(tmp);
		return (1);
	}
	else
	{
		while (str[0] != '\0')
		{
			*line = ft_strjoin(*line, str);
			str = read_to_str(fd, str);
		}
		free(str);
		return (0);
	}
}
/* 
while (read(1,buff,1))
{
	buff = strjoin(buff);	
	if ( buff[strlen(buff)] == '\n')
	{
		line = (strsplit(buff , '\n'));
		return ;
	}
}

	string, buffer.
	char *tmp = string;
	free(tmp);
	string = strjoin(string, buffer);
*/