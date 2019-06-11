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
	//char *line;
	int afd;
	int bfd;
	int cfd;

	afd = open("42", O_RDONLY);
	bfd = open("21", O_WRONLY);
	cfd = open("84", O_WRONLY);
	printf("%d\t\t\t%p -----> file 42\n", afd, fdopen(afd, "r"));
	printf("%d\t\t\t%p -----> file 21\n", bfd, fdopen(bfd, "w"));
	printf("%d\t\t\t%p -----> file 84\n", cfd, fdopen(cfd, "w"));
	return (0);
}
