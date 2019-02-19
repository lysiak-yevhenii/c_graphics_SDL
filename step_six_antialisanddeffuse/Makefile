# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/03 19:58:25 by ylisyak           #+#    #+#              #
#    Updated: 2019/02/18 23:57:07 by ylisyak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	rtv
FLAGS		=	-Wall -Werror -Wextra
INC_P		=	./inlcude/
SRC_P		=	./src/
OBJ_P		=	./tmp/

LIB_P		=	./libft/
F_LIB		=	$(addprefix $(LIB_P), libft.a)
F_INC		=	-I ./libft/
F_LNK		=	-L ./libft -l ft

SDL_P		=	./sdl/sdl2/2.0.8/lib/
SDL_INC		=	-I ./sdl/sdl2/2.0.8/include/SDL2/
SDL_LNK		=	-L ./sdl/sdl2/2.0.8/lib/ -l SDL2

SDL_IMGP	=	./sdl/sdl2_image/2.0.3/lib/
SDL_IMG_INC	=	-I ./sdl/sdl2_image/2.0.3/include/SDL2/
SDL_IMG_LNK	=	-L ./sdl/sdl2_image/2.0.3/lib/ -l SDL2_image

SDL_MIXP	=	./sdl/sdl2_mixer/2.0.2_3/lib/
SDL_MIX_INC	=	-I ./sdl/sdl2_mixer/2.0.2_3/include/SDL2/
SDL_MIX_LNK	=	-L ./sdl/sdl2_mixer/2.0.2_3/lib/ -l SDL2_mixer

SDL_TTFP	=	./sdl/sdl2_ttf/2.0.14/lib/
SDL_TTF_INC	=	-I ./sdl/sdl2_ttf/2.0.14/include/SDL2/
SDL_TTF_LNK	=	-L ./sdl/sdl2_ttf/2.0.14/lib/ -l SDL2_ttf

SRC		=	main.c \
			ft_drawing_bpx.c \
			ft_parser.c \
			ft_core.c \
			ft_init_sdl.c \
			ft_error.c \
			ft_vector_lib.c \
			ft_hitequations.c \
			ft_controller.c \
			ft_thread_start.c 

OBJ_PS	=	$(addprefix $(OBJ_P), $(SRC:.c=.o))

all:	tmp $(NAME)

tmp:	libft
	@mkdir -p $(OBJ_P)

$(OBJ_P)%.o:$(SRC_P)%.c
	@gcc $(F_INC) $(SDL_INC) $(SDL_IMG_INC) $(SDL_MIX_INC) $(SDL_TTF_INC) -I $(INC_P) -o $@ -c $<

libft: 
	@make -C $(LIB_P)
	@printf ' 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 \n'
	@printf ' 🃟 Libruary has been compiled and ready to use 🃟 \n'
	@printf ' 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 \n'	

$(NAME): $(OBJ_PS)
	@gcc $(OBJ_PS) $(F_LNK) $(SDL_LNK) $(SDL_IMG_LNK) $(SDL_MIX_LNK) $(SDL_TTF_LNK) -o $(NAME)

clean:
	@rm -Rf $(OBJ_P)
	@make -C $(LIB_P) clean	
	@printf ' 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 \n'	
	@printf ' 🃟        \033[91mObject files have been deleted      \033[0m 🃟 \n'
	@printf ' 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 🃟 \n'	

fclean: clean
	@rm -fr .DS*
	@rm -rf $(NAME)
	@make -C $(LIB_P) fclean
	@printf '                   \033[91mAll is clear!\033[0m \n'

re:	fclean all
.PHONY: libft sdl 
