/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:26:32 by mchiboub          #+#    #+#             */
/*   Updated: 2023/06/15 19:42:55 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks_1(t_data *data)
{
	int	i;

	ft_printf("- Stack B:");
	if (data->index_b > 0)
	{
		i = 0;
		while (i < data->index_b)
		{
			ft_printf(" %i", data->stack_b[i]);
			i++;
		}
	}
	else
		ft_printf(" (null)");
	ft_printf("\n");
}

void	print_stacks(t_data *data)
{
	int	i;

	ft_printf("- Stack A:");
	if (data->index_a > 0)
	{
		i = 0;
		while (i < data->index_a)
		{
			ft_printf(" %i", data->stack_a[i]);
			i++;
		}
	}
	else
		ft_printf(" (null)");
	ft_printf("\n");
	print_stacks_1(data);
}
