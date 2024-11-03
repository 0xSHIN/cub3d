/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:05:50 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 07:06:44 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int chr, size_t n)
{
	size_t	i;
	char	*str_ptr;

	str_ptr = (char *)str;
	i = 0;
	while (i < n)
	{
		str_ptr[i] = chr;
		i++;
	}
	return (str);
}
