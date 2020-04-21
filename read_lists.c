/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguitar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:25:35 by auguitar          #+#    #+#             */
/*   Updated: 2019/10/10 22:25:37 by auguitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			count_cols(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_has_same_cols(t_list_fdf *list)
{
	int j;
	int first_col;

	j = 0;
	first_col = count_cols(list->str);
	while (list)
	{
		j = count_cols(list->str);
		if (j != first_col)
		{
			ft_lst_del(&list);
			usage();
		}
		list = list->next;
	}
	return (first_col);
}

void		ft_copy_values(t_list_fdf *list, t_struct *u)
{
	int i;
	int j;

	i = 0;
	while (list && i < u->nb_lines)
	{
		j = 0;
		while (j < u->nb_col)
		{
			u->tab[i][j] = ft_atoi(list->str[j]);
			j++;
		}
		list = list->next;
		i++;
	}
}

void		list_char_to_tab_int(t_list_fdf *list, t_struct *u)
{
	int i;

	if (!(u->tab = (int**)malloc(sizeof(int*) * u->nb_lines)))
	{
		ft_lst_del(&list);
		return ;
	}
	i = 0;
	while (i < u->nb_lines)
	{
		if (!(u->tab[i] = (int*)malloc(sizeof(int) * u->nb_col)))
		{
			free_tab((void**)u->tab);
			ft_lst_del(&list);
			exit(0);
		}
		i++;
	}
	ft_copy_values(list, u);
}

void		free_string(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
