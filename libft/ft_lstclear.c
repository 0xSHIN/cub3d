/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:22:11 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 07:22:42 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = *lst;
	if (*lst == NULL)
		return ;
	while (tmp)
	{
		tmp = tmp->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	lst = NULL;
}
