/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:31:11 by cfleuret          #+#    #+#             */
/*   Updated: 2025/02/27 15:59:02 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	begin(t_program *prog)
{
	int	running;

	pthread_mutex_lock(&prog->starting_lock);
	running = prog->starting;
	pthread_mutex_unlock(&prog->starting_lock);
	return (running);
}

void	set_starting(t_program *prog, int running)
{
	pthread_mutex_lock(&prog->starting_lock);
	prog->starting = running;
	pthread_mutex_unlock(&prog->starting_lock);
}

void	cannot_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	printf("%zu philo %d took his left fork\n",
		get_current_time(), philo->id);
	ft_usleep(philo->time_to_die);
	philo->dead = 1;
	philo->prog->dead_flag = 1;
	printf("%zu philo %d DIED NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n",
		get_current_time(), philo->id);
	pthread_mutex_unlock(philo->l_fork);
}

void	destroy(t_program *prog)
{
	pthread_mutex_destroy(&prog->dead_lock);
	pthread_mutex_destroy(&prog->meal_lock);
	pthread_mutex_destroy(&prog->write_lock);
	pthread_mutex_destroy(&prog->total_lock);
	pthread_mutex_destroy(&prog->starting_lock);
}
