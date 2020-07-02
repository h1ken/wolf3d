# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 12:59:52 by cstripeb          #+#    #+#              #
#    Updated: 2020/07/01 23:05:58 by hdean            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = gcc

UNAME_OS = $(shell uname -s)

SRC_DIR = ./src/
INC_DIR = ./include/
LIB_DIR = ./lib/
OBJ_DIR = ./objs/

F_SRCS = main.c initializations.c game_loop.c draw_functions.c \
		 keyboard_handle.c read_func.c exit_and_errors.c \
		 utils.c black_rock_shooter.c textures.c floor.c \
		 ft_validation.c
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
INC += -I$(SDL_INC)
ifeq ($(UNAME_OS),Darwin)
	LNK += -F./lib/ -rpath ./lib/ -framework OpenGL -framework AppKit \
		-framework SDL2 -framework SDL2_mixer
endif
ifeq ($(UNAME_OS),Linux)
	LNK += -lSDL2 -lSDL2_mixer
endif

FLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT_AP) $(OBJS)
#	$(CC) $(INC) $(LNK) $(OBJS) -o $(NAME)
	gcc -Wall -Wextra -Werror -g -o $(NAME) $(OBJS) $(INC) $(LNK)

$(OBJS): $(INC_DIR)/wolf3d.h $(INC_DIR)/wolf3d_defines.h | $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -Wall -Wextra -Werror -g $(INC) $(FLAGS) -c $< -o $@

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
