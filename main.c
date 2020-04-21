/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguitar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:24:29 by auguitar          #+#    #+#             */
/*   Updated: 2019/10/10 22:24:32 by auguitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage(void)
{
	ft_putstr("give valid map\n");
	exit(0);
}

void	ft_free_all(t_struct *u)
{
	if (u)
		free(u);
}

int		close_fdf(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_struct	u;

	argc = 1;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		usage();
	}
	init_fdf(&u);
	ft_file_read(fd, &u);
	mlx_hook(u.win_ptr, 2, 2, deal_keys, &u);
	draw_fdf(&u);
	mlx_loop(u.mlx_ptr);
}
