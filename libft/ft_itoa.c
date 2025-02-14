/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:49:25 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/28 15:09:32 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_int_min(int n)
{
	char	*str;
	int		i;

	n = 2147483647;
	i = 10;
	str = (char *)malloc(12 * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i > 0)
	{
		str[i] = (n % 10 + '0');
		i--;
		n /= 10;
	}
	str[0] = '-';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static char	*ft_convert(char *str, int l, int n)
{
	int	i;
	int	d;

	i = l + 1;
	str[i] = '\0';
	i--;
	d = -1;
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
		d = 0;
	}
	while (i > d)
	{
		str[i] = (n % 10 + '0');
		i--;
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		l;
	int		m;
	char	*str;

	str = NULL;
	if (n == -2147483648)
		return (ft_int_min(n));
	l = 0;
	m = n;
	if (m < 10)
		m *= -1;
	while (m >= 10)
	{
		m /= 10;
		l++;
	}
	if (n < 0)
		l++;
	str = (char *)malloc(l * sizeof(char) + 2);
	if (str == NULL)
		return (NULL);
	str = ft_convert(str, l, n);
	return (str);
}
/*int	main(void)
{
	printf("%s", ft_itoa(0));
	return (0);
}*/
