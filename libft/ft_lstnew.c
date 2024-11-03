/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:12:04 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 07:12:46 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*cellule;

	cellule = malloc(sizeof(t_list));
	if (cellule == NULL)
		return (NULL);
	cellule->content = content;
	cellule->next = NULL;
	return (cellule);
}
