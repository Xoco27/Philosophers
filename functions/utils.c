/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:40:47 by cfleuret          #+#    #+#             */
/*   Updated: 2025/02/17 14:40:47 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_and_destroy(t_program *prog, pthread_mutex_t *forks, int n)
{
	int	i;
	i = 0;
	pthread_mutex_destroy(&prog->dead_lock);
	pthread_mutex_destroy(&prog->meal_lock);
	pthread_mutex_destroy(&prog->write_lock);
	while (i < n)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	i = 0;
	while (i < n)
	{
		free(prog->philos[i])
		i++;
	}
	free(prog);
}

size_t	get_current_time_ms()
{
    struct timeval	tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	f;
	int	c;

	i = 0;
	f = 0;
	c = 1;
	if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		return (0);
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			c = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		f = f * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (f * c);
}
