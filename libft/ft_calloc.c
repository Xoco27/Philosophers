/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:13:25 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/29 12:59:13 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*array;

	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	if (nmemb == 0 && size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	array = (size_t *) malloc (nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, nmemb * size);
	return (array);
}
/*int	main(void)
{
	size_t *array;
	size_t *array2;
	size_t i = 0;
	array = ft_calloc(5, 0);
	array2 = calloc(0, 5);
	if (array == NULL)
	{
		printf("NULL");
		return(1);
	}
	while (i < 1)
	{
		printf("%lu\n", array[i]);
		i++;
	}
	return (0);
}*/
