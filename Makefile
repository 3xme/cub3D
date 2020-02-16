# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiari <abiari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 14:09:59 by abiari            #+#    #+#              #
#    Updated: 2020/02/16 13:33:47 by abiari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = ft_split.c xexit.c xmalloc.c tools.c get_next_line_utils.c\
		get_next_line.c mlx_img_mod.c read_input.c ft_strtrim.c ft_isdigit.c\
		ft_atoi.c cub3d.c rgbtoint.c ft_cast.c ft_save.c ft_strcmp.c\
		ft_cast2.c ft_sprite.c ft_collision.c ft_events.c ft_3drendering.c\
		ft_dist.c ft_pos_and_move.c ft_reset_img.c check_cub.c input_utils1.c\
		input_utils2.c input_utils3.c input_utils4.c input_utils5.c\

OBJ = cub3D
 
all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -I /usr/local/include $(SRC) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(OBJ)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re