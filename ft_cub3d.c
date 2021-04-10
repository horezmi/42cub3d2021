#include "cub3d.h"

int 	ft_print_pixel(t_all *all, int color)
{
	char 		*dst;

	dst = all->win.addr + (all->pnt.y * all->win.line_l + all->pnt.x * (all->win.bpp / 8));
	
	*(unsigned int*)dst = color;
	
	return 0;
}

void	ft_plr_start(t_all *all, char c)
{
	all->plr.x = all->pnt.x;
	all->plr.y = all->pnt.y;

	if (c == 'N')
	{
		all->plr.dirY = -1;
		all->plr.dirX = 0;
		all->plr.planeX = 0.66;
	}
	else if (c == 'E')
	{
		all->plr.dirX = 1;
		all->plr.dirY = 0;
		all->plr.planeY = 0.66;
	}
	else if (c == 'S')
	{
		all->plr.dirY = 1;
		all->plr.dirX = 0;
		all->plr.planeX = -0.66;
	}
	else if (c == 'W')
	{
		all->plr.dirX = -1;
		all->plr.dirY = 0;
		all->plr.planeY = -0.66;
	}
}

char	**ft_create_map_array(t_all *all, int size, t_list **head)
{
	char	**map = ft_calloc(size + 1, sizeof(char *));
	int		i = -1;
	int		j = -1;

	t_list	*tmp = *head;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (map);
}

int		main(int argc, char **argv)
{
	t_all		all;
	t_list		*head;

	int 		fd;
	char		*line;

	line = NULL;
	
	if (argc < 2 || argc > 3) printf("Wrong numbers of arguments\n");
	if (argc == 3) printf("Need --save key/flag\n");
	if ((fd = open(argv[1], O_RDONLY)) == -1) printf("Could not open file\n");

	while (get_next_line(fd, &line) > 0)
		ft_parse(&all, line, &head);
	ft_parse(&all, line, &head);

	// ft_check_params(all);
	// ft_check_map(all);

	close(fd);

	all.map.map = ft_create_map_array(&all, ft_lstsize(head), &head);

	ft_start_mlx(&all);
	return 0;
}
