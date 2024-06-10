/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:45:00 by aet-tale          #+#    #+#             */
/*   Updated: 2023/12/18 11:39:17 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *)s1;
	s = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 1;
	while (*s == *f && i < n)
	{
		s++;
		f++;
		i++;
	}
	return (*f - *s);
}
