/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:58:52 by aclement          #+#    #+#             */
/*   Updated: 2023/10/21 22:22:18 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_tab(t_map *map)
{
	int	j;

	j = 0;
	while(j < map->mapheight)
	{
		int i = 0;
		while (i < map->mapwidth)
		{
			printf("%c", map->fmap[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
    printf("ca passe\n");
}

void	recup_map(t_map *map)
{
	int i;
	int j;

    printf("mapwidth : %d & mapheight: %d\n", map->mapwidth, map->mapheight);
	map->fmap = malloc(sizeof(char *) * map->mapheight);
	if (!map->fmap)
		return ;
    j = 0;
    while (j < map->mapheight)
    {
    	i = 0;
        map->fmap[j] = malloc(sizeof(char) * (map->mapwidth));
		if (! map->fmap[j])
			return ;
        while (map->tab[j][i] != '\0')
        {
            map->fmap[j][i] = map->tab[j][i];
            i++;
        }
        while (i < map->mapwidth)
            map->fmap[j][i++] = '1';
        // map->fmap[j][i] = '\0';
        j++;
    }
    print_tab(map);
}













    
	//while(i < map->mapheight)
	//{
	//	j = 0;
	//	map->fmap[i] = malloc(sizeof(char) * map->mapwidth + 1);
	//	while (j < map->mapwidth)
	//	{
	//		map->fmap[i][j] = '1';
	//		j++;
	//	}
    //    i++;
	//}
	//map->fmap[0][0] = map->tab[1][1];
    
	// i = 0;
	// while (i < map->mapwidth)
	// {
		// j = 0;
		// while (j < map->mapheight)
		// if (map->tab[i][j])
			// map->test[i][j] = map->tab[i][j];
		// j++;
	// }
	// i++;
    // print_tab(map);
// }
