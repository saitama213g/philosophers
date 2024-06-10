/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:05:24 by aet-tale          #+#    #+#             */
/*   Updated: 2024/06/10 11:16:58 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct t_data
{
	int		philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		eating_number;
}t_data;
int	ft_atoi(char *s);
int	ft_isdigit(int c);

# endif