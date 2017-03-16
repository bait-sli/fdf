/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:36:33 by bait-sli          #+#    #+#             */
/*   Updated: 2017/03/16 02:25:17 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*get_line(int size, int index, int *alpha)
{
	t_point		*nbr;
	int			i;

	i = 0;
	nbr = (t_point*)malloc(sizeof(t_point) * (size + 1));
	while (i < size - 1)
	{
		nbr[i].x = i;
		nbr[i].y = index;
		nbr[i].z = alpha[i];
		i++;
	}
	return (nbr);
}

t_point			**get_map(int endl, int len, int **alpha)
{
	t_point		**ret;
	int			index;

	index = 0;
	ret = (t_point**)malloc(sizeof(t_point*) * (endl + 1));
	while (index < endl)
	{
		ret[index] = get_line(len, index, alpha[index]);
		index++;
	}
	return (ret);
}
