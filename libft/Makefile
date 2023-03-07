# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 12:49:39 by rthomas           #+#    #+#              #
#    Updated: 2022/04/06 18:07:58 by rthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = \
ft_atoi.c ft_isascii.c ft_memcpy.c ft_strlcat.c ft_strrchr.c \
ft_bzero.c ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_tolower.c \
ft_calloc.c ft_isprint.c ft_memset.c ft_strlen.c ft_toupper.c \
ft_isalnum.c ft_memchr.c ft_strchr.c ft_strncmp.c \
ft_isalpha.c ft_memcmp.c ft_strdup.c ft_strnstr.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c \

BSOURCES = \
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstnew.c \
ft_lstsize.c ft_lstmap.c \

OBJECTS = ${SOURCES:.c=.o}
BOBJECTS = ${BSOURCES:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJECTS}
	$(AR) -r $@ $?

bonus : ${OBJECTS} ${BOBJECTS}
	$(AR) -r ${NAME} $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f ${OBJECTS} ${BOBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re