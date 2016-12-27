/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agencement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:53:00 by maxpetit          #+#    #+#             */
/*   Updated: 2016/05/16 15:55:28 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filit.h"

int		g_tetriminos;

/*
**Returns the result of root nb.
*/
int		ft_root(int nb)
{
	int i;

	i = 0;
	while ((i * i) < nb)
		i++;
	if ((i * i) == nb)
		return (i);
	return (i);
}

/*
**Creates a map of size SIZE and fills it with (2 power 32) - 1 result.
*/
int		*ft_create_map(int *map, int i)
{
	while (i < SIZE - 1)
		map[++i] = BIG_INT;
	return (map);
}

/*
**Returns the result of nb ^ power.
*/
int		ft_power(int nb, int power)
{
	static int i = 1;

	if (power == 0)
		return (1);
	if (power == 1)
		return (2);
	nb = nb * 2;
	if (++i == power)
	{
		i = 1;
		return (nb);
	}
	return (ft_power(nb, power));
}

void	ft_mapinitialize(int **map, int *cut_map, int *size_tmp)
{
	int i;

	i = 0;
	while (*map[i])
	{
		if (i < *size_tmp)
			*map[i] = *cut_map;
		else
			*map[i] = BIG_INT;
		i++;
	}
}

/*
**Creats map, gives a temporary size of the smaller square to fill.
**The formula root of tetriminos number multiplied by fore gives the theorical
**smaller square for a number of tetriminos gift.
**Fills an adapted value of power two which depends of size_tmp.
*/
void	ft_create_submap(int *map, int *cut_map, int *size_tmp)
{
	int i;

	i = 0;
	ft_create_map(map, i);
	*size_tmp = ((*size_tmp) == 0) ? ft_root(g_tetriminos * 4) : *size_tmp + 1;
	*cut_map = BIG_INT - ft_power(2, *size_tmp) + 1;
	while (i < *size_tmp)
	{
		map[i] = *cut_map;
		i++;
	}
}
