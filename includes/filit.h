/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:41:42 by maxpetit          #+#    #+#             */
/*   Updated: 2016/05/16 15:49:07 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILIT_H
# define FILIT_H

# include "stdlib.h"
# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"
# include "unistd.h"
# include "stdio.h"

# define SIZE 32
# define BIG_INT 2147483647
# define PLACE 0
# define PASPLACE 1
# define LETTER 64
# define POINT 46

typedef struct		s_list
{
	int				shape[4];
	char			pos;
	int				ordonnee;
	int				size;
	int				option;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

int					ft_initialize_list(t_list *list);
void				ft_printusage();
int					ft_checklen(char *buf, int *i);
int					ft_checkblock(char *buf, int i);
int					ft_checkpattern(char *buf, int i);
int					ft_checkcontact(char *buf, char c);
int					ft_checkfile(char *file, t_list **list);
void				ft_putstr(char *str);
void				ft_get_tetri(char *buf, t_list **list);
int					ft_root(int nb);
int					*ft_create_map(int *map, int i);
t_list				*ft_create_elem(t_list *list, int *nb, char letter);
int					ft_power(int nb, int power);
void				ft_create_submap(int *map, int *cut_map, int *size_tmp);
int					ft_fill(int *map, t_list *list, int cut_map, int size_tmp);
int					ft_tetri_size(t_list *list);
int					ft_mv_tetri(t_list *list, int size_tmp);
int					ft_check_placable(int *map, t_list *list, int i);
int					ft_place_tetri(int *map, t_list *list, int size_tmp,
					int cut_map);
int					ft_check_insubmap(t_list *list, int size_tmp);
void				ft_mapinitialize(int **map, int *cut_map, int *size_tmp);
void				ft_tetri_top(t_list *list, int y);
void				ft_tetri_right(t_list *list, int y);
void				ft_tetri_left(t_list *list);
void				ft_print_map(int *map);
void				ft_print_list(t_list *list);
int					ft_check_cmp(int *map, t_list *list);
void				ft_initialize_map(int *map, t_list *list);
int					ft_extend(int *map, t_list *list, int *size_tmp);
int					ft_check_place(t_list *list);
void				ft_list_organize(t_list *list);
int					ft_print_result(t_list *list, int size_tmp);
void				ft_print_str(char *res, int size_tmp, int i);
void				print_list(t_list *list);
void				print(int *map);
int					ft_insert_tetri(int	*map, t_list *list);
void				ft_initialize_tetri(t_list *list);

#endif
