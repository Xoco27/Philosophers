/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:33:29 by cfleuret          #+#    #+#             */
/*   Updated: 2025/02/18 16:28:27 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	pthread_mutex_lock(philo->write_lock);
	printf("%d\n", philo->id);
	pthread_mutex_unlock(philo->write_lock);
	return (0);
}
