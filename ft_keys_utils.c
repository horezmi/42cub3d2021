#include "cub3d.h"

void	ft_rotate_cam(t_all *all, float rotate)
{
	float tmpDirX = 0;
	float tmpPlaneX = 0;

	tmpDirX = all->plr.dirX;
	tmpPlaneX = all->plr.planeX;

	all->plr.dirX = all->plr.dirX * cos(rotate) - all->plr.dirY * sin(rotate);
	all->plr.dirY = tmpDirX * sin(rotate) + all->plr.dirY * cos(rotate);

	all->plr.planeX = all->plr.planeX * cos(rotate) - all->plr.planeY * sin(rotate);
	all->plr.planeY = tmpPlaneX * sin(rotate) + all->plr.planeY * cos(rotate);
}

int			ft_key_down(int key, t_all *all)
{
	if (key == 13)
	{
		all->plr.x += all->plr.dirX;
		all->plr.y += all->plr.dirY;
	}
	if (key == 1)
	{
		all->plr.x -= all->plr.dirX;
		all->plr.y -= all->plr.dirY;
	}
	if (key == 0)
	{
		all->plr.x -= all->plr.planeX;
		all->plr.y -= all->plr.planeY;
	}
	if (key == 2)
	{
		all->plr.x += all->plr.planeX;
		all->plr.y += all->plr.planeY;
	}
	float rotate;;
	float rotateSpeed;
	if (key == 123)
	{
		rotateSpeed = 0.09;
		rotate = -rotateSpeed; 
		ft_rotate_cam(all, rotate);
	}
	if (key == 124)
	{
		rotateSpeed = 0.09;
		rotate = rotateSpeed; 
		ft_rotate_cam(all, rotate);
	}
	if (key == 53)
		exit(0);
	ft_next_frame(all);
	return (0);
}