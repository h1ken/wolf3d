# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 14:51:13 by cstripeb          #+#    #+#              #
#    Updated: 2019/08/20 10:02:01 by cstripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

flags = -Wall -Wextra -Werror

NAME = libft.a

incl = .

srcs = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	   ft_strcmp.c ft_strlen.c ft_strncmp.c ft_strstr.c ft_tolower.c \
	   ft_toupper.c ft_strnstr.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
	   ft_strchr.c ft_strrchr.c ft_memset.c ft_bzero.c ft_memcpy.c \
	   ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strcat.c \
	   ft_strncat.c ft_strlcat.c ft_atoi.c ft_sqrt.c \
	   ft_putchar.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
	   ft_strclr.c ft_striter.c ft_striteri.c  ft_strmap.c ft_strmapi.c \
	   ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	   ft_putstr.c ft_strsplit.c ft_itoa.c ft_putendl.c ft_putnbr.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	   ft_lstmap.c ft_swap.c\
	   ft_isspace.c ft_lstaddlast.c ft_treenew.c ft_treeadd.c \
	   ft_treedelone.c ft_treedel.c ft_treeinfix.c ft_treeprefix.c \
	   ft_treepostfix.c ft_lstsearch.c ft_lstsize.c ft_arraysize.c\
	   get_next_line.c

obj = $(srcs:.c=.o)

all: $(NAME)

$(NAME): $(obj)
	@ar rc $(NAME) $(obj)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(flags) -I $(incl) -c $<

clean:
	@rm -f $(obj)

fclean: clean
	@rm -f $(NAME)

re: fclean all
