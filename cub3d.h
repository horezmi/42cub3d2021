#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "GNL/get_next_line.h"
#include "libft/libft.h"
#include "mlx.h"
#include <math.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				  t_point;

typedef struct	s_conf
{
	int				winX;
	int				winY;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*spr;
	char 			*f;
	char			*c;
	int				flag;
	int				count;
}				  t_conf;

typedef struct	s_ray
{
	float       rayDirX;
	float       rayDirY;

	int         mapX;
	int         mapY;

	float       sideDistX;
	float       sideDistY;
	float       deltaDistX;
	float       deltaDistY;

	float       perpWallDist;

	int         stepX;
    int         stepY;
	int         hit;
	int         side;

    float       drawStart;
    float       drawEnd;

	float		sideCordX;
	float		sideCordY;
	int			wallSide;
}				  t_ray;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
	int 		w;
	int			h;
}				  t_win;


typedef struct	s_plr 
{
	float		x;
	float		y;
	float		dirX;
	float		dirY;
	float		planeX;
	float		planeY;
	float		cameraX;
}				  t_plr;

typedef struct	s_map
{
	char		**map;
	int			sprLen;
	int			plrLen;
}				t_map;

typedef struct	s_all 
{
	t_win		win;
	t_plr		plr;
	t_point		pnt;
	t_ray		ray;
	t_win		noImg;
	t_win		soImg;
	t_win		eaImg;
	t_win		weImg;
	t_win		sprImg;
	t_conf		conf;
	t_map		map;
	int			color;
}				t_all;

char	**ft_create_map_array(t_all *all, int size, t_list **head);
int 	ft_print_pixel(t_all *all, int color);
void	ft_plr_start(t_all *all, char c);

void	ft_pixel_texture(t_all *all);

void	ft_draw_map(t_all *all);
void	ft_rotate_cam(t_all *all, float rotate);
int		ft_key_down(int key, t_all *all);

int		ft_need_config(t_all *all);
void    ft_parse_config(t_all *all, char **strArr, int lenArr, int lenFirstArg);
void	ft_parse_map(t_all *all, char *str, t_list **head);
void	ft_parse(t_all *all, char *str, t_list **head);

void 	ft_raycast_map_step(t_all *all);
void	ft_raycast_map_dda(t_all *all);
void	ft_raycast_map_dist(t_all *all);
void	ft_raycast_map(t_all *all);

int		ft_start_mlx(t_all *all);
int		ft_next_frame(t_all *all);

void	ft_init_texture(t_all *all);
void 	ft_side_texture(t_all *all);

// void	ft_check_map(t_all *all);
// void	ft_check_params(t_all *all);

#endif