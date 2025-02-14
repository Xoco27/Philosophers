/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:53:05 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/28 14:45:44 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_checkend(char const *s1, char const *set, int l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (set[j])
	{
		if (set[j] == s1[i - 1])
		{
			while (set[j] == s1[i - 1])
			{
				i--;
				l--;
			}
			j = -1;
		}
		j++;
	}
	if (l <= 0)
		l = 1;
	l--;
	return (l);
}

static char	*ft_trim(char const *s1, char const *set, int l, char *nstr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (set[i] == s1[j])
		{
			j++;
			i = -1;
		}
		i++;
	}
	i = 0;
	while (l-- > 0)
	{
		nstr[i] = s1[j];
		i++;
		j++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*nstr;
	int		i;
	int		j;
	int		l;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = 0;
	l = ft_strlen(s1) + 1;
	while (set[i])
	{
		if (set[i] == s1[j])
		{
			j++;
			l--;
			i = -1;
		}
		i++;
	}
	l = ft_checkend(s1, set, l);
	nstr = (char *)malloc(l * sizeof(char) + 1);
	if (nstr == NULL)
		return (NULL);
	return (ft_trim(s1, set, l, nstr));
}

/*int	main(void)
{
	printf("%s", ft_strtrim("Hld", " Hld"));
	return (0);
}*/
