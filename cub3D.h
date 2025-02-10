/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:28 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 11:35:50 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
// for mlx functions (handle window, image, etc)
# include "minilibx_linux/mlx.h"	
// for keycode Macro (XK_SPACE, XK_Escape, etc)
# include <X11/Xutil.h>				
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdint.h>
# include <math.h>

# define TITLE "(: Edou ------ Cub3D ------ Johnny :)"
# define WIN_W 1200
# define WIN_H 600
# define FPS 42

# define C_BLACK		0x1A1A1A
# define C_DARK_RED	0x311F1F
# define C_DEEP_RED	0x8C2B36
# define C_RED		0xF53F39
# define C_DARK_GREY	0x2e2e2e
# define C_GREY		0xABABAB
# define C_TRANSPARENT	0xFF000000

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define BOLD "\033[1m"

# define NS false
# define EW true

# define ST 0.05 // step for the player to move
# define RANGE 0.04 // range to detect the door

// Map Macro
# define PADDING 10
# define MINI_SIZE 20
# define FOC_SIZE 20
# define MINI_H 150
# define MINI_W 150
# define MAX_M_W 1008
# define MAX_M_H 402
# define ID_FLOOR 0
# define ID_WALL 1
# define ID_HIDDEN 2
# define ID_DOOR 3
# define ID_METAL 4
# define ID_METAL2 5
# define ID_GRIDS 6
# define ID_SCAFFOLD 7
# define ID_PIPE 8
# define ID_OUT_OF_BOUND -1

// Animation hand/player Macro
# define H_DELAY 5
# define H_FRAMES 34
# define H_W 420
# define H_H 236
# define H_X 390
# define H_Y 364

enum e_game_state
{
	home_screen,
	game_screen,
	game_over,
	menu,
	map_focus,
	inventory,
};

enum e_xpm_images
{
	xpm_home_screen,
	xpm_game_over,
	xpm_menu,
	xpm_map_focus,
	xpm_inventory,
	xpm_north,
	xpm_south,
	xpm_east,
	xpm_west,
	xpm_wall,
	xpm_door,
	xpm_grid,
	xpm_pipe,
	xpm_scaffold,
	xpm_metal,
	xpm_metal2,
	XPM_NULL,
};

enum e_wall_or
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
};

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
	bool	e;
	bool	m;
	bool	tab;
	bool	esc;
	bool	enter;
	bool	space;
	bool	m_pressed;
	bool	tab_pressed;
	bool	enter_pressed;
	bool	space_pressed;
	bool	mouse_left;
	bool	mouse_right;
	bool	mouse_1;
	bool	mouse_2;
	bool	mouse_3;
}		t_keys;

typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
	struct s_win	*win;
}		t_img;

typedef struct s_win
{
	char	*title;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	scr;
	int		width;
	int		height;
}		t_win;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	speed;
	double	rot_speed;
	double	plane_x;
	double	plane_y;
}		t_player;

typedef struct s_marker
{
	t_img	frame;
	float	min_angle;
}	t_marker;

