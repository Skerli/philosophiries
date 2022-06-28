/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:40:39 by dcompreh          #+#    #+#             */
/*   Updated: 2022/06/23 18:39:44 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg		arg;
	int			i;

	i = -1;
	if (argc != 5 && argc != 6)
		return (printf(
				"\e[1;91mERROR:\033[0m	not enough or too much arguments\n"));
	if (init_all(argv, &arg))
		return (1);
	arg.ate = malloc(sizeof(int) * arg.n_philo);
	start_process(&arg);
	end_philo(&arg);
}
