/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v2_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:17:29 by mchiboub          #+#    #+#             */
/*   Updated: 2023/06/17 01:08:13 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_pushes_a(t_data *data, int i, int print)
{
	int	operations;
	int	n1;
	int	n2;

	operations = 0;
	n1 = data->stack_a[data->index_a - 1];
	n2 = data->stack_c[data->index_c - 1];
	while ((n1 != n2) && (n1 > i))
	{
		exec_rra(data, print);
		operations++;
		n1 = data->stack_a[data->index_a - 1];
	}
	return (operations);
}

int	sorting_pushes_b(t_data *data, int i, int print)
{
	int	operations;
	int	n1;
	int	n2;

	operations = 0;
	n1 = data->stack_a[data->index_a - 1];
	n2 = data->stack_c[data->index_c - 1];
	if ((n1 == n2) || (data->stack_b[0] > n1))
	{
		exec_pa(data, print);
		exec_ra(data, print);
		operations += 2;
	}
	else
	{
		if (do_rb(data, i))
			exec_rb(data, print);
		else
			exec_rrb(data, print);
		operations++;
	}
	return (operations);
}

int	sorting_pushes(t_data *data, int print)
{
	int	i;
	int	operations;

	operations = 0;
	while (data->index_b > 0)
	{
		i = find_next_elem(data);
		operations += sorting_pushes_a(data, i, print);
		while (data->stack_b[0] != i)
			operations += sorting_pushes_b(data, i, print);
		exec_pa(data, print);
		operations++;
	}
	while (data->stack_a[data->index_a - 1] != data->stack_c[data->index_c - 1])
	{
		exec_rra(data, print);
		operations++;
	}
	return (operations);
}
