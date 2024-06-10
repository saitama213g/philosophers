/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:18:32 by aet-tale          #+#    #+#             */
/*   Updated: 2023/12/23 19:41:18 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_inset(char c, char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		l;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	l = ft_strlen(s1);
	while (s1[i] && str_inset(s1[i], (char *)set))
		i++;
	while (l > i && str_inset(s1[l - 1], (char *)set))
		l--;
	str = malloc(sizeof(char) * (l - i + 1));
	if (!str)
		return (NULL);
	while (i + j < l)
	{
		str[j] = s1[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
