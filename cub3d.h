/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:17:12 by abiari            #+#    #+#             */
/*   Updated: 2020/02/15 23:59:54 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <math.h>
# include "xmalloc.h"
# include <stdio.h>

# define BUFFER_SIZE 100
# define MALLOC xmalloc
# define FREE xfree
# define FLUSH xflush
# define EXIT xexit

# define RAD M_PI/180
# define TILE_SIZE 64
# define FOV_ANGLE 60

typedef struct	s_h_ray_data
{
	int		foundhorzwallhit;
	float	horzwallhitx;
	float	horzwallhity;
	int		horzwallcontent;
	float	nexthorztouchx;
	float	nexthorztouchy;
	float	xtocheck;
	float	ytocheck;
	float	horzhitdistance;
}				t_h_ray_data;
typedef struct	s_v_ray_data
{
	int		foundvertwallhit;
	float	vertwallhitx;
	float	vertwallhity;
	int		vertwallcontent;
	float	nextverttouchx;
	float	nextverttouchy;
	float	xtocheck;
	float	ytocheck;
	float	verthitdistance;
}				t_v_ray_data;
typedef struct	s_cast_data
{
	float			xhintercept;
	float			yhintercept;
	float			xvintercept;
	float			yvintercept;
	float			xstep;
	float			ystep;
	int				rayup;
	int				raydown;
	int				rayleft;
	int				rayright;
	t_h_ray_data	h_ray_data;
	t_v_ray_data	v_ray_data;
}				t_cast_data;
typedef struct	s_player
{
	float	x;
	float	y;
	int		turn_direction;
	int		walk_direction;
	float	rotation_angle;
	int		walk_speed;
	int		turn_speed;
	int		pov_direction;
}				t_player;
typedef	struct	s_res
{
	long long	height;
	long long	width;
}				t_res;
typedef	struct	s_paths
{
	char *no;
	char *so;
	char *we;
	char *ea;
	char *s;
}				t_paths;
typedef struct	s_map
{
	int		rows;
	int		columns;
	char	*map;
}				t_map;
typedef	struct	s_color
{
	int r;
	int	g;
	int	b;
}				t_color;
typedef struct	s_game_data
{
	int		check;
	t_res	res;
	t_paths paths;
	t_color c;
	t_color f;
	t_map	map;
}				t_game_data;
typedef struct	s_ray
{
	float	ray_angle;
	float	wallhitx;
	float	wallhity;
	float	distance;
	int		washitvertical;
	int		wallhitcontent;
	int		rayup;
	int		raydown;
	int		rayleft;
	int		rayright;
}				t_ray;
typedef struct	s_textures
{
	void	*ptr;
	int		width;
	int		height;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_textures;
typedef struct	s_wall
{
	float	perpdistance;
	float	distanceprojplane;
	float	projectedwallheight;
	float	wallstripeheight;
	float	walltoppixel;
	float	wallbottompixel;
	int		textureoffsetx;
	int		textureoffsety;
	int		distancefromtop;
	int		color;
	int		i;
	int		j;
}				t_wall;
typedef struct	s_img_data
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_img_data;
typedef struct	s_sp
{
	void		*ptr;
	int			*data;
	float		x;
	float		y;
	float		distance;
}				t_sp;
void			*g_mlx_ptr;
void			*g_win_ptr;
int				g_num_rays;
t_cast_data		g_cast_data;
t_player		g_player;
t_game_data		g_game_data;
t_textures		g_textures[4];
t_img_data		g_img;
t_ray			g_rays[5120];
t_player		g_player;
t_sp			g_sp[100];
t_wall			g_wall;
int				g_num_sp;

void			mlx_img_mod(int x, int y, int color);
int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strdup(const char *str);
char			*ft_strchr(const char *s1, int c);
int				ft_isdigit(int s);
char			**ft_split(char const *str, char c);
int				ft_atoi(const char *ptr);
int				ft_comp(char *str, char *f);
char			*ft_strtrimall(char *s, char *set);
void			*ft_calloc(size_t n, size_t size);
char			*ft_strtrim(char const *s1, char const *set);
void			cast_ray(float ray_angle, int i);
int				has_wall(float x, float y);
int				render_frames(void);
int				destroy_window(void);
int				key_pressed(int key);
int				key_released(int key);
void			player_pos(void);
int				set_route(char **lines);
char			**read_input(char *file);
int				rgbtoint(int r, int g, int b);
char			*ft_strchr(const char *s, int c);
void			affect_distance(void);
void			init_v_data(float ray_angle);
void			v_ray_inter(float ray_angle);
void			h_ray_inter(float ray_angle);
void			init_h_data(float ray_angle);
float			normalize_angle(float angle);
void			screen_shot();
int				ft_strcmp(char *s1, char *s2);
void			set_h(void);
void			set(int flag, int i);
void			set_v(void);
void			xflush(void);
void			*xexit(int x);
void			*ftft();
void			ft_putstr(char *str);
void			sprites(void);
void			init_sprite(int k, int *x_s, int *y_s);
void			render_sp(int x, int y, int sp_size, int k);
void			update_sp_d(void);
void			sp_pos(void);
int				has_sp(float x, float y);
void			putstripes(float ray_angle, int x, int k);
void			grownd(int x);
void			wall(int x);
void			ceiling(int x);
void			init_stripe(float ray_angle, int k);
void			move_x(float new_x, float new_y);
void			move_y(float new_x, float new_y);
void			set_angle(int i, int j);
void			save(int argc, char **argv);
void			black_img(void);
float			dist(float x1, float x2, float y1, float y2);
void			render3d(void);
void			check_cub(int argc, char **argv);
char			**affect(char **tmp, char **line, char **buffer, char ***ret);
int				map_check2(char *buffer);
char			**read_input(char *file);
char			*skip_blanks(char *str);
void			skip_digits(char **line);
void			skip_digits2(char ***line);
void			check_max_w(char *line);
int				store_resolution(char *line);
void			check_max_h(char *line);
int				fill_f(char **line);
int				store_f(char *line);
int				store_ea(char *line);
int				store_we(char *line);
int				store_so(char *line);
int				store_no(char *line);
char			*skip_blanks(char *str);
int				store_map(char ***line);
int				map_size(char **line);
int				store_s(char *line);
int				store_c(char *line);
int				fill_c(char **line);
void			check_p(char *map, int *p);
char			*ft_strdup(const char *src);
int				check_all(char *map);
long long		ft_atoi2(const char *ptr);

#endif
