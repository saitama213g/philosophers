/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:31:39 by aet-tale          #+#    #+#             */
/*   Updated: 2023/12/21 16:50:43 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*byt;

	i = 0;
	byt = (unsigned char *)s;
	while (i < n)
	{
		if (*byt == (unsigned char)c)
			return (byt);
		byt++;
		i++;
	}
	return (NULL);
}
