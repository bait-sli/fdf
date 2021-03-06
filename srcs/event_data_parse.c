/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_data_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:33:12 by bait-sli          #+#    #+#             */
/*   Updated: 2017/03/16 02:26:25 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static t_newpos	*get_pos_event_endl(int size, t_newpos *data, int key)
{
	t_newpos	*ret;
	int			index;

	index = 0;
	ret = (t_newpos*)malloc(sizeof(t_newpos) * (size + 1));
	while (index < size)
	{
		if (key == KEY_RIGHT || key == KEY_LEFT ||
				key == KEY_UP || key == KEY_DOWN)
			ret[index] = new_pos_after_basic_move(data[index], key);
		if (key == ADD_HEIGHT || key == RM_HEIGHT)
			ret[index] = add_size(key, size, data[index]);
		if (key == KEY_ZOOM_IN || key == KEY_ZOOM_OUT)
			ret[index] = new_pos_after_zoom(size, data[index], key);
		if (key == KEY_ROT || key == KEY_ROT_Y)
			ret[index] = new_pos_after_rotation(size, data[index], key);
		index++;
	}
	return (ret);
}

t_newpos		**get_pos_event_data(int endl, int size,
		t_newpos **data, int key)
{
	t_newpos	**ret;
	int			index;

	index = 0;
	ret = (t_newpos**)malloc(sizeof(t_newpos*) * (endl + 1));
	while (index < endl)
	{
		ret[index] = get_pos_event_endl(size, data[index], key);
		index++;
	}
	return (ret);
}
