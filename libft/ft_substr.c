/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:03:40 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 08:24:36 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	if (s_len - start > len)
		s_len = len;
	else
		s_len -= start;
	len = s_len;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
	if (ac != 4)
	{
		printf("3 args\n");
		return(1);
	}
	printf("%s\n", ft_substr(av[1], atoi(av[2]), atoi(av[3])));

}
*/
