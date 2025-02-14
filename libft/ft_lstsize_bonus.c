/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:58:22 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/28 13:55:34 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	l;

	if (lst == NULL)
		return (0);
	l = 1;
	while (lst->next != NULL)
	{
		l++;
		lst = lst->next;
	}
	return (l);
}
/*int	main(void)
{
	t_list	*l;
	t_list	*l2;
	t_list	*l3;
	l = ft_lstnew((void *)1);
	l2 = ft_lstnew((void *)2);
	l3 = ft_lstnew((void *)3);
	ft_lstadd_front(&l, l2);
	ft_lstadd_front(&l, l3);
	printf("%d\n", ft_lstsize(l));
	return (0);
}*/
