/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_mvt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 19:23:21 by maxpetit          #+#    #+#             */
/*   Updated: 2016/05/16 14:30:48 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filit.h"

void	ft_tetri_top(t_list *list, int y)
{
	while (list->shape[0] == 0)
	{
		list->shape[0] = list->shape[1];
		list->shape[1] = list->shape[2];
		list->shape[2] = list->shape[3];
		list->shape[3] = 0;
		list->ordonnee = y;
	}
}

void	ft_tetri_right(t_list *list, int y)
{
	while ((list->shape[0] % 2 == 0) && (list->shape[1] % 2 == 0)
	&& (list->shape[2] % 2 == 0) && (list->shape[3] % 2 == 0))
	{
		list->shape[0] = list->shape[0] >> 1;
		list->shape[1] = list->shape[1] >> 1;
		list->shape[2] = list->shape[2] >> 1;
		list->shape[3] = list->shape[3] >> 1;
		list->ordonnee = y;
	}
}

void	ft_tetri_left(t_list *list)
{
	list->shape[0] = list->shape[0] << 1;
	list->shape[1] = list->shape[1] << 1;
	list->shape[2] = list->shape[2] << 1;
	list->shape[3] = list->shape[3] << 1;
}
