/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:17:41 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 07:27:36 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	size_t		trimmed_len;
	char		*trimmed_str;

	start = s1;
	end = s1 + ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	while (start < end && is_set((unsigned char)*start, set) == 1)
		start++;
	while (end > start && is_set((unsigned char)*(end - 1), set) == 1)
		end--;
	trimmed_len = end - start;
	trimmed_str = malloc(trimmed_len + 1);
	if (trimmed_str == NULL)
	{
		return (NULL);
	}
	ft_memcpy(trimmed_str, start, trimmed_len);
	trimmed_str[trimmed_len] = '\0';
	return (trimmed_str);
}
