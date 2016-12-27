/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:15:27 by maxpetit          #+#    #+#             */
/*   Updated: 2016/05/16 16:17:19 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filit.h"

int		g_tetriminos;

void	ft_initialize_map(int *map, t_list *list)
{
	int j;

	j = 0;
	while ((j < list->size))
	{
		map[list->ordonnee + j] = map[list->ordonnee + j] ^ list->shape[j];
		j++;
	}
}

int		ft_initialize_list(t_list *list)
{
	list->ordonnee = 0;
	ft_tetri_top(list, list->ordonnee);
	ft_tetri_right(list, list->ordonnee);
	if (!(list->pos == g_tetriminos))
		if (ft_initialize_list(list->next))
			return (1);
	return (1);
}

void	ft_initialize_tetri(t_list *list)
{
	list->ordonnee = 0;
	ft_tetri_top(list, list->ordonnee);
	ft_tetri_right(list, list->ordonnee);
}
