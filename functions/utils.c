/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:40:47 by cfleuret          #+#    #+#             */
/*   Updated: 2025/02/27 16:02:05 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printing(t_philo *philo)
{
	if (philo->eating == 0)
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%zu philo %d took his left fork\n",
			get_current_time(), philo->id);
		printf("%zu philo %d took his right fork\n",
			get_current_time(), philo->id);
		printf("%zu philo %d is eating\n", get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
		philo->eating = 1;
		return ;
	}
	else
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%zu philo %d dropped his left fork\n",
			get_current_time(), philo->id);
		printf("%zu philo %d dropped his right fork\n",
			get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
		philo->eating = 0;
		return ;
	}
}

void	free_and_destroy(t_program *prog, pthread_mutex_t *forks, int n)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&prog->dead_lock);
	pthread_mutex_destroy(&prog->meal_lock);
	pthread_mutex_destroy(&prog->write_lock);
	pthread_mutex_destroy(&prog->total_lock);
	pthread_mutex_destroy(&prog->starting_lock);
	while (i < n)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	if (prog->philos)
		free(prog->philos);
	free(prog);
	free(forks);
}

size_t	get_current_time(void)
{
	struct timeval	tv;
	size_t			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	f;

	i = 0;
	f = 0;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		f = f * 10 + (str[i] - '0');
		i++;
	}
	if (f > INT_MAX)
		return (0);
	if (str[i] != '\0')
		return (0);
	return ((int)f);
}
