/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:30:43 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/28 15:31:19 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*ft_check(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*b;
	const char	*p;

	b = dest;
	p = src;
	i = n;
	while (i > 0)
	{
		b[i - 1] = p[i - 1];
		i--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*b;
	const char	*p;
	size_t		i;

	if (src == NULL && dest == NULL)
		return (NULL);
	b = dest;
	p = src;
	i = 0;
	if (b < p)
	{
		while (i < n)
		{
			b[i] = p[i];
			i++;
		}
	}
	else
		return (ft_check(dest, src, n));
	return (dest);
}
/*int	main(void)
{
	char str1[4] = "abc";
	char str2[4] = "abc";
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%p\n", memmove(str1 + 1, str1, 2));
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%p\n", ft_memmove(str1 + 1, str1, 2));
	printf("%s\n", str1);
	printf("%s\n", str2);
	return (0);
}*/
