/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:09:52 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/16 11:03:49 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*int main (void)
{
	char src[4] = "abc";
	char dst[4];
	printf("%lu\n", ft_strlcpy(dst, src, 4));
	printf("%s\n", dst);
	return (0);
}*/
