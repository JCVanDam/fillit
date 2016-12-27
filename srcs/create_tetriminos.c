/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:17:02 by maxpetit          #+#    #+#             */
/*   Updated: 2016/05/16 15:47:19 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filit.h"

int		ft_tetri_size(t_list *list)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while ((++i < 4))
		if (list->shape[i] != 0)
			j++;
	return (j);
}

/*
**Allows a memory space and fills elem struct.
*/

t_list	*ft_create_elem(t_list *list, int *nb, char letter)
{
	t_list	*elem;
	int		i;

	i = -1;
	elem = list;
	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		return (0);
	while (++i < 4)
		elem->shape[i] = nb[i];
	elem->ordonnee = 0;
	elem->pos = letter;
	elem->size = ft_tetri_size(elem);
	elem->option = PASPLACE;
	elem->next = NULL;
	return (elem);
}

/*
**Inserts only element at the end of list. If there are no element creates it.
*/

void	ft_list_pushback(t_list **list, int *nb, char letter)
{
	t_list *tmp;

	if (list && *list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(tmp, nb, letter);
	}
	else
	{
		tmp = *list;
		*list = ft_create_elem(tmp, nb, letter);
	}
}

/*
**Tanslate line of tetriminos received in binary number in an int[4]. Increments
**the corresponding letter.
*/

void	ft_get_tetri(char *buf, t_list **tetri)
{
	int			i;
	int			j;
	int			nb[4];
	static int	letter = 0;

	i = 0;
	j = 0;
	while (i < 20)
	{
		nb[j] = 0;
		while (((i + 1) % 5) != 0)
		{
			if (buf[i] == '#')
				nb[j] = nb[j] + (1 << (4 - (i + 1) % 5));
			i++;
		}
		i++;
		j++;
	}
	letter++;
	ft_list_pushback(tetri, nb, letter);
}
