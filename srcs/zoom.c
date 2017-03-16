/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:27:48 by bait-sli          #+#    #+#             */
/*   Updated: 2017/03/16 03:58:18 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static t_newpos	zoom_in(int sz, t_newpos dot)
{
	t_newpos	ret;

	ret = initialisation(dot);
	ret.new_sub_widht = dot.new_sub_widht * 1.1;
	ret.new_sub_height = dot.new_sub_height * 1.1;
	ret.new_pos_x = ret.new_init_x + ((ret.new_sub_widht / (sz - 1)) * dot.rx);
	ret.new_pos_y = ret.new_init_y + ((ret.new_sub_height / (sz - 1)) *
			dot.ry) - ((ret.new_sub_height / (sz - 1) * dot.grid) * dot.rz);
	return (ret);
}

static t_newpos	zoom_out(int sz, t_newpos dot)
{
	t_newpos	ret;

	ret = initialisation(dot);
	ret.new_sub_widht = dot.new_sub_widht * 0.70;
	ret.new_sub_height = dot.new_sub_height * 0.70;
	ret.new_pos_x = ret.new_init_x + ((ret.new_sub_widht / (sz - 1)) * dot.rx);
	ret.new_pos_y = ret.new_init_y + ((ret.new_sub_height / (sz - 1)) *
			dot.ry) - ((ret.new_sub_height / (sz - 1) * dot.grid) * dot.rz);
	return (ret);
}

t_newpos		new_pos_after_zoom(int sz, t_newpos dot, int key)
{
	return ((key == KEY_ZOOM_IN) ? zoom_in(sz, dot) : zoom_out(sz, dot));
}
