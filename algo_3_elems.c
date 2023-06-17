/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3_elems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:16:51 by mchiboub          #+#    #+#             */
/*   Updated: 2023/06/15 18:58:27 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algo_3_elems_a(t_data *data, int print)
{
	int	operations;

	operations = 0;
	if (data->stack_a[1] < data->stack_a[0])
	{
		exec_sa(data, print);
		operations++;
	}
	exec_rra(data, print);
	operations++;
	return (operations);
}

int	algo_3_elems_b(t_data *data, int print)
{
	int	operations;

	operations = 0;
	if (data->stack_a[2] < data->stack_a[0])
		exec_ra(data, print);
	else
		exec_sa(data, print);
	operations++;
	return (operations);
}

int	algo_3_elems_c(t_data *data, int print)
{
	int	operations;

	operations = 0;
	if (data->stack_a[2] < data->stack_a[1])
	{
		exec_ra(data, print);
		exec_sa(data, print);
		exec_rra(data, print);
		operations += 3;
	}
	return (operations);
}

int	algo_3_elems(t_data *data, int print)
{
	int	operations;

	operations = 0;
	if ((data->stack_a[2] < data->stack_a[0])
		&& (data->stack_a[2] < data->stack_a[1]))
		operations += algo_3_elems_a(data, print);
	else if ((data->stack_a[1] < data->stack_a[0])
		&& (data->stack_a[1] < data->stack_a[2]))
		operations += algo_3_elems_b(data, print);
	else if ((data->stack_a[0] < data->stack_a[1])
		&& (data->stack_a[0] < data->stack_a[2]))
		operations += algo_3_elems_c(data, print);
	return (operations);
}
