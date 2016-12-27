/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 10:19:26 by maxpetit          #+#    #+#             */
/*   Updated: 2016/05/16 16:17:09 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filit.h"

int		ft_len_line(char *res)
{
	int i;

	i = 0;
	while (res[i] != '\n')
		i++;
	return (i);
}

void	ft_print_str(char *res, int size_tmp, int i)
{
	int j;
	int k;

	while (res[i])
	{
		j = ft_len_line(res);
		while (res[i] != '\n')
			i++;
		k = i;
		while (j >= 0)
		{
			if (i != size_tmp)
				write(1, &res[i], 1);
			i--;
			j--;
		}
		i = ++k;
	}
}

char	*ft_create_tab(int size_tmp, int i)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) *
					((size_tmp * size_tmp) + size_tmp))))
		return (NULL);
	while (i < ((size_tmp * size_tmp) + size_tmp))
	{
		if (((i + 1) % (size_tmp + 1)) == 0)
			res[i] = '\n';
		else
			res[i] = POINT;
		i++;
	}
	return (res);
}

void	ft_loop(t_list *list, char *res, int size_tmp, int j)
{
	int cmp;
	int i;

	i = size_tmp;
	while (j < list->size)
	{
		cmp = 1;
		while (cmp < ft_power(2, size_tmp))
		{
			if ((list->shape[j] & cmp) != 0)
			{
				list->shape[j] = list->shape[j] ^ cmp;
				res[((((list->ordonnee) + j) *
							(size_tmp + 1)) + i) - 1] = list->pos + LETTER;
			}
			i--;
			cmp = cmp << 1;
		}
		i = size_tmp;
		j++;
	}
}

int		ft_print_result(t_list *list, int size_tmp)
{
	char	*res;
	int		j;

	j = 0;
	res = NULL;
	if (!ft_create_tab(size_tmp, j))
		return (0);
	else
		res = ft_create_tab(size_tmp, j);
	while (list)
	{
		ft_loop(list, res, size_tmp, j);
		list = list->next;
	}
	res[(size_tmp * size_tmp) + size_tmp] = '\0';
	j = 0;
	ft_print_str(res, size_tmp, j);
	return (0);
}
