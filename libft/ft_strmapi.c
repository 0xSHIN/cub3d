/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:59:24 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 06:59:25 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL || f == NULL || s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		str[i] = (*f)(i, str[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
