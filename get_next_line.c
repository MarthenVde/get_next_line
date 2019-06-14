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


char	*readit(const int fd, char *str)
	{
		char	buf[BUFF_SIZE + 1];
		int		i2;

		if (fd < 0 || read(fd, buf, 0) < 0 || BUFF_SIZE < 1)
			return (NULL);
		if (str == NULL)
			str = ft_strnew(1);
		while (!(ft_strchr(str, '\n')))
		{
			if ((i2 = read(fd, buf, BUFF_SIZE)) < 0)
				return (NULL);
			buf[i2] = '\0';
			str = ft_strnjoin(str, buf, 1);
			if (str[0] == '\0' || i2 == 0)
				break ;
		}
		return (str);
	}

	int		get_next_line(const int fd, char **line)
	{
		static char *str;
		char		*pos;
		int			len;

		if (!(str = readit(fd, str)) || !line)
			return (-1);
		if ((pos = ft_strchr(str, '\n')) != NULL)
		{
			len = pos - str;
			if (!(*line = ft_strndup(str, len)))
				return (-1);
			str = ft_strdup(pos + 1);
			return (1);
		}
		else
		{
			if (!(*line = ft_strdup(str)))
				return (-1);
			free(str);
			str = NULL;
			if (*line[0] == '\0')
				return (0);
			return (1);
		}
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



//////////////

while (arr[i][0] != NULL)
{
	while(arr[i[j]] !=  '/0')
	{
		write(1, &arr[i][j],1 );
		j++;
	}
	j =0;
	i++;
}

file = [a, b, \n, c, d]
str = [a, b, '\0']
*/