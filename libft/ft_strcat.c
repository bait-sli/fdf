/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:20:40 by bait-sli          #+#    #+#             */
/*   Updated: 2016/11/18 19:36:26 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	char	*cur1;
	char	*cur2;

	cur1 = s1;
	cur2 = (char *)s2;
	while (*cur1 != '\0')
	{
		cur1++;
	}
	while (*cur2 != '\0')
	{
		*cur1 = *cur2;
		cur1++;
		cur2++;
	}
	*cur1 = '\0';
	return (s1);
}
