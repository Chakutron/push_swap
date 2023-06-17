/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:17:29 by mchiboub          #+#    #+#             */
/*   Updated: 2023/06/17 01:36:01 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_c(t_data *data)
{
	int	i;

	ft_printf("- Stack C:");
	if (data->index_c > 0)
	{
		i = 0;
		while (i < data->index_c)
		{
			ft_printf(" %i", data->stack_c[i]);
			i++;
		}
	}
	else
		ft_printf(" (null)");
	ft_printf("\n");
}

void	sort_stack_c(t_data *data)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < data->index_c)
	{
		j = 1;
		while (j < data->index_c)
		{
			if (data->stack_c[j - 1] > data->stack_c[j])
			{
				tmp = data->stack_c[j - 1];
				data->stack_c[j - 1] = data->stack_c[j];
				data->stack_c[j] = tmp;
			}
			else if (data->stack_c[j - 1] == data->stack_c[j])
				error_parameter();
			j++;
		}
		i++;
	}
}

void	init_algo_v2(t_data *data)
{
	if (data->index_c == 100)
	{
		data->min = 13;
		data->max = 39;
	}
	else if (data->index_c == 500)
	{
		data->min = 6;
		data->max = 11;
	}
	else
	{
		data->min = 1;
		data->max = 100;
	}
}

int	algo_v2(t_data *data)
{
	int	i;
	int	operations;
	int	min_ops;
	int	per_sum;

	init_algo_v2(data);
	min_ops = INT_MAX;
	i = data->min;
	while (i <= data->max)
	{
		operations = split_pushes(data, i, 0);
		operations += sorting_pushes(data, 0);
		if (operations < min_ops)
		{
			min_ops = operations;
			per_sum = i;
		}
		reset_stacks(data);
		i++;
	}
	operations = split_pushes(data, per_sum, 1);
	operations += sorting_pushes(data, 1);
	return (operations);
}
