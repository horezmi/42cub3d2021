#include "cub3d.h"

int		ft_need_config(t_all *all)
{
	if (all->conf.winX && all->conf.winY  && all->conf.no \
	&& all->conf.so && all->conf.we && all->conf.ea && all->conf.spr \
	&& all->conf.f && all->conf.c)
		return (0);
	return (1);
}

void    ft_parse_config(t_all *all, char **strArr, int lenArr, int lenFirstArg)
{
	if (strArr[0][0] == 'R' && lenFirstArg == 1 && lenArr == 3)
		printf("R is OK\n");
	else if (strArr[0][0] == 'N' && strArr[0][1] == 'O' && lenFirstArg == 2 && lenArr == 2)
		printf("NO is OK\n");
	else if (strArr[0][0] == 'S' && strArr[0][1] == 'O' && lenFirstArg == 2 && lenArr == 2)
		printf("SO is OK\n");
	else if (strArr[0][0] == 'W' && strArr[0][1] == 'E' && lenFirstArg == 2 && lenArr == 2)
		printf("WE is OK\n");
	else if (strArr[0][0] == 'E' && strArr[0][1] == 'A' && lenFirstArg == 2 && lenArr == 2)
		printf("EA is OK\n");
	else if (strArr[0][0] == 'S' && lenFirstArg == 1 && lenArr == 2)
		printf("S is OK\n");
	else if (strArr[0][0] == 'F' && lenFirstArg == 1 && lenArr == 2)
		printf("F is OK\n");
	else if (strArr[0][0] == 'C' && lenFirstArg == 1 && lenArr == 2)
		printf("C is OK\n");
	else
		printf("Incorrect parameter value\n");
}

// void	ft_check_map(t_all *all)
// {
// 	int y = -1;
// 	int x = -1;
// 	all->map.plrLen = 0;
// 	all->map.sprLen = 0;
// 	while (all->map.map[++y])
// 	{
// 		x = -1;
// 		while(all->map.map[++x])
// 		{
// 			if (all->map.map[y][x] == '2')
// 				all->map.sprLen++;
// 			if (all->map.map[y][x] == 'N' || all->map.map[y][x] == 'S' || all->map.map[y][x] == 'E' || all->map.map[y][x] == 'W')
// 				all->map.plrLen++;
// 			if (all->map.map[y][x] == ' ')
// 				printf("has space\n");
// 		}
// 	}
// }

void	ft_parse_map(t_all *all, char *str, t_list **head)
{
	int		i = 0;

	while (str[i])
	{
		if (!ft_strchr("012NEWS", str[i++]))
		{
			printf("Error map\n");
			return ;
		}
	}
	ft_lstadd_back(head, ft_lstnew(str));	
}

void	ft_parse(t_all *all, char *str, t_list **head)
{
	char	**strArr;
	int		lenStrArr = 0;
	int		lenFirstArg = 0;

	all->conf.c = 0;
	if (all->conf.c != 0)
	{
		strArr = ft_split(str, ' ');
		if (strArr[0])
		{
			while (strArr[lenStrArr])
			{
				lenStrArr++;
			}

			lenFirstArg = ft_strlen(&str[0]);
			ft_parse_config(all, strArr, lenStrArr, lenFirstArg);
		}
	}
	else
		ft_parse_map(all, str, head);
}