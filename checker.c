/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:26:32 by mchiboub          #+#    #+#             */
/*   Updated: 2023/06/18 16:33:16 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_str(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->str[i] = '\0';
		i++;
	}
}

void	read_operations(t_data *data)
{
	char	c;
	int		i;

	init_str(data);
	i = 42;
	while (i > 0)
	{
		i = read(0, &c, 1);
		if (c == '\n' && ft_strlen(data->str) > 0)
		{
			exec_inputs_1(data, data->str, 0);
			init_str(data);
		}
		else
		{
			if (ft_strlen(data->str) == 3)
			{
				
				while (i != 0)
					i = read(0, &c, 1);
				error_parameter();
			}
			else
				data->str[ft_strlen(data->str)] = c;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc > 1)
	{
		count_elements(&data, argc, argv);
		init_stacks(&data, argc, argv);
		read_operations(&data);
		if (check_stack_a(&data))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_stacks(&data);
	}
	return (0);
}
