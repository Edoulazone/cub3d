# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 10:45:35 by jveirman          #+#    #+#              #
#    Updated: 2025/01/30 12:27:49 by jveirman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

INCPATH		=	./
MLX_PATH	=	minilibx_linux/
SRCS_PATH	=	sources/
LIBFT		=	./libft/libft.a

INIT		=	init/
HOOK		=	hook/
GAME		=	game/
KEYS		=	keys/
DRAW		=	drawing_tools/
PARS		=	parsing/
GNL			=	gnl/
ANIM		=	animation/
TOOL		=	tools/

INCLUDES	=	$(MLX_PATH)mlx.h \
				cub3D.h

SRC			=	main.c \
				$(INIT)init_project.c $(INIT)init_game_struct.c $(INIT)init_window_struct.c $(INIT)init_map_struct.c $(INIT)init_player_struct.c $(INIT)init_keys_struct.c $(INIT)init_hooks_logics.c $(INIT)init_xpm_images.c $(INIT)init_animation_struct.c $(INIT)init_pars_struct.c $(INIT)init_animation_minimap_struct.c $(INIT)init_animation_hand_struct.c \
				$(HOOK)expose_hook.c $(HOOK)key_hook.c $(HOOK)mouse_hook.c \
				$(KEYS)handle_keys.c $(KEYS)key_tab.c $(KEYS)key_space.c $(KEYS)key_m.c $(KEYS)key_left.c $(KEYS)key_right.c $(KEYS)key_w.c $(KEYS)key_s.c $(KEYS)key_a.c $(KEYS)key_d.c $(KEYS)key_e.c $(KEYS)key_esc.c $(KEYS)key_enter.c \
				$(GAME)update.c $(GAME)layout_home_screen.c $(GAME)layout_game_screen.c $(GAME)layout_map_screen.c $(GAME)raycast.c $(GAME)raycast_utils.c $(GAME)minimap.c \
				$(DRAW)draw_rectangle.c \
				$(ANIM)animation_tools.c $(ANIM)animation_utils.c $(ANIM)animation_player_hand.c \
				$(TOOL)close.c $(TOOL)fps.c $(TOOL)image_helper.c $(TOOL)colors.c $(TOOL)is_wall.c $(TOOL)optimization.c \
				$(PARS)parser.c $(PARS)pars_colours.c $(PARS)pars_texture.c $(PARS)free_map_and_colour.c $(PARS)pars_utils2.c \
				$(GNL)get_next_line.c $(GNL)get_next_line_utils.c

ifdef BONUS
	SRC += $(GAME)display_bonus.c $(PARS)pars_utils_bonus.c $(PARS)pars_map_bonus.c $(PARS)pars_errors_bonus.c
else
	SRC += $(GAME)display.c $(PARS)pars_map.c $(PARS)pars_utils.c $(PARS)pars_errors.c
endif

OBJ = $(SRC:.c=.o)

CC			=	clang
INCS		=	-I./
LIBS		=	minilibx_linux/libmlx_Linux.a \
				-Lminilibx_linux -lmlx -lXext -lX11 -lm

# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g $(INCS)
# LDFLAGS = -fsanitize=address -g $(LIBS)
CFLAGS = -Wall -Wextra -Werror $(INCS) 
LDFLAGS = $(LIBS)

all: $(NAME)

$(NAME): $(OBJ)
	make --no-print-directory all -C libft
	$(CC) $(OBJ) $(LIBFT) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

bonus:
	$(MAKE) BONUS=1 all

bonus_clean:
	$(MAKE) BONUS=1 clean

bonus_fclean:
	$(MAKE) BONUS=1 fclean

bonus_re:
	$(MAKE) BONUS=1 re

clean:
	make --no-print-directory clean -C libft
	rm -f $(OBJ)

fclean:
	make --no-print-directory fclean -C libft/
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(INIT)
	norminette $(HOOK)
	norminette $(GAME)
	norminette $(KEYS)
	norminette $(DRAW)
	norminette $(PARS)
	norminette $(GNL)
	norminette $(ANIM)
	norminette $(TOOL)
	norminette $(NAME).h
	norminette main.c
	
.PHONY: all clean fclean re bonus bonus_clean bonus_fclean bonus_re norm bonus_norm
