/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:36:01 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/31 11:19:37 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*c;

	if (lst == NULL || f == NULL)
		return (NULL);
	p = ft_lstnew(f(lst ->content));
	if (p == NULL)
		return (NULL);
	c = p;
	lst = lst->next;
	while (lst != NULL)
	{
		c->next = ft_lstnew(f(lst->content));
		if (c == NULL)
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		c = c->next;
		lst = lst->next;
	}
	return (p);
}

/*void	del(void *c)
{
	free(c);
}

void	*add(void *c)
{
	return (c + 1);
}

int	main(void)
{
	t_list	*l = ft_lstnew((void *)1);
	t_list  *l2 = ft_lstnew((void *)2);
	t_list  *l3 = ft_lstnew((void *)3);
	t_list	*res;
	l->next = l2;
	l2->next = l3;
	res = ft_lstmap(l, add, del);
	printf("%d\n", (int)(intptr_t)res->content);
	return (0);
}*/
