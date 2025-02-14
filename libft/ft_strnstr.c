/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:29:22 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/15 16:12:07 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *) &big[0]);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] != '\0'
			&& little[j] != '\0'
			&& big[i + j] == little[j]
			&& i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
/*int main (void)
{
	char str[] = "abcdef";
	char to_find[] = "bc";
	printf("%s",ft_strnstr(str,to_find, 3));
	return (0);
}*/
