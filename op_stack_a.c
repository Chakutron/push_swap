/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:26:32 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/25 18:54:24 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_sa(t_data *data, int print)
{
	int	tmp;

	if (data->index_a > 1)
	{
		tmp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = tmp;
		if (print)
			ft_printf("sa\n");
	}
}

void	exec_pa(t_data *data, int print)
{
	int	i;

	if (data->index_b > 0)
	{
		if (data->index_a > 0)
		{
			i = data->index_a;
			while (i > 0)
			{
				data->stack_a[i] = data->stack_a[i - 1];
				i--;
			}
		}
		data->stack_a[0] = data->stack_b[0];
		data->index_a += 1;
		data->index_b -= 1;
		i = 0;
		while (i < data->index_b)
		{
			data->stack_b[i] = data->stack_b[i + 1];
			i++;
		}
		if (print)
			ft_printf("pa\n");
	}
}

void	exec_ra(t_data *data, int print)
{
	int	i;
	int	tmp;

	if (data->index_a > 1)
	{
		i = 0;
		tmp = data->stack_a[0];
		while (i < data->index_a - 1)
		{
			data->stack_a[i] = data->stack_a[i + 1];
			i++;
		}
		data->stack_a[i] = tmp;
		if (print)
			ft_printf("ra\n");
	}
}

void	exec_rra(t_data *data, int print)
{
	int	i;
	int	tmp;

	if (data->index_a > 1)
	{
		i = data->index_a - 1;
		tmp = data->stack_a[i];
		while (i > 0)
		{
			data->stack_a[i] = data->stack_a[i - 1];
			i--;
		}
		data->stack_a[i] = tmp;
		if (print)
			ft_printf("rra\n");
	}
}
