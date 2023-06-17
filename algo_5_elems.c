/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5_elems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:16:51 by mchiboub          #+#    #+#             */
/*   Updated: 2023/06/15 19:01:18 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algo_5_elems_a(t_data *data, int print)
{
	int	operations;

	operations = algo_3_elems(data, print);
	exec_pa(data, print);
	exec_pa(data, print);
	operations += 2;
	if (data->stack_a[0] > data->stack_a[1])
	{
		exec_sa(data, print);
		operations++;
	}
	return (operations);
}

int	algo_5_elems(t_data *data, int print)
{
	int	operations;
	int	i;

	operations = 0;
	i = 0;
	while (i < 5)
	{
		if (data->stack_a[0] == data->stack_c[data->index_c - 5]
			|| data->stack_a[0] == data->stack_c[data->index_c - 4])
			exec_pb(data, print);
		else
			exec_ra(data, print);
		operations++;
		i++;
		if (data->index_a == 3)
			break ;
	}
	operations += algo_5_elems_a(data, print);
	return (operations);
}
