# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 22:18:21 by bait-sli          #+#    #+#              #
#    Updated: 2017/03/16 05:48:21 by bait-sli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
SRCS_NAME		=	atoi_base.c\
				check_file.c\
				get_color.c\
				tools.c\
				initial_expose.c\
				translation.c\
				define_color.c\
				get_data.c\
				draw_segments.c\
				rotation.c\
				calc_dot.c\
				event_data_parse.c\
				height_controler.c main.c\
				zoom.c
SRCS_PATH		=	srcs/
SRCS			=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME		=	$(SRCS_NAME:.c=.o)
OBJ_PATH		=	obj/
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAGS			=	-Wall -Werror -Wextra
INC			=	-I./includes/ -I./libft/
LIB			=	-L minilibx -lmlx -framework OpenGL -framework AppKit \
				-Llibft -lft\


.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(INC) $(LIB)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) $< -o $@ $(INC)

clean:
	make -C minilibx/ clean
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
