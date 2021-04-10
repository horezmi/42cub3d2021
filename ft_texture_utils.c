#include "cub3d.h"

void	ft_init_texture(t_all *all)
{
	all->weImg.img = mlx_xpm_file_to_image(all->win.mlx, "./weTxtr.xpm", &all->weImg.w, &all->weImg.h);
	all->weImg.addr = mlx_get_data_addr(all->weImg.img, &all->weImg.bpp, &all->weImg.line_l, &all->weImg.en);

	all->noImg.img = mlx_xpm_file_to_image(all->win.mlx, "./noTxtr.xpm", &all->noImg.w, &all->noImg.h);
	all->noImg.addr = mlx_get_data_addr(all->noImg.img, &all->noImg.bpp, &all->noImg.line_l, &all->noImg.en);
	
	all->eaImg.img = mlx_xpm_file_to_image(all->win.mlx, "./eaTxtr.xpm", &all->eaImg.w, &all->eaImg.h);
	all->eaImg.addr = mlx_get_data_addr(all->eaImg.img, &all->eaImg.bpp, &all->eaImg.line_l, &all->eaImg.en);

	all->soImg.img = mlx_xpm_file_to_image(all->win.mlx, "./soTxtr.xpm", &all->soImg.w, &all->soImg.h);
	all->soImg.addr = mlx_get_data_addr(all->soImg.img, &all->soImg.bpp, &all->soImg.line_l, &all->soImg.en);

}
void	ft_pixel_texture(t_all *all)
{
	int x = 0;
	int y = 0;

	all->color = 0;
	if (all->ray.wallSide == 0)//we
	{
		x = all->weImg.w * (-all->ray.sideCordX);
		y = all->weImg.h * all->ray.sideCordY;
		all->color = *(unsigned int *)(all->weImg.addr + (y * all->weImg.line_l + x * (all->weImg.bpp / 8)));
	}
	else if (all->ray.wallSide == 1)//ea
	{
		x = all->eaImg.w * (-all->ray.sideCordX);
		y = all->eaImg.h * all->ray.sideCordY;
		all->color  = *(unsigned int *)(all->eaImg.addr + (y * all->eaImg.line_l + x * (all->eaImg.bpp / 8)));
	}
	else if (all->ray.wallSide == 2)//no
	{
		x = all->noImg.w * (all->ray.sideCordX);
		y = all->noImg.h * all->ray.sideCordY;
		all->color  = *(unsigned int *)(all->noImg.addr + (y * all->noImg.line_l + x * (all->noImg.bpp / 8)));
	}
	else if (all->ray.wallSide == 3)//so
	{
		x = all->soImg.w * (all->ray.sideCordX);
		y = all->soImg.h * all->ray.sideCordY;
		all->color  = *(unsigned int *)(all->soImg.addr + (y * all->soImg.line_l + x * (all->soImg.bpp / 8)));
	}
}

void 	ft_side_texture(t_all *all)
{
	all->ray.sideCordX = 0;

	float wallY = 0;
	float wallX = 0;
	if (all->ray.side == 0)
	{
		wallY = all->plr.y + all->ray.perpWallDist * all->ray.rayDirY;
		if (all->ray.mapX < all->plr.x)
		{
			all->ray.wallSide = 0;
			all->ray.sideCordX = wallY - (int)wallY;
		}
		else
		{
			all->ray.wallSide = 1;
			all->ray.sideCordX = 1 - (wallY - (int)wallY);
		}
	}
	else if (all->ray.side == 1)
	{
		wallX = all->plr.x + all->ray.perpWallDist * all->ray.rayDirX;
		if (all->ray.mapY < all->plr.y)
		{
			all->ray.wallSide = 2;
			all->ray.sideCordX = wallX - (int)wallX;
		}
		else
		{
			all->ray.wallSide = 3;
			all->ray.sideCordX = 1 - (wallX - (int)wallX);
		}
	}
}