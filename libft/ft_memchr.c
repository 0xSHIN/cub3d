/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:17:52 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 06:18:31 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	char	*str_ptr;
	size_t	i;

	i = 0;
	str_ptr = (char *)memoryBlock;
	while (i != size)
	{
		if (str_ptr[i] == (char)searchedChar)
			return (&str_ptr[i]);
		i++;
	}
	return (NULL);
}
