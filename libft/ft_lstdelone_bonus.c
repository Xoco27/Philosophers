/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:14:15 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/29 16:38:12 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}

void	del(void *c)
{
	free(c);
}

/*int	main(void)
{
	t_list	*l;
	int *c = malloc(sizeof(int));
	l = ft_lstnew(c);
	ft_lstdelone(l, (del));
	printf("%p\n", (l)->content);
	return (0);
}*/
