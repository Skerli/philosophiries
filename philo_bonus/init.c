/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:14:57 by dcompreh          #+#    #+#             */
/*   Updated: 2022/06/24 14:13:52 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_sem(t_arg *arg)
{
	sem_unlink("/sem_fork");
	sem_unlink("/sem_check");
	sem_unlink("/sem_message");
	sem_unlink("/sem_bar");
	sem_unlink("/sem_exit");
	sem_unlink("/sem_1");
	arg->fork = sem_open("/sem_fork", O_CREAT, 0, arg->n_philo);
	arg->check = sem_open("/sem_check", O_CREAT, 0, 1);
	arg->bar = sem_open("/sem_bar", O_CREAT, 0, 0);
	arg->message = sem_open("/sem_message", O_CREAT, 0, 1);
	arg->exit = sem_open("/sem_exit", O_CREAT, 0, arg->n_philo);
	arg->one = sem_open("/sem_1", O_CREAT, 0, 1);
	return (0);
}

int	init_all(char **argv, t_arg *arg)
{
	arg->n_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (arg->n_philo < 1 || arg->time_to_eat <= 0 || arg->time_to_die <= 0
		|| arg->time_to_sleep <= 0)
		return (printf("\e[1;91mERROR:\033[0m invalid arguments\n"));
	if (argv[5])
	{
		arg->n_of_eat = ft_atoi(argv[5]);
		if (arg->n_of_eat <= 0)
			return (printf("\e[1;91mERROR:\033[0m invalid arguments (n_eat)\n"));
	}
	else
		arg->n_of_eat = -1;
	return (init_sem(arg));
}

// sem_t *sem_open(const char *name, int oflag,
// 		mode_t mode, unsigned int value);
// - создает семофор (название,флаг, 0 не используем, и кол-во)
// sem_unlink(char *name); - удаляет семафор названный именем
