/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:48:23 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 06:49:15 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*tab;
	long	nbr;
	int		i;

	nbr = n;
	i = len(nbr);
	tab = malloc(sizeof(char) * len(nbr) + 1);
	tab[i] = '\0';
	i--;
	if (tab == NULL)
		return (NULL);
	if (nbr < 0)
	{
		tab[0] = '-';
		nbr *= -1;
	}	
	if (nbr == 0)
		tab[0] = '0';
	while (nbr > 0)
	{
		tab[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	return (tab);
}
/*
int main()
{
	char *ok = ft_itoa(42);
	printf("%s", ok);
	free(ok);
}
*/
