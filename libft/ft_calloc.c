/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:21:22 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 07:21:51 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	total;

	tab = NULL;
	total = (count * size);
	if (count != 0 && ((count * size) / count != size))
		return (NULL);
	tab = malloc(total);
	if (tab == NULL)
		return (NULL);
	ft_memset(tab, 0, total);
	return (tab);
}
