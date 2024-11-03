/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:19:42 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 06:21:59 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*bite;

	new = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		bite = ft_lstnew(f(lst->content));
		if (new == NULL)
			ft_lstclear(&new, del);
		ft_lstadd_back(&new, bite);
		lst = lst->next;
	}
	return (new);
}
