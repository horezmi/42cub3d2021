#include "cub3d.h"

int		ft_next_frame(t_all *all) 
{
	int x;
	
	x = -1;

	all->win.img = mlx_new_image(all->win.mlx, 1400, 1400);
	all->win.addr =mlx_get_data_addr(all->win.img, &all->win.bpp, &all->win.line_l,
                                 &all->win.en);
	while (x++ < 1400)
	{
		all->pnt.x = x;
		ft_raycast_map(all);
		ft_draw_map(all);
	}
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
	mlx_destroy_image(all->win.mlx, all->win.img);
	return 0;
}

int		ft_start_mlx(t_all *all)
{
	int			x;
	int 		y;

	x = -1;
	y = -1;

	int i = -1;
	while (all->map.map[++i])
	printf("%s\n", all->map.map[i]);

	all->win.mlx = mlx_init();
	all->win.win = mlx_new_window(all->win.mlx, 1400, 1400, "cub3d");

	while (all->map.map[++y])
	{
		all->pnt.y = y;
		x = -1;
		while (all->map.map[y][++x])
		{
			all->pnt.x = x;
			if (all->map.map[y][x] == 'N' || all->map.map[y][x] == 'S' || all->map.map[y][x] == 'E' || all->map.map[y][x] == 'W')
			{
					ft_plr_start(all, all->map.map[y][x]);
					all->map.map[y][x] = '0';
			}
		}
	}
	ft_init_texture(all);
    mlx_loop_hook(all->win.mlx, ft_next_frame, all);
	mlx_hook(all->win.win, 2, 1L << 0, ft_key_down, all);
	mlx_loop(all->win.mlx);
	return 0;
}
