/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:10:53 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/15 11:05:30 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*r;

	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	r = (void *) 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			r = &s[i];
		i++;
	}
	return ((char *) r);
}

/*int	main(void)
{
	printf("%s\n", strrchr("teste", 't' + 256));
	printf("%s\n", ft_strrchr("teste", 't' + 256));
	return (0);
}*/