typedef struct s_lst
{
	void			*content;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

typedef struct s_sprite
{
	void	*anim;
	t_lst	*cur_node;
	char	*name;
	char	*file_path;
	t_img	sprite_img;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_animation
{
	void	*current_frame;
	void	*sequence;
	t_img	sprite_img;
	int		delay;
	int		tmp_delay;
	int		current_frame_num;
	int		total_frame;
	int		w;
	int		h;
	int		x;
	int		y;
}	t_animation;

typedef struct s_map
{
	int			**map_grid;
	char		**temp_grid;
	int			w;
	int			h;
	t_sprite	pos_sprite;
	bool		dynamic_map;
	int			start_x;
	int			start_y;
	int			f_startx;
	int			f_starty;
	t_img		f_map_dynamic;
	bool		focus_rendered;
}		t_map;

/*
* camera = position of the current column
* perp_wall_dist = distance from the player to the wall
* wall_x = exact value of where the wall was hit
* side = it will be used to determine if the ray hit a NS or EW wall
*/
typedef struct s_ray
{
	bool			hit;
	double			camera;
	double			ray_dir_x;
	double			ray_dir_y;
	double			map_x;
	double			map_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			step_x;
	double			step_y;
	double			perp_wall_dist;
	double			wall_x;
	bool			side;
	enum e_wall_or	wall_orientation;
	double			wall_height;
	int				number_of_the_wall_hitted;
}		t_raycast;

typedef struct s_pars
{
	int		**map;
	int		error;
	int		map_w;
	int		map_h;
	int		tmp_map_h;
	int		empty_line;
	int		wrongchar;
	int		in_map;
	int		start_x;
	int		start_y;
	char	start_dir;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	char	*fr;
	char	*fg;
	char	*fb;
	int		c;
	char	*cr;
	char	*cg;
	char	*cb;
}	t_pars;

typedef struct s_game
{
	t_win				win;
	t_keys				keys;
	t_player			player;
	t_map				map;
	t_raycast			raycast;
	unsigned int		win_w;
	unsigned int		win_h;
	enum e_game_state	state;
	uint64_t			created_at;
	uint64_t			updated_at;
	int					fps;
	t_pars				data;
	t_img				xpm_images[XPM_NULL];
	t_animation			anim_h;
	t_animation			anim_h_light;
}	t_game;

/*----------------  FAT ARG HELPER  ---------------*/
typedef struct s_cell_param
{
	int		x;
	int		y;
	int		i;
	int		j;
	float	start_x;
	float	start_y;
}	t_cell_param;

typedef struct s_rect
{
	t_img	*img;
	int		x;
	int		y;
	int		w;
	int		h;
	int		color;
}	t_rect;

typedef struct s_copy_pixel
{
	t_img	src_img;
	int		src_x;
	int		src_y;
	t_img	dst_img;
	int		dst_x;
	int		dst_y;
}	t_copy_pix;

typedef struct s_sprite_slice_data
{
	int	x;
	int	y;
	int	width;
	int	height;
}	t_sprite_slice_data;

/*----------------  expose_hook.c  ---------------*/
int			expose_hook(t_game *game);

/*----------------  mouse_hook.c  ---------------*/
int			mouse_move(int x, int y, t_game *game);
int			mouse_press(int button, int x, int y, t_game *game);
int			mouse_release(int button, int x, int y, t_game *game);

/*----------------  key_hook.c  ---------------*/
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);

/*----------------  main.c  ---------------*/
int			main(int argc, char **argv);

/*----------------  draw_rectangle.c  ---------------*/
void		draw_rect(t_rect rect);

/*----------------  optimization.c  ---------------*/
void		img_pix_put(t_img *img, int x, int y, int color);

/*----------------  init_keys_struct.c  ---------------*/
bool		init_keys_struct(t_game *game);

/*----------------  init_hooks_logics.c  ---------------*/
bool		init_hooks_logics(t_game *game);

/*----------------  init_project.c  ---------------*/
bool		init_project(t_game **game, t_pars *data);

/*----------------  init_player_struct.c  ---------------*/
bool		init_player_struct(t_game *game);

/*----------------  init_xpm_images.c  ---------------*/
bool		init_xpm_images(t_game *game);

/*----------------  init_map_struct.c  ---------------*/
bool		init_map_struct(t_game *game);

/*----------------  init_window_struct.c  ---------------*/
bool		init_window_struct(t_game **game);

/*----------------  init_game_struct.c  ---------------*/
bool		init_game_struct(t_game **game, t_pars *data);

/*----------------  init_pars_struct.c  ---------------*/
void		init_pars(t_pars **data);

/*----------------  close.c  ---------------*/
int			close_game(void *p);

/*----------------  fps.c  ---------------*/
uint64_t	gettimeofday_ms(void);
uint64_t	timestamp_in_ms(t_game *game);

/*----------------  colors.c  ---------------*/
int			encode_rgb(int r, int g, int b);

/*----------------  is_wall.c  ---------------*/
bool		is_wall(int num);

/*----------------  image_helpers.c  ---------------*/
t_img		new_img(int w, int h, t_win *window);
t_img		set_new_xpm(char *path, t_win *window);
void		put_img_to_img(t_img *dst, t_img *src, int x, int y);
void		copy_pixel_img(t_copy_pix c);

/*----------------  handle_keys.c  ---------------*/
void		rotate(t_game *game, bool lr, double speed);
void		handle_keys(t_game *game);

/*----------------  layout_home_screen.c  ---------------*/
int			layout_home_screen(t_game *game);

/*----------------  layout_game_screen.c  ---------------*/
int			layout_game_screen(t_game *game);

/*----------------  layout_map_screen.c  ---------------*/
void		layout_map_screen(t_game *game);

/*----------------  update.c  ---------------*/
int			update(t_game *game);

/*----------------  parser.c  ---------------*/
void		parse_all(t_pars *data, char *file);

/*----------------  pars_colours.c  ---------------*/
void		pars_colours(t_pars *data, char *str);

/*----------------  pars_errors.c  ---------------*/
void		ft_errors(t_pars *d, char *str);
int			ft_empty_line(char *str);
void		ft_exit(t_pars *data, char *str);

/*----------------  pars_map.c  ---------------*/
void		map_pars(t_pars *data, char *file);
int			is_map(t_pars *data, char *str);

/*----------------  pars_texture.c  ---------------*/
void		get_texture(t_pars *data, char *str);

/*----------------  free_map_and_colour.c  ---------------*/
void		free_colours(t_pars *data);
void		free_map(t_pars *data, int ***map);
void		free_tmp_map(t_pars *data, int ***map);

/*----------------  pars_utils.c  ---------------*/
int			check_fd(t_pars *data, char *file);
void		map_check(t_pars *data, char *str);
int			det_c(char *str, char c);
int			data_check(t_pars *data);
int			is_special(char c);

/*----------------  pars_utils2.c  ---------------*/
int			is_number(t_pars *data, char c);
void		ft_exit2(t_pars *data, char *str);

/*----------------  get_next_line.c --------------*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int			get_next_line(int fd, char **line, t_pars *data);
char		*ft_subbuff(char *buff, int start, int len);

/*----------------  raycast.c  ---------------*/
int			raycast(t_game *game);

/*----------------  raycast_utils.c  ---------------*/
void		set_hit_and_wall_number(t_game *game);

/*----------------  display.c  ---------------*/
void		put_column_to_win(t_game *game, int x);

/*----------------  minimap.c  ---------------*/
void		minimap(t_game *game);

/*----------------  animation_tools.c  ---------------*/
t_sprite	new_sprite(char *name, char *file_path, t_win *win);

/*----------------  init_animation_struct.c  ---------------*/
bool		init_animation_struct(t_game *game);
bool		init_anim_minimap(t_game *game);
bool		init_anim_hand(t_game *game, char *path, t_animation *anim);

/*----------------  animation_utils.c  ---------------*/
t_lst		*lst_new_double(void *content);
void		lstadd_back_double(t_lst **lst, t_lst *new);
t_lst		*lstlast(t_lst *lst);

/*---------------- animation_player_hand.c  ---------------*/
void		player_hand(t_game *game);

/*---------------- key_*.c  ---------------*/
void		key_esc(t_game *game);
void		key_enter(t_game *game);
void		key_tab(t_game *game);
void		key_space(t_game *game);
void		key_m(t_game *game);
void		key_left(t_game *game);
void		key_right(t_game *game);
void		key_w(t_game *game);
void		key_s(t_game *game);
void		key_a(t_game *game);
void		key_d(t_game *game);
void		key_e(t_game *game);

#endif
