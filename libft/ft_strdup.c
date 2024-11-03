/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:12:48 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 06:12:49 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*src_casted;
	size_t	i;

	str = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!str)
		return (0x0);
	src_casted = (char *)src;
	i = 0;
	while (src_casted[i] != '\0')
	{
		str[i] = src_casted[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
