/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:34:16 by dcompreh          #+#    #+#             */
/*   Updated: 2022/06/27 13:41:52 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check(t_philos *philo)
{
	int	i;

	i = -1;
	while (1)
	{
		sem_wait(philo->one);
		if (time_in() - philo->time > philo->time_to_die)
		{
			sem_post(philo->one);
			sem_wait(philo->one);
			printf("%lld %d died\n", time_in() - philo->time, \
				philo->id);
			while (1)
				sem_post(philo->exit);
		}
		sem_post(philo->one);
	}
	return (0);
}

void	*algorithm(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (1)
	{
		eat(philo);
		sem_wait(philo->one);
		printf("%llu %d is sleeping\n",
			(time_in() - philo->start), philo->id);
		sem_post(philo->one);
		f_sleep(philo, 2);
		sem_wait(philo->one);
		printf("%llu %d is thinking\n",
			(time_in() - philo->start), philo->id);
		sem_post(philo->one);
	}
}

// printf("\n->>>philo %d: \t %d %d\n\n", philo->id,
// 			philo->arg->ate[i], philo->arg->n_of_eat);