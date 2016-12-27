/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:15:27 by maxpetit          #+#    #+#             */
/*   Updated: 2016/05/16 16:03:00 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filit.h"

int		ft_check_cmp(int *map, t_list *list)
{
	int j;

	j = 0;
	while (j < list->size)
	{
		if (((map[list->ordonnee + j]) & list->shape[j]) == 0)
			j++;
		else
			return (0);
	}
	return (1);
}

int		ft_check_insubmap(t_list *list, int size_tmp)
{
	int j;

	j = 0;
	while ((j < list->size) && ((list->shape[j]) < (ft_power(2, size_tmp - 1))))
		j++;
	if (j != list->size)
		return (0);
	return (1);
}
