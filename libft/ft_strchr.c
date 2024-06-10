/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:03:18 by aet-tale          #+#    #+#             */
/*   Updated: 2024/04/21 17:09:24 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *s, int c)
{
	int	l;
	int	i;

	l = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	// printf("%s\n", ft_strchr("hello\n", '\n'));

// 	if (ft_strchr("hello \n", '\n'))
// 	{
// 		printf("hello");
// 	}
// }