/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:31:56 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/21 14:37:20 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}

/*void	ft_f(unsigned int i, char *c)
{
	*c += i;
	return ;
}

int	main(void)
{
	char	c[] = "0000000000";
	ft_striteri(c, (ft_f));
	printf("%s", c);
	return (0);
}*/