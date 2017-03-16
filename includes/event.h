/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:21:38 by bait-sli          #+#    #+#             */
/*   Updated: 2017/03/16 02:19:02 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H
# include "fdf.h"

# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_DOWN 125

# define KEY_ROT 7
# define KEY_ROT_Y 16

# define RESET 15

# define ADD_HEIGHT 84
# define RM_HEIGHT 83

# define KEY_ZOOM_IN 69
# define KEY_ZOOM_OUT 78

# define TETA 0.02
# define KEY_EXIT 53

# define LEFT 20
# define RIGHT 20
# define UP 20
# define DOWN 20

# define ZOOM_IN 2
# define ZOOM_OUT 1.9

t_newpos	new_pos_after_basic_move(t_newpos dot, int keycode);
t_newpos	new_pos_after_zoom(int sz, t_newpos dot, int key);
t_newpos	new_pos_after_rotation(int sz, t_newpos dot, int key);
t_newpos	add_size(int keycode, int size, t_newpos dot);
t_newpos	**get_pos_event_data(int endl, int
			size, t_newpos **data, int keycode);
t_newpos	initialisation(t_newpos dot);
void		reset_func(t_param *setup);

#endif
