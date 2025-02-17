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
