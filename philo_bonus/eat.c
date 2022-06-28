/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:35:36 by dcompreh          #+#    #+#             */
/*   Updated: 2022/06/27 13:50:03 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philos *philo)
{
	sem_wait(philo->fork);
	sem_wait(philo->one);
	printf("%llu %d has taken a fork\n", (time_in() - philo->start), philo->id);
	sem_post(philo->one);
	sem_wait(philo->fork);
	sem_wait(philo->one);
	printf("%llu %d has taken a fork\n", (time_in() - philo->start), philo->id);
	sem_post(philo->one);
	return (0);
}

int	eat(t_philos *philo)
{
	take_fork(philo);
	sem_wait(philo->one);
	printf("%llu %d is eating\n", (time_in() - philo->start), philo->id);
	philo->time = time_in();
	sem_post(philo->one);
	f_sleep(philo, 1);
	sem_wait(philo->one);
	philo->n_eat++;
	if (philo->n_eat == philo->must_eat)
		sem_post(philo->exit);
	sem_post(philo->one);
	sem_wait(philo->one);
	sem_post(philo->one);
	sem_post(philo->fork);
	sem_post(philo->fork);
	return (0);
}
