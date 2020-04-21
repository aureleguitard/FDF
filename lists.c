/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguitar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:24:00 by auguitar          #+#    #+#             */
/*   Updated: 2019/10/11 01:06:30 by auguitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_tab(void **tab)
{
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	tab = NULL;
}

t_list_fdf	*ft_lst_new(char **string)
{
	t_list_fdf	*new;

	if (!(new = (t_list_fdf *)malloc(sizeof(t_list_fdf))))
	{
		free_tab((void **)string);
		return (NULL);
	}
	new->str = string;
	new->next = NULL;
	return (new);
}

void		ft_lst_add_last(t_list_fdf **begin_list, t_list_fdf *new)
{
	t_list_fdf	*tmp;

	if (*begin_list && new)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		ft_lst_del(t_list_fdf **list)
{
	t_list_fdf	*next;

	if (*list)
	{
		while ((*list)->next)
		{
			next = (*list)->next;
			free_string((*list)->str);
			free(*list);
			*list = next;
		}
		free(*list);
	}
}
