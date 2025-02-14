/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:58:04 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/29 12:18:04 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	p = (*lst);
	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = new;
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
	ft_lstadd_back(&l, l3);
    	printf("%d\n", (int)(intptr_t)(l)->content);
    	printf("%d\n", (int)(intptr_t)(l)->next->content);
	return (0);
}*/
