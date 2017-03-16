/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:39:09 by bait-sli          #+#    #+#             */
/*   Updated: 2017/03/16 02:27:44 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned long	*ft_getnbr_color(int size, t_point *alpha, char *str)
{
	char				**ret;
	unsigned long		*nbr;
	int					count;

	count = 0;
	ret = ft_strsplit(str, ' ');
	nbr = (unsigned long*)malloc(sizeof(unsigned long) * (size + 1));
	while (count < size)
	{
		nbr[count] = ft_atoi_base(remove_prefix(clean_str(ret[count])), 16);
		if (nbr[count] == 0)
		{
			if (alpha[count].z <= 4)
				nbr[count] = ft_atoi_base(COLOR1, 16);
			else if (alpha[count].z >= 5 && alpha[count].z <= 8)
				nbr[count] = ft_atoi_base(COLOR2, 16);
			else if (alpha[count].z >= 9 && alpha[count].z <= 14)
				nbr[count] = ft_atoi_base(COLOR3, 16);
			else
				nbr[count] = ft_atoi_base(COLOR4, 16);
		}
		count++;
	}
	return (nbr);
}

unsigned long			**get_color_data(int endl, int size,
		t_point **alpha, char **stock)
{
	unsigned long		**ret;
	int					index;

	index = 0;
	ret = (unsigned long**)malloc(sizeof(unsigned long*) * (endl + 1));
	while (index < endl)
	{
		ret[index] = ft_getnbr_color(size, *alpha, *stock);
		index++;
		stock++;
		alpha++;
	}
	return (ret);
}
