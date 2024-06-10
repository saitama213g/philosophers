/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:05:14 by aet-tale          #+#    #+#             */
/*   Updated: 2023/12/18 11:14:35 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptrbyte;
	size_t			i;

	i = 0;
	ptrbyte = s;
	while (i < n)
	{
		ptrbyte[i] = '\0';
		i++;
	}
}
