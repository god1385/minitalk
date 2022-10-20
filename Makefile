# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 21:12:04 by ctorrek           #+#    #+#              #
#    Updated: 2022/03/10 21:12:08 by ctorrek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: server client

server:
	cc -Wall -Wextra -Werror server.c others.c -o server

client:
	cc -Wall -Wextra -Werror client.c others.c -o client

clean:
	rm -f server client

fclean: clean

re: fclean all