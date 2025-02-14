/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:07:26 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/29 16:39:00 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*l;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		return ;
	p = *lst;
	l = *lst;
	while (p != NULL)
	{
		l = p->next;
		if (del)
			del(p->content);
		free(p);
		p = l;
	}
	*lst = NULL;
}
/*void	del(void * c)
{
	free(c);
}

int	main(void)
{
	t_list	*l;
	t_list  *l2;
	t_list  *l3;
	int *content1 = malloc(sizeof(int));
	int *content2 = malloc(sizeof(int));
	int *content3 = malloc(sizeof(int));
	l = ft_lstnew(content1);
	l2 = ft_lstnew(content2);
	l3 = ft_lstnew(content3);
	ft_lstadd_front(&l, l2);
	ft_lstadd_front(&l, l3);
	ft_lstclear(&l, (del));
	printf("%p\n", (l)->content);
	return (0);
}*/
