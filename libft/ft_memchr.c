/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:32:33 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/15 14:01:27 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*b;
	size_t				i;

	i = 0;
	b = s;
	while (n > 0)
	{
		if (b[i] == (unsigned char)c)
			return ((char *) &b[i]);
		i++;
		n--;
	}
	return (NULL);
}

/*int main (void)
{
	char str[4] = "abc";
	printf("%p\n", memchr(str, 100, sizeof(str)));
	printf("%p\n", ft_memchr(str, 100, sizeof(str)));
	return (0);
}*/
