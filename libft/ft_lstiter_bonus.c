/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:41:23 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/29 17:35:13 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*p;

	p = lst;
	while (p != NULL)
	{
		f(p->content);
		p = p->next;
	}
}

/*void	add(void *c)
{
	int	*p;

	p = (int *)c;
	*p = 3;
}

int	main(void)
{
	t_list  *l;
	l = ft_lstnew((void *)2);
	ft_lstiter(l, add);
	printf("%d\n", (int)(intptr_t)l->content);
	printf("%p\n", l->next);
	return (0);
}*/
