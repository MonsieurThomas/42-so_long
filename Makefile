# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 12:49:39 by rthomas           #+#    #+#              #
#    Updated: 2022/05/23 10:58:10 by rthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CFLAGS = -Wall -Wextra -Werror 

SOURCES =	sources/check_av.c \
			sources/main.c \
			sources/main_error.c \
			sources/xml_part.c \
			sources/xml_key_move.c \
			sources/xml_utils.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c 

OBJS = $(SOURCES:.c=.o)

all:		libft $(NAME)

$(NAME):	$(OBJS)
			gcc $(CFLAGS) $(OBJS) ./libft/libft.a -lmlx -framework OpenGL -framework Appkit -o $(NAME)

libft:
			make -C ./libft

clean:
			rm -f $(OBJS)
			make clean -C ./libft

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./libft

norme:
			norminette $(SRCS)

re:			fclean all

.PHONY:		re clean fclean all libft