/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:52:58 by dcompreh          #+#    #+#             */
/*   Updated: 2022/06/22 15:53:13 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_sleep(t_philos *philo, int i)
{
	long long	t;

	t = time_in();
	while (i == 1 && (time_in() - t) < philo->time_eat)
		usleep(100);
	while (i == 2 && (time_in() - t) < philo->time_sleep)
		usleep(100);
	while (i == 3 && (time_in() - t) < philo->time_to_die)
		usleep(100);
}
