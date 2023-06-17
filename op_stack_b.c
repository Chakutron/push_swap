/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:26:32 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/25 18:54:48 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_sb(t_data *data, int print)
{
	int	tmp;

	if (data->index_b > 1)
	{
		tmp = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = tmp;
		if (print)
			ft_printf("sb\n");
	}
}

void	exec_pb(t_data *data, int print)
{
	int	i;

	if (data->index_a > 0)
	{
		if (data->index_b > 0)
		{
			i = data->index_b;
			while (i > 0)
			{
				data->stack_b[i] = data->stack_b[i - 1];
				i--;
			}
		}
		data->stack_b[0] = data->stack_a[0];
		data->index_b += 1;
		data->index_a -= 1;
		i = 0;
		while (i < data->index_a)
		{
			data->stack_a[i] = data->stack_a[i + 1];
			i++;
		}
		if (print)
			ft_printf("pb\n");
	}
}

void	exec_rb(t_data *data, int print)
{
	int	i;
	int	tmp;

	if (data->index_b > 1)
	{
		i = 0;
		tmp = data->stack_b[0];
		while (i < data->index_b - 1)
		{
			data->stack_b[i] = data->stack_b[i + 1];
			i++;
		}
		data->stack_b[i] = tmp;
		if (print)
			ft_printf("rb\n");
	}
}

void	exec_rrb(t_data *data, int print)
{
	int	i;
	int	tmp;

	if (data->index_b > 1)
	{
		i = data->index_b - 1;
		tmp = data->stack_b[i];
		while (i > 0)
		{
			data->stack_b[i] = data->stack_b[i - 1];
			i--;
		}
		data->stack_b[i] = tmp;
		if (print)
			ft_printf("rrb\n");
	}
}
