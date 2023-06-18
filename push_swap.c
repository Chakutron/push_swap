/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:26:32 by mchiboub          #+#    #+#             */
/*   Updated: 2023/06/18 15:41:27 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc > 1)
	{
		count_elements(&data, argc, argv);
		init_stacks(&data, argc, argv);
		sort_stack_c(&data);
		if (data.index_a == 3)
			algo_3_elems(&data, 1);
		else if (data.index_a == 5)
			algo_5_elems(&data, 1);
		else
			algo_v2(&data);
		free_stacks(&data);
	}
	return (0);
}
