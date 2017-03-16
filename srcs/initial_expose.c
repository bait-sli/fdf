/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_expose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 03:17:20 by bait-sli          #+#    #+#             */
/*   Updated: 2017/03/16 03:17:22 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_newpos		dot_in_win(int size, t_point dot)
{
	t_newpos		ret;

	ret.rx = dot.x;
	ret.ry = dot.y;
	ret.rz = dot.z;
	ret.new_pos_x = INIT_X + ((SUB_WIDTH / (size - 1)) * dot.x);
	ret.new_pos_y = INIT_Y + ((SUB_HEIGHT / (size - 1)) * dot.y) - ((SUB_HEIGHT
				/ (size - 1)) * dot.z);
	ret.new_init_x = INIT_X;
	ret.new_init_y = INIT_Y;
	ret.new_sub_widht = SUB_WIDTH;
	ret.new_sub_height = SUB_HEIGHT;
	ret.grid = INIT_GRID;
	return (ret);
}

static t_newpos		*get_pos_endl(int size, t_point *data)
{
	t_newpos		*ret;
	int				index;

	index = 0;
	ret = ft_memalloc(sizeof(t_newpos*) * (size + 11500));
	while (index < size)
	{
		ret[index] = dot_in_win(size, data[index]);
		index++;
	}
	return (ret);
}

t_newpos			**get_pos_data(int endl, int size, t_point **data)
{
	t_newpos		**ret;
	int				index;

	index = 0;
	ret = ft_memalloc(sizeof(t_newpos**) * (endl + 15500));
	while (index < endl)
	{
		ret[index] = get_pos_endl(size, data[index]);
		index++;
	}
	return (ret);
}
