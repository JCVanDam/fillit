/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:38:57 by maxpetit          #+#    #+#             */
/*   Updated: 2016/05/16 16:03:23 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filit.h"

int		g_tetriminos;

void	ft_reverse(t_list *list)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (list->shape[j] == 3)
			list->shape[j] = 12;
		else if (list->shape[j] == 12)
			list->shape[j] = 3;
		if (list->shape[j] == 1)
			list->shape[j] = 8;
		else if (list->shape[j] == 8)
			list->shape[j] = 1;
		if (list->shape[j] == 7)
			list->shape[j] = 14;
		else if (list->shape[j] == 14)
			list->shape[j] = 7;
		if (list->shape[j] == 2)
			list->shape[j] = 4;
		else if (list->shape[j] == 4)
			list->shape[j] = 2;
		if (list->shape[j] == 0)
			list->shape[j] = 0;
		j++;
	}
}

/*
**Reverse the shape of all tetriminos in all element of list. Puts all
**of them in the top right corner.
*/

void	ft_list_organize(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		ft_reverse(tmp);
		ft_tetri_top(tmp, 0);
		ft_tetri_right(tmp, 0);
		tmp = tmp->next;
	}
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

/*
**Checks if there are two arguments and checks if the file is valid. Launch the
**list tetriminos creation with ft_list_organize, launch the researche of
**square with ft_extend and print the result.
*/

int		main(int argc, char **argv)
{
	int			map[SIZE - 1];
	t_list		*list;
	static int	size_tmp = 0;

	list = NULL;
	if (argc == 2)
	{
		if (!ft_checkfile(argv[1], &list))
		{
			g_tetriminos++;
			ft_list_organize(list);
			ft_extend(map, list, &size_tmp);
			ft_print_result(list, size_tmp);
			write(1, "\n", 1);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: filit source_file");
	return (0);
}
