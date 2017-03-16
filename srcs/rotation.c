/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:10:32 by bait-sli          #+#    #+#             */
/*   Updated: 2017/03/10 21:45:38 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static t_newpos	about_x(int sz, t_newpos dot)
{
	t_newpos	ret;

	ret = initialisation(dot);
	ret.rx = dot.rx;
	ret.ry = dot.ry * cos(TETA) - dot.rz * sin(TETA);
	ret.rz = dot.ry * sin(TETA) + dot.rz * cos(TETA);
	ret.new_pos_x = dot.new_init_x + ((dot.new_sub_widht / (sz - 1)) * dot.rx);
	ret.new_pos_y = dot.new_init_y + ((dot.new_sub_height / (sz - 1)) *
			ret.ry) - (((dot.new_sub_height / (sz - 1))) * dot.grid * ret.rz);
	ret.new_init_x = dot.new_init_x;
	ret.new_init_y = dot.new_init_y;
	ret.new_sub_widht = dot.new_sub_widht;
	ret.new_sub_height = dot.new_sub_height;
	return (ret);
}

static t_newpos	about_y(int sz, t_newpos dot)
{
	t_newpos	ret;

	ret = initialisation(dot);
	ret.rx = dot.rx * cos(TETA) + dot.rz * sin(TETA);
	ret.ry = dot.ry;
	ret.rz = -dot.rx * sin(TETA) + dot.rz * cos(TETA);
	ret.new_pos_x = dot.new_init_x + ((dot.new_sub_widht / (sz - 1)) * ret.rx);
	ret.new_pos_y = dot.new_init_y + ((dot.new_sub_height / (sz - 1)) *
			ret.ry) - ((dot.new_sub_height / (sz - 1)) * dot.grid * (ret.rz));
	ret.new_init_x = dot.new_init_x;
	ret.new_init_y = dot.new_init_y;
	ret.new_sub_widht = dot.new_sub_widht;
	ret.new_sub_height = dot.new_sub_height;
	return (ret);
}

t_newpos		new_pos_after_rotation(int sz, t_newpos dot, int key)
{
	return ((key == KEY_ROT) ? about_x(sz, dot) : about_y(sz, dot));
}
