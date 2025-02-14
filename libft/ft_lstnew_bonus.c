/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:58:28 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/25 14:35:20 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*c;

	c = malloc(sizeof(*c));
	if (c == NULL)
		return (NULL);
	c->content = content;
	c->next = NULL;
	return (c);
}

/*int main(void)
{
    t_list  *l;
    l = ft_lstnew((void *)2);
    printf("%d\n", (int)(intptr_t)l->content);
    printf("%p\n", l->next);
}*/
