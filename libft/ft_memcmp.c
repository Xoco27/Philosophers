/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:04:40 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/15 16:12:23 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			i;
	const char	*c1;
	const char	*c2;

	c1 = s1;
	c2 = s2;
	i = 0;
	while (n > 0)
	{
		if ((unsigned char)c1[i] != (unsigned char)c2[i])
			return ((unsigned char)c1[i] - (unsigned char)c2[i]);
		i++;
		n--;
	}
	return (0);
}
/*int	main(void)
{
	char s[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	printf("%d\n", memcmp(s, s2, 1));
	printf("%d\n", ft_memcmp(s, s2, 1));
	return (0);
}*/