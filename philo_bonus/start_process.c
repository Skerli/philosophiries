/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:19:28 by dcompreh          #+#    #+#             */
/*   Updated: 2022/06/27 13:49:05 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_in(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (time);
}

int	create_process(t_arg *arg, int i, t_philos *philo)
{
	arg->start = time_in();
	while (++i < arg->n_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			philo[i].start = arg->start;
			philo[i].time = arg->start;
			philo[i].id = i + 1;
			philo[i].must_eat = arg->n_of_eat;
			philo[i].time_eat = arg->time_to_eat;
			philo[i].time_sleep = arg->time_to_sleep;
			philo[i].time_to_die = arg->time_to_die;
			philo[i].fork = arg->fork;
			philo[i].check = arg->check;
			philo[i].bar = arg->bar;
			philo[i].exit = arg->exit;
			philo[i].one = arg->one;
			philo[i].n_eat = 0;
			pthread_create(&(philo[i].life), NULL, &algorithm, &philo[i]);
			check(&philo[i]);
			return (0);
		}
	}
	return (0);
}

int	start_process(t_arg *arg)
{
	int			i;
	t_philos	*philo;
	int			k;

	i = -1;
	k = 0;
	philo = malloc(sizeof(t_philos) * arg->n_philo);
	if (!philo)
		return (0);
	while (++i < arg->n_philo)
		sem_wait(arg->exit);
	i = -1;
	create_process(arg, i, philo);
	while (++i < arg->n_philo)
		sem_wait(arg->exit);
	i = -1;
	while (++i < arg->n_philo)
		kill(philo[i].pid, SIGTERM);
	free(philo);
	return (0);
}
