/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:44:41 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/16 15:15:23 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len(const char *s, size_t len, unsigned int start)
{
	size_t	l;

	if (start > ft_strlen(s))
		return (1);
	l = ft_strlen(s + start);
	if (l > len)
		return (len + 1);
	else
		return (l + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;

	if (start >= ft_strlen(s))
	{
		c = (char *)malloc(1 * sizeof(char));
		if (c == NULL)
			return (NULL);
		c[0] = '\0';
		return (c);
	}
	len = ft_len(s, len, start);
	c = (char *)malloc(len * sizeof(char));
	if (c == NULL)
		return (NULL);
	ft_strlcpy(c, s + start, len);
	return (c);
}
/*int	main(void)
{
	char	*nstr;
	nstr = ft_substr("tripouille", 100, 1);
	printf("%s", nstr);
	return (0);
}*/