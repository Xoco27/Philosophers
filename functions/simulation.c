/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:33:29 by cfleuret          #+#    #+#             */
/*   Updated: 2025/02/20 16:14:17 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eating(t_philo *philo)
{
	if (is_he_dead(philo) == 1)
		return ;
	pthread_mutex_lock(philo->l_fork);
	printf("philo %d took his left fork\n", philo->id);
	if (is_he_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	printf("philo %d took his right fork\n", philo->id);
	if ((get_current_time() - philo->last_meal) >= philo->time_to_die)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_lock(philo->dead_lock);
		philo->dead = 1;
		philo->prog->dead_flag = 1;
		printf("philo %d DIED\n", philo->id);
		pthread_mutex_unlock(philo->dead_lock);
		return ;
	}
	printf("philo %d is eating\n", philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	if (is_he_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_unlock(philo->l_fork);
	printf("philo %d dropped his left fork\n", philo->id);
	pthread_mutex_unlock(philo->r_fork);
	printf("philo %d dropped his right fork\n", philo->id);
}

static void	philo_sleeping(t_philo *philo)
{
	if (is_he_dead(philo) == 1)
		return ;
	printf("philo %d is sleeping\n", philo->id);
	ft_usleep(philo->time_to_sleep);
	if (is_he_dead(philo) == 1)
		return ;
	if (get_current_time() - philo->last_meal >= philo->time_to_die)
	{
		pthread_mutex_lock(philo->dead_lock);
		philo->dead = 1;
		philo->prog->dead_flag = 1;
		printf("philo %d DIED\n", philo->id);
		pthread_mutex_unlock(philo->dead_lock);
		return ;
	}
}

static void	philo_thinking(t_philo *philo)
{
	printf("philo %d is thinking\n", philo->id);
}

void	*start(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	while (philo->meals_eaten < philo->num_times_to_eat && philo->dead == 0)
	{
		if (is_he_dead(philo) == 1)
			return (NULL);
		philo_eating(philo);
		if (is_he_dead(philo) == 1)
			return (NULL);
		philo_sleeping(philo);
		if (is_he_dead(philo) == 1)
			return (NULL);
		philo_thinking(philo);
		if (is_he_dead(philo) == 1)
			return (NULL);
	}
	return (0);
}
