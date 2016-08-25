#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suvitiel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/13 14:02:38 by suvitiel          #+#    #+#              #
#    Updated: 2016/08/25 01:49:19 by hanguelk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC		= gcc
OUT		= bsq
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I.
SRC = main.c mainalgo.c upgradebsq.c fonction_print.c ft_realloc.c ft_strlen.c ft_strcat.c ft_atoi.c ft_split_whitespaces.c strfunc.c
OBJ = $(SRC:.c=.o)

all:	compil

compil:
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ)

clean:	
	$(RM) $(OBJ)

debug:
	$(CC) $(CFLAGS) -fsanitize=address -o $(OUT) $(SRC)

norme:	
	norminette $(SRC) *.h

fclean:	clean
	$(RM) $(OUT)

re:	fclean all
