#include "cub3d.h"

void	ft_draw_map(t_all *all)
{
	ft_side_texture(all);
	all->ray.drawStart = 0;
	all->ray.drawEnd = 0; 
	int lineHeight = 0;
	lineHeight = (int)1400 / all->ray.perpWallDist;

	all->ray.drawStart = -lineHeight / 2 + 1400 / 2;
	if(all->ray.drawStart < 0)
		all->ray.drawStart = 0;

	all->ray.drawEnd = lineHeight / 2 + 1400 / 2; 
	if(all->ray.drawEnd >= 1400)
		all->ray.drawEnd = 1400 - 1;
	
	int y = -1;

	while (++y < 1400)
	{
		all->pnt.y = y;
		if (y < all->ray.drawStart)
			ft_print_pixel(all, 0x0051C9F5);
		if (y >= all->ray.drawStart && y <= all->ray.drawEnd)
		{
			all->ray.sideCordY = (float)(y - all->ray.drawStart) / (float)(all->ray.drawEnd - all->ray.drawStart);
			ft_pixel_texture(all);
			ft_print_pixel(all, all->color);
		}
		if (y > all->ray.drawEnd)
			ft_print_pixel(all, 0x0037291C);
	}
}