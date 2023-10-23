# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tas <tas@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 20:17:27 by tas               #+#    #+#              #
#    Updated: 2023/10/23 08:55:16 by tas              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        	=   cub3d

CC          	=   gcc

SRC_DIR			= 	$(shell find sources -type d)
INC_DIR			= 	$(shell find includes -type d) \
					$(shell find lib/mlx -type d) \
					$(shell find lib/libft -type d)
LIB_DIR			=	lib/libft lib/mlx
OBJ_DIR			=	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

LINUXFLAG	=	-lm -lX11 -lXext

# library -----------------------------------------------------------

LIB			=	ft mlx_Linux

SRC			= 	main.c\
				raycasting.c\
				3d.c\
				recup_map.c\
				keypress.c\
				tools.c\
				free.c\
				free2.c\
				init.c\
				init2.c\
				check_nswe.c\
				verif_line_by_line.c\
				verif_map.c\
				check_fc.c\
				ft_for_norme.c\
				verif_textures.c\
				parse_elements.c\
				get_next_line_bis.c\
				get_next_line_bis_utils.c\
				

				
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags -------------------------------------------------

CFLAGS		=	-Wall -Wextra -Werror -g

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib)) \
				$(LINUXFLAG)


# main part ---------------------------------------------------------

all:
	@make -s $(NAME)

install:
	@$(foreach dir, $(LIB_DIR), make -s -C $(dir) > /dev/null 2>&1;)

re-install:
	@$(foreach dir, $(LIB_DIR), make -s -C $(dir) > /dev/null 2>&1 re;)

fclean-install:
	@$(foreach dir, $(LIB_DIR), make -s -C $(dir) > /dev/null 2>&1 fclean;)

$(NAME): install $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

re:	fclean all

clean:
	@$(foreach file, $(OBJ), rm -rf $(file))

fclean:	clean
	@rm -f $(NAME)

.PHONY: all install re-install re clean flcean
