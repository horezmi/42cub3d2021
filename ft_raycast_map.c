#include "cub3d.h"

void 	ft_raycast_map_step(t_all *all)
{
	if(all->ray.rayDirX < 0)
	{
		all->ray.stepX = -1;
		all->ray.sideDistX = (all->plr.x - all->ray.mapX) * all->ray.deltaDistX;
	}
	else
	{
		all->ray.stepX = 1;
		all->ray.sideDistX = (all->ray.mapX + 1.0 - all->plr.x) * all->ray.deltaDistX;
	}

	if(all->ray.rayDirY < 0)
	{
		all->ray.stepY = -1;
		all->ray.sideDistY = (all->plr.y - all->ray.mapY) * all->ray.deltaDistY;
	}
	else
	{
		all->ray.stepY = 1;
		all->ray.sideDistY = (all->ray.mapY + 1.0 - all->plr.y) * all->ray.deltaDistY;
	}
}

void	ft_raycast_map_dda(t_all *all)
{
	while (all->ray.hit == 0)
	{	
		if (all->ray.sideDistX < all->ray.sideDistY)
		{
			all->ray.sideDistX += all->ray.deltaDistX;
			all->ray.mapX += all->ray.stepX;
			all->ray.side = 0;
		}
		else
		{
			all->ray.sideDistY += all->ray.deltaDistY;
			all->ray.mapY += all->ray.stepY;
			all->ray.side = 1;
		}
		if (all->map.map[all->ray.mapY][all->ray.mapX] == '1') 
			all->ray.hit = 1;
	}
	all->ray.hit = 0;
}

void	ft_raycast_map_dist(t_all *all)
{
	if (all->ray.side == 0) 
		all->ray.perpWallDist = (all->ray.mapX - all->plr.x + (1 - all->ray.stepX) / 2) / all->ray.rayDirX;
	else 
		all->ray.perpWallDist = (all->ray.mapY - all->plr.y + (1 - all->ray.stepY) / 2) / all->ray.rayDirY;
}

void	ft_raycast_map(t_all *all)
{
	all->plr.cameraX = 2 * all->pnt.x / (float)1400 - 1;
	all->ray.rayDirX = all->plr.dirX + all->plr.planeX * all->plr.cameraX;
	all->ray.rayDirY = all->plr.dirY + all->plr.planeY * all->plr.cameraX;
	all->ray.mapX = (int)all->plr.x;
	all->ray.mapY = (int)all->plr.y;
	all->ray.deltaDistX = fabs(1 / all->ray.rayDirX);
	all->ray.deltaDistY = fabs(1 / all->ray.rayDirY);
	
	ft_raycast_map_step(all);
	ft_raycast_map_dda(all);
	ft_raycast_map_dist(all);
}