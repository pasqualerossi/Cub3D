/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:56:40 by prossi            #+#    #+#             */
/*   Updated: 2022/10/28 17:00:25 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// libraries

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"

// define actions

// screen
# define SCREEN_HEIGHT 			900
# define SCREEN_WIDTH 			1200

// texture
# define TEX_HEIGHT 			64
# define TEX_WIDTH 				64

// game assets
# define WALL					0x00F0F0F0
# define WALKABLE				0x00000000
# define PLAYER					0x00FF0000

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

//structs

// game struct

typedef struct s_var 
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			wall_x;
	double			step;
	double			tex_pos;
	double			frame_time;
	double			move_speed;
	double			rot_speed;

	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_width;
	int				tex_height;
	int				tex_num;
	int				tex_y;
	int				tex_x;

	unsigned int	color;
}			t_var;

// screen struct

typedef struct s_img {
	void	*ptr_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

// textures struct

typedef struct s_img2 {
	void	*ptr_img;
	int		*addr;
	int		bits_per_pixel;
	int		line_len;
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

//------game_utils-------//

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
	t_var_minimap	var_mm;
	int				texture[4][TEX_HEIGHT * TEX_WIDTH];
	t_key			key;
}				t_cub;


//------game_utils-------//

// game_utils.c
int				ft_arrlen(char **arr);
void			ft_free(char ***arr);
char			**ft_realloc(char **ptr, int size);
const char		*get_ext(const char *file);
unsigned long	rgb_to_hex(int r, int g, int b);

// get_next_line.c
char			*get_next_line(int fd);

// libft.c
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			**ft_split(char const *str, char c);
char			*ft_strchr(const char *s, int i);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strlen(const char *str);
int				ft_strncmp(const char *s1, char *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);


//------game_map-------//

// map_colours.c
void			convert_colors(int *rgb, int i);
int				init_colors(void);

// map_logic.c
void			init(void);
int				parse(char *file);
int				parse_map(int fd);

// map_textures.c
int				parse_info(int fd);

// map_validation.c
int				validate_map(void);

// map_vectors.c
int				check_chars(void);


//------game_player-------//

// player_controls.c
int				key_press(int keycode);
int				key_release(int keycode);
void			hooks(void);

// player_movement.c
void			move_forward(void);
void			move_backwards(void);
void			move_left(void);
void			move_right(void);

// player_rotate.c
void			rotate_right(void);
void			rotate_left(void);


//------game_main-------//

// cub3d.c
int				launch_game(void);
int				quit_game(void);
t_cub			*data(void);
int				main(int argc, char **argv);

#endif