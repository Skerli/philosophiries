/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:10:11 by dcompreh          #+#    #+#             */
/*   Updated: 2022/06/22 16:14:53 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_philo(t_arg *arg)
{
	sem_unlink("/sem_fork");
	sem_unlink("/sem_check");
	sem_unlink("/sem_message");
	sem_close(arg->fork);
	sem_close(arg->check);
	sem_close(arg->bar);
	return ;
}
