/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:45:06 by mchiboub          #+#    #+#             */
/*   Updated: 2023/06/15 19:04:15 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_parameter(void)
{
	ft_printf("Error\n");
	exit(0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;
	int		neg;

	i = 0;
	if (nptr[0] == '-')
	{	
		neg = -1;
		i++;
	}
	else
		neg = 1;
	nb = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
		if (nb > INT_MAX || (nb * neg) < INT_MIN)
			error_parameter();
	}
	if (nptr[i] != '\0' && nptr[i] != ' ')
		error_parameter();
	return (nb * neg);
}
