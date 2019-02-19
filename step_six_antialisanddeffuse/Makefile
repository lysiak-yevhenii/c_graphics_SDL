# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/03 19:58:25 by ylisyak           #+#    #+#              #
#    Updated: 2019/02/19 22:21:04 by ylisyak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv

CC =	gcc
FG =	-lmlx -framework OpenGL -framework AppKit
PTHL =	-L /usr/local/lib 
PTHLS = -L ./libft/ -lft
PTHH =	-I /usr/local/include

SRC_PTH = ./src/
OBJ_PTH = ./obj/

SRC		=	main.c \
			ft_drawing_bpx.c \
			ft_parser.c \
			ft_core.c \
			ft_error.c \
			ft_vector_lib.c \
			ft_hitequations.c \
			ft_controller.c \
			ft_thread_start.c \
		    ft_init_mlx.c \
			ft_interface_support.c	

OBJ_P = $(addprefix $(OBJ_PTH), $(SRC:.c=.o))
SCR_P = $(addprefix $(SRC_PTH), $(SRC))

all: $(NAME)

mlib:
	make -C ./libft
	mkdir -p $(OBJ_PTH)

$(NAME): mlib $(OBJ_P)
	$(CC) $(PTHH) $(OBJ_P) $(PTHL) $(FG) -o $(NAME) $(PTHLS) -I ./

$(OBJ_PTH)%.o:$(SRC_PTH)%.c
	gcc -Wall -Werror -Wextra -c -o $@ $< -I libft

clean:
	rm -f *.o
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all



.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re
