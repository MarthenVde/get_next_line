/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:10:41 by marvan-d          #+#    #+#             */
/*   Updated: 2019/06/10 15:10:42 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char *line;
	int fd;

	fd = open("42", O_RDONLY);

	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
	}
	
	close(fd);
	return (0);
}
