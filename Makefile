# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 12:59:52 by cstripeb          #+#    #+#              #
#    Updated: 2020/02/16 20:16:37 by cstripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = gcc

SRC_DIR = ./src/
INC_DIR = ./include/
LIB_DIR = ./lib/
OBJ_DIR = ./objs/

F_SRCS = main.c
SRCS = $(addprefix $(SRC_DIR), $(F_SRCS))
OBJS = $(addprefix $(OBJ_DIR), $(F_SRCS:.c=.o))

INC = -I$(INC_DIR)
LNK = -lm

LIBFT_A = libft.a
LIBFT_PATH = $(addprefix $(LIB_DIR), libft/)
LIBFT_AP = $(addprefix $(LIBFT_PATH), $(LIBFT_A))
LIBFT_I = -I$(LIBFT_PATH)
LIBFT_L = -L$(LIBFT_PATH) -lft
INC += $(LIBFT_I)
LNK += $(LIBFT_L)

SDL_PATH = $(LIB_DIR)
SDL_INC = $(addprefix $(INC_DIR), SDL/)
INC += -I$(SDL_INC) -F./lib/
LNK += -F./lib/SDL2.framework/ -rpath ./lib/ -framework OpenGL -framework AppKit\
		-framework SDL2 

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT_AP) $(OBJS)
	$(CC) $(INC) $(LNK) $(OBJS) -o $(NAME)

$(OBJS): $(OBJ_DIR) $(INC_DIR)/wolf3d.h

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT_AP):
	@$(MAKE) -C $(LIBFT_PATH)


.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

.PHONY: re
re: fclean all
