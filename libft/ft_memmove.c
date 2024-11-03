/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:27:49 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/07 19:04:10 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	d = (char *)dest;
	s = (const char *)src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (dest);
}
/*
Si les deux blocs sont identiques, return dest;
	if (d == s)
		return (dest); 

Si la destination est avant la source, copiez les données de gauche à droite.
Si la destination est après la source, copiez les données de droite à gauche.
*/
