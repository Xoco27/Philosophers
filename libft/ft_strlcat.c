/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:56:14 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/16 11:04:22 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dl;
	size_t	sl;

	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	j = 0;
	if (size <= dl)
		return (sl + size);
	i = dl;
	while (i < size - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dl + sl);
}
/*int main (void)
{
	char dst[11] = "Hello";
	char src[] = "World";
	printf("%s\n", dst);
	printf("%lu\n", ft_strlcat(dst, src, sizeof(dst)));
	printf("%s\n", dst);
	return (0);
}*/
