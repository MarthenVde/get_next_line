# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 15:05:32 by marvan-d          #+#    #+#              #
#    Updated: 2019/06/10 15:13:02 by marvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = line

FILES = get_next_line.c libft/libft.a main.c

all: $(FILES)
	gcc -Wall -Werror -Wextra $(FILES) -o $(NAME)
clean:
	rm -f $(NAME)
