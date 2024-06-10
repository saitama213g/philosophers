/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:54:47 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/07 15:59:00 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int		counter = 0;

void	*increment(void *arg)
{
	counter++;
	printf("thread %i\n", counter);
	return (NULL);
}

int	main(int ac, char **av)
{
	return (0);
}