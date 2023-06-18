/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:26:32 by mchiboub          #+#    #+#             */
/*   Updated: 2023/06/18 16:30:36 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_inputs_1(t_data *data, char *str, int print)
{
	if (strcmp(str, "sa") == 0)
		exec_sa(data, print);
	else if (strcmp(str, "sb") == 0)
		exec_sb(data, print);
	else if (strcmp(str, "ss") == 0)
		exec_ss(data, print);
	else if (strcmp(str, "pa") == 0)
		exec_pa(data, print);
	else if (strcmp(str, "pb") == 0)
		exec_pb(data, print);
	else if (strcmp(str, "ra") == 0)
		exec_ra(data, print);
	else if (strcmp(str, "rb") == 0)
		exec_rb(data, print);
	else if (strcmp(str, "rr") == 0)
		exec_rr(data, print);
	else if (strcmp(str, "rra") == 0)
		exec_rra(data, print);
	else if (strcmp(str, "rrb") == 0)
		exec_rrb(data, print);
	else if (strcmp(str, "rrr") == 0)
		exec_rrr(data, print);
	else
		error_parameter();
	return (1);
}

int	exec_algo(t_data *data)
{
	int	operations;

	ft_printf("\033[0;33mReset stacks..\033[0m\n");
	reset_stacks(data);
	print_stacks(data);
	if (data->index_a == 3)
		operations = algo_3_elems(data, 1);
	else if (data->index_a == 5)
		operations = algo_5_elems(data, 1);
	else
		operations = algo_v2(data);
	ft_printf("\033[0;33m(Stack A) sorted in %i operations\033[0m\n",
		operations);
	return (operations);
}

void	exec_inputs_2(t_data *data, char *str)
{
	int	inputs1;

	inputs1 = exec_inputs_1(data, str, 1);
	if (strcmp(str, "exit") == 0)
		exit (0);
	else if (strcmp(str, "check") == 0)
		check_stacks(data);
	else if (strcmp(str, "algo") == 0)
		exec_algo(data);
	else
	{
		if (!inputs1)
			ft_printf("Invalid input");
	}
}

void	read_inputs(t_data *data)
{
	char	*str;

	while (1)
	{
		str = readline("\033[0;32mEnter input: \033[0m");
		exec_inputs_2(data, str);
		print_stacks(data);
		free(str);
	}
}
