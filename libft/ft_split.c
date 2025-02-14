/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:14:51 by cfleuret          #+#    #+#             */
/*   Updated: 2025/02/13 16:09:51 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	int	i;
	int	n;
	int	word;

	i = 0;
	n = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
		{
			word = 1;
			n++;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (n);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*ft_strndup(const char *s, int start, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

static char	**ft_separate(const char *s, char c, char **tab, int n)
{
	int	i;
	int	start;
	int	j;

	i = 0;
	j = -1;
	while (j++ < n - 1)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		tab[j] = ft_strndup(s, start, i - start);
		if (!tab[j])
		{
			ft_free(tab);
			return (NULL);
		}
	}
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	if (s[0] == '\0')
		return (NULL);
	i = ft_count(s, c);
	tab = (char **)malloc((i + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (i != 0)
		tab = ft_separate(s, c, tab, i);
	tab[i] = NULL;
	return (tab);
}

// int    main(void)
// {
//     char    **tab;
//     int        i;

//     tab = ft_split("1 2 3", ' ');
//     if (tab == NULL)
//     {
//         printf("NULL");
//         return (1);
//     }
//     i = 0;
//     while (tab[i])
//     {
//         printf("%s\n", tab[i]);
//         i++;
//     }
//     i = 0;
//     while (tab[i])
//     {
//         free(tab[i]);
//         i++;
//     }
//     free(tab);
//     return (0);
// }
