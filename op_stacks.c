/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:26:32 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/25 18:55:30 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_ss(t_data *data, int print)
{
	exec_sa(data, 0);
	exec_sb(data, 0);
	if (print)
		ft_printf("ss\n");
}

void	exec_rr(t_data *data, int print)
{
	exec_ra(data, 0);
	exec_rb(data, 0);
	if (print)
		ft_printf("rr\n");
}

void	exec_rrr(t_data *data, int print)
{
	exec_rra(data, 0);
	exec_rrb(data, 0);
	if (print)
		ft_printf("rrr\n");
}
