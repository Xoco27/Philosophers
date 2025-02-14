/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:39:59 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/28 14:54:15 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*b;
	const char	*p;
	int			i;

	if (src == NULL && dest == NULL)
		return (NULL);
	b = dest;
	p = src;
	i = 0;
	while (n > 0)
	{
		b[i] = p[i];
		i++;
		n--;
	}
	return (dest);
}
/*int	main(void)
{
	char str1[4] = "abc";
	char str2[4];
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%p\n", memcpy(str2, str1, sizeof(str1)));
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%p\n", ft_memcpy(NULL, NULL, sizeof(str1)));
	printf("%s\n", str1);
	printf("%s\n", str2);
	return (0);
}*/
