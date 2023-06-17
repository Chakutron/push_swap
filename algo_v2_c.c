/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v2_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:17:29 by mchiboub          #+#    #+#             */
/*   Updated: 2023/06/17 01:26:10 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_stacks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->index_c)
	{
		data->stack_a[i] = data->original_stack_a[i];
		data->stack_b[i] = 0;
		i++;
	}
	data->index_a = data->index_c;
	data->index_b = 0;
}

int	top_split(t_data *data, int percentage)
{
	int	num;

	if (percentage > 100)
		percentage = 100;
	num = data->stack_c[(data->index_c * percentage / 100) - 1];
	if (num >= data->stack_c[data->index_c - 6])
		num = data->stack_c[data->index_c - 6];
	return (num);
}

int	do_ra(t_data *data, int n)
{
	int	i;

	if (data->index_a == 0)
		return (42);
	if (data->stack_a[0] <= n)
		return (0);
	i = 0;
	while (i < data->index_a)
	{
		if (data->stack_a[i] <= n)
			break ;
		i++;
	}
	if (i == data->index_a)
		return (42);
	else if (i <= (data->index_a / 2))
		return (1);
	else
		return (-1);
}

int	do_rb(t_data *data, int n)
{
	int	i;

	i = 0;
	while (i < data->index_b)
	{
		if (data->stack_b[i] == n)
			break ;
		i++;
	}
	if (i <= (data->index_b / 2))
		return (1);
	else
		return (0);
}

int	find_next_elem(t_data *data)
{
	int	max;
	int	i;

	max = INT_MIN;
	i = 0;
	while (i < data->index_b)
	{
		if (data->stack_b[i] > max)
			max = data->stack_b[i];
		i++;
	}
	return (max);
}
