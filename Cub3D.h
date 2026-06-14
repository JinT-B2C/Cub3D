/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:58:26 by torasolo          #+#    #+#             */
/*   Updated: 2026/06/14 12:34:04 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "gnl/get_next_line.h"
# include "lib/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define DEFAULT_WIDTH 1024
# define DEFAULT_HEIGHT 768
# define FOV_FACTOR 0.66
# define KEY_W 119
# define KEY_D 97
# define KEY_S 115
# define KEY_A 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define MAX_DIST 6.0
# define SIDE_DARK 0.70
# define MARGIN 0.25
# define PI 3.141592653589793115997963468544185161590576171875
# define TWO_PI 6.283185307179586

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_ray_data
{
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
}				t_ray_data;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_wall_draw
{
	int			wall_height;
	int			y_start;
	int			y_end;
	double		wall_x;
	char		wall_type;
	double		perp_wall_dist;
}				t_wall_draw;

typedef struct s_conf
{
	char		*tex_n;
	char		*tex_s;
	char		*tex_w;
	char		*tex_e;
	t_rgb		floor;
	t_rgb		sky;
	int			floor_set;
	int			sky_set;
	char		**map;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	char		player_or;
}				t_conf;

typedef struct s_fill
{
	t_conf		*conf;
	char		**visited;
	t_point		*stack;
	int			top;
	int			max;
}				t_fill;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_conf		conf;
	int			width;
	int			height;
	double		player_px;
	double		player_py;
	double		player_angle;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			move_forward;
	int			move_backward;
	int			move_left;
	int			move_right;
	int			rotate_left;
	int			rotate_right;
	int			ceil_color;
	int			floor_color;
	int			dirty;
	t_texture	tex_n;
	t_texture	tex_s;
	t_texture	tex_w;
	t_texture	tex_e;
}				t_game;

/* path.c */
int				check_path(char *path);

/* readfl.c */
char			*strip_nl(char *s);
int				is_line_empty(const char *s);
void			free_lines(char **lines);
char			**read_map(const char *path);

/* parse.c */
int				is_texture_id(const char *line);
int				is_color_id(const char *line);
int				looks_like_map(const char *line);
int				valid_map_chars(const char *line);
int				all_header_set(t_conf *conf);
int				is_duplicate(const char *line, t_conf *conf);
void			parse_color(const char *line, t_conf *conf);
int				parse_rgb_values(char **rgb, t_conf *conf, char c);
char			*skip_spaces(const char *s);
int				try_set_texture(const char *line, t_conf *conf);

/* init_conf.c */
void			init_config(t_conf *conf);
int				parse_cub_file(const char *path, t_conf *conf);

/* map_utils.c */
int				build_map(char **lines, t_conf *conf, int start_line);
int				validate_map(t_conf *conf);
int				flood_fill(t_conf *conf, int x, int y, char **visited);
int				get_map_width(char **lines, int start);
int				get_map_height(char **lines, int start);

/* free.c */
void			free_config(t_conf *conf);
void			game_cleanup(t_game *game);

/* error.c */
void			game_error(const char *message, t_game *game);
void			print_error(const char *message);

/* game_init.c */
int				init_game(t_game *game, const char *map_path);
void			update_camera_vectors(t_game *game);

/* render.c */
int				render(t_game *game);
void			pixel_put(t_img *img, int coord[2], int color, t_game *game);

/* events.c */
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				close_window(t_game *game);

/* raycasting.c */
void			raycasting(t_game *game);

/* raycasting_utils.c */
char			get_wall_type(int side, double ray_dir_x, double ray_dir_y);
void			draw_sky_and_floor(t_game *game, int x, int y_start, int y_end);
void			draw_textured_wall(t_game *game, int x, t_wall_draw *wall,
					t_texture *tex);
int				traverse_dda(t_game *game, t_ray_data *ray);
void			draw_column(t_game *game, int x, t_wall_draw *wall);
void			init_ray_data(t_game *game, int x, t_ray_data *ray,
					t_wall_draw *wall);
void			calc_wall_intersection(t_ray_data *ray, t_wall_draw *wall,
					t_game *game);
void			cast_column(t_game *game, int x);
void			ray_step_x(t_ray_data *ray, t_game *game);
void			ray_step_y(t_ray_data *ray, t_game *game);

/* movement.c */
void			update_player(t_game *game);

/* mov_utils.c */
void			dir_player(t_game *game, double *dx, double *dy);
int				accumulate_input(t_game *game, double *out_dx, double *out_dy,
					double speed);
void			normalize_angle(t_game *game);
void			try_move(t_game *game, double dx, double dy);
int				can_move(t_game *game, double x, double y);

/* textures.c */
int				init_textures(t_game *game);
void			free_textures(t_game *game);
t_texture		*select_texture(t_game *game, char wall_type);
int				get_texture_pixel(t_texture *tex, int x, int y);

#endif
