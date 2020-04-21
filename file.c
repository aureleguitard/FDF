/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguitar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:23:09 by auguitar          #+#    #+#             */
/*   Updated: 2019/10/11 01:06:19 by auguitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_fdf(t_struct *u)
{
	u->tab = NULL;
	u->nb_col = 0;
	u->nb_lines = 0;
	u->y1 = 0;
	u->z1 = 0;
	u->isoc1 = cos(0.523599);
	u->isoc2 = sin(0.523599);
	u->projection = 1;
	u->p_x1 = 0;
	u->p_x2 = 0;
	u->p_y1 = 0;
	u->p_y2 = 0;
	u->zoom = 30;
	u->check = 0;
	if (!(u->mlx_ptr = mlx_init()))
		exit(0);
	if (!(u->win_ptr = mlx_new_window(u->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
		"fdf AURSAL")))
		exit(0);
}

void		handle_all(t_list_fdf *list, char **string, int i, t_struct *u)
{
	u->nb_lines = i;
	u->nb_col = ft_has_same_cols(list);
	list_char_to_tab_int(list, u);
	free_string(string);
	ft_lst_del(&list);
}

void		ft_read_handle(t_list_fdf **list, char **string)
{
	t_list_fdf *new;

	if (!*list)
	{
		if (!(*list = ft_lst_new(string)))
		{
			free_string(string);
			exit(0);
		}
	}
	else
	{
		if (!(new = ft_lst_new(string)))
		{
			free_string(string);
			ft_lst_del(list);
			exit(0);
		}
		ft_lst_add_last(list, new);
	}
}

void		ft_file_read(int fd, t_struct *u)
{
	int			i;
	char		*line;
	t_list_fdf	*list;
	char		**string;

	i = 0;
	list = NULL;
	while (get_next_line(fd, &line))
	{
		if (*line < 1)
			usage();
		if (!(string = ft_strsplit(line, ' ')))
			return ;
		free(line);
		ft_read_handle(&list, string);
		i++;
	}
	handle_all(list, string, i, u);
}

int			deal_keys(int key, t_struct *u)
{
	if (key == KEY_ESCAPE)
		exit(0);
	u->check = 1;
	return (0);
}
