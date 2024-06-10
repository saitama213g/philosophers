/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:15:21 by aet-tale          #+#    #+#             */
/*   Updated: 2023/12/22 12:35:29 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptrbyte1;
	const unsigned char	*ptrbyte2;
	size_t				i;

	if (dst == src)
		return (dst);
	i = 0;
	ptrbyte1 = dst;
	ptrbyte2 = src;
	while (i < n)
	{
		ptrbyte1[i] = ptrbyte2[i];
		i++;
	}
	return (dst);
}
