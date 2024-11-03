/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:59:36 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 07:02:01 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	base;

	i = 0;
	sign = 1;
	base = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
	{
		i += 1;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9'
		&& base < 2147483647 && base > -2147483648)
	{
		base = base * 10 + (str[i] - '0');
		i++;
	}
	return (base * sign);
}
