/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:15:09 by bait-sli          #+#    #+#             */
/*   Updated: 2017/03/16 02:06:01 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/uio.h>

# define WIDHT 1900
# define HEIGHT 1080

# define INIT_GRID 1

# define SUB_WIDTH 1500
# define SUB_HEIGHT 860
# define COLOR1 "A327FF"
# define COLOR2 "FC27FF"
# define COLOR3 "FFD827"
# define COLOR4 "FF7719"

# define INIT_X 200
# define INIT_Y 110

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_image
{
	int				bpp;
	int				endian;
	int				sizeline;
	void			*img_ptr;
	char			*data;
}					t_image;

typedef struct		s_draw
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					t_draw;

typedef struct		s_newpos
{
	float			rx;
	float			ry;
	float			rz;
	int				new_pos_x;
	int				new_pos_y;
	float			new_init_x;
	float			new_init_y;
	float			new_sub_widht;
	float			new_sub_height;
	float			grid;
}					t_newpos;

typedef struct		s_param
{
	char			**ret;
	int				endl;
	int				len;
	void			*mlx;
	void			*window;
	int				**nbr;
	t_point			**dot;
	t_image			pict;
	t_newpos		**stock;
	unsigned long	**color;
}					t_param;

void				print_menu(void *mlx, void *win);
char				**read_file(char *file);
int					size_line(char *str);
int					check_file(char **stock);
int					nb_line(char **stock);
int					**ft_getdata(int endl, int size, char **stock);
t_point				**get_map(int endl, int len, int **alpha);
t_newpos			**get_pos_data(int endl, int size, t_point **data);
void				print_map(t_param *s, unsigned long **color,
						t_newpos **data);
int					ft_atoi_base(char *str, int base);
unsigned long		**get_color_data(int endl, int size, t_point **alpha,
						char **stock);
char				*clean_str(char *str);
char				*remove_prefix(char *str);
void				put_pixel(t_param *s, unsigned long color, int x, int y);

#endif
