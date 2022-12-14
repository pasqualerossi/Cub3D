/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:56:40 by prossi            #+#    #+#             */
/*   Updated: 2022/12/14 15:44:51 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <limits.h>
# include "../minilibx/mlx.h"

// screen

# define SCREEN_HEIGHT 			900
# define SCREEN_WIDTH 			1400

// texture

# define TEXTURE_HEIGHT 			64
# define TEXTURE_WIDTH 				64

// game controls

# define ESC 					53
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_EXIT			17

// player controls

# define W 						13
# define A 						0
# define S 						1
# define D 						2
# define UP 					126
# define DOWN 					125
# define LEFT 					123
# define RIGHT 					124
# define P 						35

// game structs

typedef struct s_point
{
	double			x;
	double			y;
}			t_point;

typedef struct s_state
{
	t_point			pos;
	t_point			dir;
	t_point			plane;
}			t_state;

typedef struct s_var
{
	double			position_x;
	double			position_y;
	double			direction_x;
	double			direction_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_direction_x;
	double			ray_direction_y;
	double			side_distance_x;
	double			side_distance_y;
	double			delta_distance_x;
	double			delta_distance_y;
	double			perspective_wall_distance;
	double			wall_x;
	double			step;
	double			texture_position;
	double			frame_time;
	double			move_speed;
	double			rotate_speed;

	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				texture_number;
	int				texture_y;
	int				texture_x;

	unsigned int	color;
}			t_var;

// screen struct

typedef struct s_img
{
	void	*pointer_to_image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

// textures struct

typedef struct s_img2
{
	void	*pointer_to_image;
	int		*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img2;

// player struct

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	right;
	int	left;
	int	p;
}				t_key;

// map struct

typedef struct s_cub
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_img2			img2[4];
	char			**rgb;
	char			**xpm;
	char			**map;
	unsigned long	floor;
	unsigned long	ceilling;
	t_var			var;
	int				texture[4][TEXTURE_HEIGHT * TEXTURE_WIDTH];
	t_key			key;
}				t_cub;

// raycasting struct

typedef struct s_ray
{
	t_point	ray_dir;
	t_point	side_dist;
	t_point	delta_dist;
	int		map_x;
	int		map_y;
	double	perspective_wall_distance;
	int		step_x;
	int		step_y;
	int		side;
}			t_ray;

//---------game_map_folder----------//

int				init_colours(void);
int				parse_info(int fd);
int				init_textures(void);
int				validate_map(void);
int				check_characters(void);
int				parse_map(int fd);
int				parse(char *file);

void			mlx_place_pixel(int x, int y, int color);
void			draw_floor(void);
void			draw_ceiling(void);
void			init(void);
void			calculate_ray_position_and_direction(int x);
void			set_box_position(void);
void			calculate_delta_distance(void);
void			calculate_step_and_side_distance_x(void);
void			calculate_step_and_side_distance_y(void);
void			dda(void);
void			raycast_loop(void);
void			calculate_distance_perspective(void);
void			calculate_vertical_line_height(void);
void			calculate_draw_start_and_draw_end(void);
void			calculate_texture_x(void);
void			draw_vertical_texture_stripe(int x);

//------game_player_folder-------//

int				key_press(int keycode);
int				key_release(int keycode);

void			hooks(void);
void			player_move_forward(void);
void			player_move_backwards(void);
void			player_move_left(void);
void			player_move_right(void);
void			player_rotate_right(void);
void			player_rotate_left(void);

//------------game_utils_folder------------//

const char		*get_exit(const char *file);
unsigned long	rgb_to_hex(int red, int green, int blue);

int				get_next_line(int fd, char **line);
int				ft_new_line(char *buf);
int				ft_array_length(char **arr);
int				ft_strncmp(const char *s1, char *s2, size_t n);
int				ft_atoi(const char *str);

void			ft_free(char ***arr);
void			*ft_calloc(size_t count, size_t size);

char			**ft_reallocation(char **ptr, int size);
char			**ft_split(char const *str, char c);
char			*ft_strchr(const char *s, int i);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);

size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

//---------main.c----------//

int				quit_game(void);
t_cub			*data(void);

#endif