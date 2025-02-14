/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:35:46 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/29 12:13:05 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*p;

	if (lst == NULL)
		return (lst);
	p = lst;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return (p);
}
/*int	main(void)
{
	t_list	*l;
	t_list	*l2;
	t_list	*l3;
	t_list	*res;
	l = ft_lstnew((void *)1);
	l2 = ft_lstnew((void *)2);
	l3 = ft_lstnew((void *)3);
	ft_lstadd_front(&l, l2);
	ft_lstadd_front(&l, l3);
	res = ft_lstlast(l);
	printf("%d", (int)(intptr_t)res->content);
	return (0);
}*/
