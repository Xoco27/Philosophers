/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:48:17 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/28 12:47:23 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	(*lst) = new;
}
/*int main(void)
{
    t_list  *l;
    t_list *new;
    l = ft_lstnew((void *)2);
    new = ft_lstnew((void *)3);
    ft_lstadd_front(&l, new);
    printf("%d\n", (int)(intptr_t)(l)->content);
    printf("%d\n", (int)(intptr_t)(l)->next->content);
    return (0);
}*/