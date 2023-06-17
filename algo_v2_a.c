/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v2_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:17:29 by mchiboub          #+#    #+#             */
/*   Updated: 2023/06/17 00:30:43 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_pushes_a(t_data *data, int top_num, int percentage, int print)
{
	int	operations;
	int	rotation;

	exec_pb(data, print);
	operations = 1;
	if (data->stack_b[0] > top_split(data, percentage)
		&& data->index_b > 1)
	{
		rotation = do_ra(data, top_num);
		if (rotation == 1)
			exec_rr(data, print);
		else
			exec_rb(data, print);
		operations++;
	}
	return (operations);
}

int	split_pushes_b(t_data *data, int top_num, int print)
{
	int	operations;

	operations = 0;
	while (data->stack_a[0] > top_num)
	{
		exec_ra(data, print);
		operations++;
	}
	return (operations);
}

int	split_pushes_c(t_data *data, int top_num, int print)
{
	int	operations;

	operations = 0;
	while (data->stack_a[0] > top_num)
	{
		exec_rra(data, print);
		operations++;
	}
	return (operations);
}

int	split_pushes2(t_data *data, int top_num, int percentage, int print)
{
	int	operations;
	int	rotation;

	operations = 0;
	rotation = do_ra(data, top_num);
	while (rotation != 42)
	{
		if (rotation == 0)
			operations += split_pushes_a(data, top_num, percentage, print);
		else if (rotation == 1)
			operations += split_pushes_b(data, top_num, print);
		else if (rotation == -1)
			operations += split_pushes_c(data, top_num, print);
		rotation = do_ra(data, top_num);
	}
	return (operations);
}

int	split_pushes(t_data *data, int per_sum, int print)
{
	int	percentage;
	int	operations;
	int	top_num;

	percentage = per_sum;
	operations = 0;
	while (data->index_a > 5)
	{
		top_num = top_split(data, percentage + per_sum);
		operations += split_pushes2(data, top_num, percentage, print);
		percentage += per_sum * 2;
		if (percentage > 100)
			percentage = 100;
	}
	operations += algo_5_elems(data, print);
	return (operations);
}
