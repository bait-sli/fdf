/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_controler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:47:24 by bait-sli          #+#    #+#             */
/*   Updated: 2017/03/10 21:33:13 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

t_newpos		add_size(int keycode, int size, t_newpos dot)
{
	t_newpos	ret;

	ret = initialisation(dot);
	if (keycode == ADD_HEIGHT)
		ret.grid = dot.grid * 1.3;
	if (keycode == RM_HEIGHT)
		ret.grid = ret.grid * 0.80;
	ret.new_pos_y = ret.new_init_y + (ret.new_sub_height / (size - 1) * ret.ry)
		- ((ret.new_sub_height / (size - 1)) * ret.grid * ret.rz);
	return (ret);
}
