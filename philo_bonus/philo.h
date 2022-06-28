/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:40:35 by dcompreh          #+#    #+#             */
/*   Updated: 2022/06/24 14:15:40 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>	//SEM
# include <fcntl.h>		//SEM
# include <sys/stat.h> 	//SEM
# include <signal.h>

typedef struct s_arg
{
	int				*ate;
	long long		start;
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_of_eat;
	int				*eat_check;
	int				n_ph;
	sem_t			*one;
	sem_t			*fork;
	sem_t			*check;
	sem_t			*bar;
	sem_t			*message;
	sem_t			*eat;
	sem_t			*exit;
}	t_arg;

typedef struct s_philos
{
	t_arg			*arg;
	pthread_t		s1;
	int				id;
	int				must_eat;
	int				time_eat;
	int				time_sleep;
	int				solo;
	int				time_to_die;
	int				s_kill;
	int				s_dead;
	long long		start;
	int				s_eated;
	int				s_exit;
	long long		time;
	pthread_t		*threads;
	pthread_t		life;
	pid_t			pid;
	sem_t			*fork;
	sem_t			*check;
	sem_t			*bar;
	sem_t			*eat;
	sem_t			*message;
	sem_t			*exit;
	sem_t			*one;
	int				s;
	int				n_eat;
}	t_philos;

int			ft_atoi(const char *str);
int			init_all(char **argv, t_arg *arg);
long long	time_in(void);
int			start_process(t_arg *arg);
void		*algorithm(void *arg);
void		*check(t_philos *arg);
void		*check_is_dead(void *philo);
int			check_eat(t_philos *philo);
void		f_sleep(t_philos *philo, int i);
void		take_forks(t_philos *philo);
void		eating(t_philos *philo);
void		sleeping(t_philos *philo);
void		end_philo(t_arg *arg);
int			eat(t_philos *philo);

#endif