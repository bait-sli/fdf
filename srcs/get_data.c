/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 03:16:52 by bait-sli          #+#    #+#             */
/*   Updated: 2017/03/16 05:45:05 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*ft_getnbr(int size, char *str)
{
	char			**ret;
	int				*nbr;
	int				count;

	count = 0;
	ret = ft_strsplit(str, ' ');
	nbr = (int*)malloc(sizeof(int) * size + 1);
	while (count < size)
	{
		nbr[count] = ft_atoi(ret[count]);
		count++;
	}
	return (nbr);
}

int			**ft_getdata(int endl, int size, char **stock)
{
	int		**ret;
	int		index;

	index = 0;
	ret = (int**)malloc(sizeof(int*) * (endl + 1));
	while (index < endl)
	{
		ret[index] = ft_getnbr(size, *stock);
		index++;
		stock++;
	}
	return (ret);
}
