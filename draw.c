/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguitar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:24:16 by auguitar          #+#    #+#             */
/*   Updated: 2019/10/10 22:24:18 by auguitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		initialize_points_zoom(t_struct *u, int x, int y, int index)
{
	if (index == 0)
	{
		u->p_x1 = x * u->zoom;
		u->p_x2 = (x + 1) * u->zoom;
		u->p_y1 = y * u->zoom;
		u->p_y2 = y * u->zoom;
	}
	if (index == 1)
	{
		u->p_x1 = x * u->zoom;
		u->p_x2 = x * u->zoom;
		u->p_y1 = y * u->zoom;
		u->p_y2 = (y + 1) * u->zoom;
	}
}

void		get_par_view(t_struct *u, int x, int y, int index)
{
	if (index == 0)
	{
		initialize_points_zoom(u, x, y, 0);
		u->parx1 = (u->p_x1 + u->zoom * -(u->tab[y][x] / 10));
		u->pary1 = (u->p_y1 + (u->zoom) * -(u->tab[y][x] / 10));
		u->parx2 = ((u->p_x2) + u->zoom * -(u->tab[y][x + 1] / 10));
		u->pary2 = (u->p_y1 + (u->zoom) * -(u->tab[y][x + 1] / 10));
	}
	else if (index == 1)
	{
		initialize_points_zoom(u, x, y, 1);
		u->parx1 = (u->p_x1 + u->zoom * -(u->tab[y][x] / 10));
		u->pary1 = (u->p_y1 + (u->zoom) * -(u->tab[y][x] / 10));
		u->parx2 = (u->p_x2 + u->zoom * -(u->tab[y + 1][x] / 10));
		u->pary2 = ((u->p_y2) + (u->zoom) * -(u->tab[y + 1][x] / 10));
	}
}

void		get_iso_view(t_struct *u, int x, int y, int index)
{
	if (index == 0)
	{
		initialize_points_zoom(u, x, y, 0);
		u->parx1 = (u->isoc1 * u->p_x1) - (u->isoc1 * u->p_y1);
		u->pary1 = -(u->tab[y][x]) + (u->isoc1 / 2) * u->p_x1 +
			(u->isoc1 / 2) * u->p_y1;
		u->parx2 = (u->isoc1 * u->p_x2) - (u->isoc1 * u->p_y2);
		u->pary2 = -(u->tab[y][x + 1]) + (u->isoc1 / 2) * u->p_x2 +
			(u->isoc1 / 2) * u->p_y2;
	}
	else if (index == 1)
	{
		initialize_points_zoom(u, x, y, 1);
		u->parx1 = (u->isoc1 * u->p_x1) - (u->isoc1 * u->p_y1);
		u->pary1 = -(u->tab[y][x]) + (u->isoc1 / 2) * u->p_x1 +
			(u->isoc1 / 2) * u->p_y1;
		u->parx2 = (u->isoc1 * u->p_x2) - (u->isoc1 * u->p_y2);
		u->pary2 = -(u->tab[y + 1][x]) + (u->isoc1 / 2) * u->p_x2 +
			(u->isoc1 / 2) * u->p_y2;
	}
}

void		draw_hor(int x, int y, t_struct *u)
{
	if (u->projection == 2 || u->projection == 4)
		get_par_view(u, x, y, 0);
	else if (u->projection == 1 || u->projection == 3)
		get_iso_view(u, x, y, 0);
	u->parx1 += ((WIN_WIDTH - MENU_RIGHT_BORDER) / 2);
	u->pary1 += ((WIN_HEIGHT - BORDER_SIZE) / 2);
	u->parx2 += ((WIN_WIDTH - MENU_RIGHT_BORDER) / 2);
	u->pary2 += ((WIN_HEIGHT - BORDER_SIZE) / 2);
	bresenham(u);
}

void		draw_ver(int x, int y, t_struct *u)
{
	if (u->projection == 2 || u->projection == 4)
		get_par_view(u, x, y, 1);
	else if (u->projection == 1 || u->projection == 3)
		get_iso_view(u, x, y, 1);
	u->parx1 += ((WIN_WIDTH - MENU_RIGHT_BORDER) / 2);
	u->pary1 += ((WIN_HEIGHT - BORDER_SIZE) / 2);
	u->parx2 += ((WIN_WIDTH - MENU_RIGHT_BORDER) / 2);
	u->pary2 += ((WIN_HEIGHT - BORDER_SIZE) / 2);
	bresenham(u);
}
