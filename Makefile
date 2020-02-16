# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 12:59:52 by cstripeb          #+#    #+#              #
#    Updated: 2020/02/16 14:52:18 by cstripeb         ###   ########.fr        #
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
LIBFT_L = -l$(LIBFT_PATH) -lft
INC += $(LIBFT_I)
LNK += $(LIBFT_L)

LGLFW_A = libglfw3.a
LGLFW_PATH = $(addprefix $(LIB_DIR), glfw/)
LGLFW_PATH_A = $(addprefix $(LGLFW_PATH), src/)
LGLFW_AP = $(addprefix $(LGLFW_PATH_A), $(LGLFW_A))
LGLFW_I = -I$(addprefix $(LGLFW_PATH), include/)
LGLFW_L = -L$(LGLFW_PATH_A) -glfw3

.PHONY: all
all: $(NAME)

$(NAME): $(LGLFW_AP) $(LIBFT_AP) $(OBJS)
	$(CC) $(INC) $(OBJS) -o $(NAME)

$(OBJS): $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -MD $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT_AP):
	@$(MAKE) -C $(LIBFT_PATH)

$(LGLFW_AP):
	@$(MAKE) -C $(LGLFW_PATH)

.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(LGLFW_PATH) clean
	@rm -f $(NAME)

.PHONY: re
re: fclean all
