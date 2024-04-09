# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 22:16:25 by ramzerk           #+#    #+#              #
#    Updated: 2024/04/09 11:10:15 by ramzerk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	=	main.c \
				get_next_line.c \
				get_next_line_utils.c \
				parsing.c \
			#	parsing.c \
			#	checking.c \

CFLAGS 		=	-Wall -Wextra  #-Werror
NAME		=	so_long
NAME_MAC	=	so_long_MAC
LIBX		=	minilibx-linux/libmlx_Linux.a
LIBX_MAC	=	minilibx-linux/libmlx_Darwin.a
# LIBFT		=	libft/libft.a
SRC_DIR		=	src
OBJ_DIR		=	obj
INCLUDES	=	inc
SRC 		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

remac: fclean mac

re: fclean all

mac: $(NAME_MAC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -g3 -I$(INCLUDES) -c -o $@ $<

debug: $(OBJS) $(LIBX) $(LIBFT)
	cc $(CFLAGS) -g3 -gdwarf-4 -L/opt/homebrew/Cellar/libxext/1.3.6/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11 -Lminilibx-linux/ -lmlx $^ -o $(NAME)_debug

$(NAME_MAC): $(OBJS) $(LIBX_MAC) $(LIBFT)
	 cc $(CFLAGS) -L/opt/homebrew/Cellar/libxext/1.3.6/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11  -Lminilibx-linux/ -lmlx $^ -o $@

$(NAME): $(OBJS) $(LIBX) $(LIBFT)
	cc $(CFLAGS) -lXext -lX11 -Lminilibx-linux/ -lmlx $^ -o $@

$(LIBX_MAC):
	make -C minilibx-linux/

$(LIBX):
	make -C minilibx-linux/

# $(LIBFT):
# make -C libft/

$(OBJ_DIR):
	mkdir obj

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf *.o $(NAME) $(NAME)_debug $(NAME_MAC)
	make -C minilibx-linux/ clean
	make -C libft/ fclean

.PHONY: all clean fclean re