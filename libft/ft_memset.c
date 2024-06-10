/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:31:22 by aet-tale          #+#    #+#             */
/*   Updated: 2023/12/22 19:49:14 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptrbyte1;

	ptrbyte1 = (unsigned char *)b;
	while (len)
	{
		*ptrbyte1++ = (unsigned char)c;
		len--;
	}
	return (b);
}
