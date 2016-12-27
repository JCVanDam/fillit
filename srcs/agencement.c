/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agencement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:15:27 by maxpetit          #+#    #+#             */
/*   Updated: 2016/05/16 16:17:07 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filit.h"

int		g_tetriminos;

int		ft_mv_tetri(t_list *list, int size_tmp)
{
	if (ft_check_insubmap(list, size_tmp))
	{
		ft_tetri_left(list);
		return (1);
	}
	else if ((list->ordonnee + list->size) + 1 <= size_tmp)
	{
		list->ordonnee += 1;
		ft_tetri_right(list, list->ordonnee);
		return (1);
	}
	return (0);
}

int		ft_insert_tetri(int *map, t_list *list)
{
	int j;

	j = 0;
	if (ft_check_cmp(map, list))
	{
		while (j < list->size)
		{
			map[list->ordonnee + j] = map[list->ordonnee + j] + list->shape[j];
			j++;
		}
		return (1);
	}
	return (0);
}

int		ft_place_tetri(int *map, t_list *list, int size_tmp, int cut_map)
{
	if (ft_insert_tetri(map, list))
		return (0);
	else
		if (ft_mv_tetri(list, size_tmp))
			return (ft_place_tetri(map, list, size_tmp, cut_map) + 0);
	ft_initialize_tetri(list);
	return (1);
}

/*
**
*/

int		ft_extend(int *map, t_list *list, int *size_tmp)
{
	static int	cut_map = 0;

	if (!(*size_tmp))
		ft_create_submap(map, &cut_map, size_tmp);
	if (!ft_fill(map, list, cut_map, *size_tmp))
	{
		ft_create_submap(map, &cut_map, size_tmp);
		ft_initialize_list(list);
		ft_extend(map, list, size_tmp);
	}
	return (0);
}

int		ft_fill(int *map, t_list *list, int cut_map, int size_tmp)
{
	if (!(ft_place_tetri(map, list, size_tmp, cut_map)))
	{
		if (list->next)
			if (ft_fill(map, list->next, cut_map, size_tmp) == 1)
				return (1);
		if (list->pos == g_tetriminos)
			return (1);
		ft_initialize_map(map, list);
		while ((ft_mv_tetri(list, size_tmp)))
			if (ft_insert_tetri(map, list))
			{
				if (list->pos == g_tetriminos)
					return (1);
				if (ft_fill(map, list->next, cut_map, size_tmp))
					return (1);
				else
					ft_initialize_map(map, list);
			}
		ft_initialize_tetri(list);
	}
	return (0);
}
