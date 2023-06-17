/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:26:32 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/15 19:53:18 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_a(t_data *data)
{
	int	i;

	if (data->index_b > 0)
		return (0);
	else if (data->index_a > 1)
	{
		i = 1;
		while (i < data->index_a)
		{
			if (data->stack_a[i - 1] > data->stack_a[i])
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_stack_b(t_data *data)
{
	int	i;

	if (data->index_b == 0)
		return (0);
	else if (data->index_b > 1)
	{
		i = 1;
		while (i < data->index_b)
		{
			if (data->stack_b[i - 1] < data->stack_b[i])
				return (0);
			i++;
		}
	}
	return (1);
}

void	check_stacks(t_data *data)
{
	if (data->index_b == 0)
	{
		if (check_stack_a(data) == 1)
			ft_printf("\033[0;33m*** (Stack A) is sorted ***\033[0m\n");
		else
			ft_printf("\033[0;31m*** (Stack A) is not sorted ***\033[0m\n");
	}
	else
		ft_printf("\033[0;31m*** (Stack B) contains data ***\033[0m\n");
}
