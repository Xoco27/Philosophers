/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:24:45 by cfleuret          #+#    #+#             */
/*   Updated: 2024/11/07 13:21:26 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	f;
	int	c;

	i = 0;
	f = 0;
	c = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
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
	return (f * c);
}
/*int main (void)
{
	char s[] = "    2147-483647";
	printf("%d\n",ft_atoi(s));
	printf("%d\n",atoi(s));
	return (0);
}*/
