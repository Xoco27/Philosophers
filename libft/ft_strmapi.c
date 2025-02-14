/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:58:16 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/28 15:05:24 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;
	int		l;

	l = ft_strlen(s);
	res = (char *)malloc(l * sizeof(char) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*char    f(unsigned int i, char s)
{
        s = s + i;
        return (s);
}

int	main(void)
{
	printf("%s", ft_strmapi("Hello", (*f)));
	return (0);
}*/
