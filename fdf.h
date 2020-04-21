/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguitar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:22:56 by auguitar          #+#    #+#             */
/*   Updated: 2019/10/11 01:03:44 by auguitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

# define BUF_SIZE 100
# define WIN_WIDTH 2000
# define WIN_HEIGHT 1200
# define BORDER_SIZE 60
# define MENU_RIGHT_BORDER 350
# define KEY_ESCAPE 0X35

typedef	struct	s_list_fdf
{
	char				**str;
	struct s_list_fdf	*next;
}				t_list_fdf;

typedef struct	s_elem
{
	int					x;
	int					y;
	struct s_elem		*next;
}				t_elem;

typedef struct	s_struct
{
	int					y1;
	int					z1;
	int					p_x1;
	int					p_x2;
	int					p_y1;
	int					p_y2;

	double				zoom;

	int					projection;
	int					check;

	double				isoc1;
	double				isoc2;

	int					nb_col;
	int					nb_lines;

	void				*mlx_ptr;
	void				*win_ptr;
	void				*img;
	int					**tab;

	int					parx1;
	int					pary1;
	int					parx2;
	int					pary2;
}				t_struct;

void			ft_file_read(int fd, t_struct *u);
void			init_fdf(t_struct *u);
t_struct		*tab_char_to_tab_int(int fd);
int				draw_fdf(t_struct *coor);
int				deal_keys(int key, t_struct *u);
void			usage(void);
int				close_fdf(void *param);
void			free_tab(void **tab);
t_list_fdf		*ft_lst_new(char **string);
void			ft_lst_add_last(t_list_fdf	**begin_list, t_list_fdf *new);
void			ft_lst_del(t_list_fdf **list);
int				count_cols(char **str);
int				ft_has_same_cols(t_list_fdf *list);
void			ft_copy_values(t_list_fdf *list, t_struct *u);
void			list_char_to_tab_int(t_list_fdf *list, t_struct *u);
void			free_string(char **str);
void			draw_hor(int x, int y, t_struct *u);
void			draw_ver(int x, int y, t_struct *u);
void			bresenham(t_struct *u);
void			ft_read_handle(t_list_fdf **list, char **string);
void			handle_all(t_list_fdf *list, char **string, int i, t_struct *u);

#endif
