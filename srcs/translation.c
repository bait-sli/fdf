/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 03:18:25 by bait-sli          #+#    #+#             */
/*   Updated: 2017/03/16 03:18:29 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

t_newpos		new_pos_after_basic_move(t_newpos dot, int keycode)
{
	t_newpos	ret;

	ret = initialisation(dot);
	if (keycode == KEY_RIGHT)
	{
		ret.new_pos_x = dot.new_pos_x + RIGHT;
		ret.new_init_x = dot.new_init_x + RIGHT;
	}
	if (keycode == KEY_LEFT)
	{
		ret.new_pos_x = dot.new_pos_x - LEFT;
		ret.new_init_x = dot.new_init_x - LEFT;
	}
	if (keycode == KEY_UP)
	{
		ret.new_pos_y = dot.new_pos_y - UP;
		ret.new_init_y = dot.new_init_y - UP;
	}
	if (keycode == KEY_DOWN)
	{
		ret.new_pos_y = dot.new_pos_y + DOWN;
		ret.new_init_y = dot.new_init_y + DOWN;
	}
	return (ret);
}
