/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:31:11 by cfleuret          #+#    #+#             */
/*   Updated: 2025/06/24 15:51:21 by cfleuret         ###   ########.fr       */
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
	count_time(philo);
	pthread_mutex_lock(philo->l_fork);
	if (philo->prog->dead_flag == 0)
		printf("%zu philo %d took his left fork\n",
			philo->prog->time, philo->id);
	ft_usleep(philo->time_to_die, philo);
	if (philo->prog->dead_flag == 0)
		printf("%zu philo %d DIED NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n",
			philo->prog->time, philo->id);
	philo->prog->dead_flag = 1;
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

void	check_usleep(t_philo *philo, int i)
{
	count_time(philo);
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->prog->philos[i].last_meal
		> philo->prog->philos[i].time_to_die)
	{
		pthread_mutex_unlock(philo->meal_lock);
		pthread_mutex_lock(philo->dead_lock);
		pthread_mutex_lock(philo->write_lock);
		if (philo->prog->dead_flag == 0)
			printf("%zu philo %d DIED NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n",
				philo->prog->time, philo->id);
		pthread_mutex_unlock(philo->write_lock);
		philo->dead = 1;
		philo->prog->dead_flag = 1;
		set_starting(philo->prog, 0);
		pthread_mutex_unlock(philo->dead_lock);
		return ;
	}
	pthread_mutex_unlock(philo->meal_lock);
}
