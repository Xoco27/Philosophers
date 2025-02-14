/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:20:34 by cfleuret          #+#    #+#             */
/*   Updated: 2025/02/10 17:54:49 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*nstr;
	unsigned int	i;
	unsigned int	s1l;
	unsigned int	s2l;

	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	i = 0;
	nstr = (char *)malloc((s1l + s2l + 1) * sizeof(char));
	if (nstr == NULL)
		return (NULL);
	while (i < s1l)
	{
		nstr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2l)
	{
		nstr[i + s1l] = s2[i];
		i++;
	}
	nstr[i + s1l] = '\0';
	return (nstr);
}
/*int	main(void)
{
	char s1[] = "hello";
	char s2[] = "world";
	printf("%s", ft_strjoin(s1, s2));
	return (0);
}*/
