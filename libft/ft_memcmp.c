/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:51:53 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 06:52:37 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size )
{
	unsigned char	*str_ptr1;
	unsigned char	*str_ptr2;
	size_t			i;

	str_ptr1 = (unsigned char *)pointer1;
	str_ptr2 = (unsigned char *)pointer2;
	i = 0;
	while (i < size)
	{
		if (str_ptr1[i] != str_ptr2[i])
			return (str_ptr1[i] - str_ptr2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
char s2[] = {0, 0, 127, 0};
char s3[] = {0, 0, 42, 0};

	printf("%d\n", ft_memcmp(s2, s3, 4));
}
*/
