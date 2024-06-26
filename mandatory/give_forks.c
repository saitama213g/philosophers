/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:52:24 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/26 12:19:05 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	give_forks(t_philo_s *philos, pthread_mutex_t *forks, int philos_nmbr)
{
	int i = 0;

	while (i < philos_nmbr)
	{
		philos->fork1 = &forks[i];
		philos->fork2 = &forks[(i+1)%5];
		i++;
		philos++;
	}
}
