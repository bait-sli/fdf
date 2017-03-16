/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 03:15:38 by bait-sli          #+#    #+#             */
/*   Updated: 2017/03/16 03:15:45 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	find_pos(char *str, char ptr)
{
	int		i;

	i = 0;
	while ((unsigned int)i < ft_strlen(str))
	{
		if (!(str[i] == ptr))
			i++;
		if (str[i] == ptr)
		{
			break ;
			return (i);
		}
	}
	return (i);
}

char		*clean_str(char *str)
{
	char	*ret;
	char	*ptr;

	ptr = NULL;
	if (!(ptr = ft_strchr((const char*)str, ',')))
		ret = "0x000000";
	else
		ret = ft_strsub((const char*)str, (find_pos(str, ',') + 1),
				ft_strlen(str));
	return (ret);
}

char		*remove_prefix(char *str)
{
	char	*ret;
	char	*ptr;

	ptr = NULL;
	if (!(ptr = ft_strchr((const char*)str, 'x')) ||
			find_pos(str, 'x') != 1 || str[0] != '0')
		return (str);
	else
	{
		ret = ft_strsub((const char*)str, 2, ft_strlen(str));
		return (ret);
	}
	return (NULL);
}
