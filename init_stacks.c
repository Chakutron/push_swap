/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:26:32 by mchiboub          #+#    #+#             */
/*   Updated: 2023/06/17 16:12:30 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_elements(t_data *data, int argc, char *argv[])
{
	int	i;
	int	j;
	int	space;

	i = 1;
	data->len = 0;
	while (i < argc)
	{
		j = 0;
		space = 1;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ' && space)
			{
				data->len += 1;
				space = 0;
			}
			else if (argv[i][j] == ' ')
				space = 1;
			j++;
		}
		i++;
	}
}

void	init_stacks_1(t_data *data, int argc, char *argv[])
{
	data->len = 0;
	data->i = 1;
	while (data->i < argc)
	{
		if (ft_strlen(argv[data->i]) == 0)
			error_parameter();
		data->j = 0;
		data->space = 1;
		while (argv[data->i][data->j])
		{
			if (argv[data->i][data->j] != ' ' && data->space)
			{
				data->stack_a[data->len] = ft_atoi(&argv[data->i][data->j]);
				data->stack_b[data->len] = 0;
				data->stack_c[data->len] = data->stack_a[data->len];
				data->original_stack_a[data->len] = data->stack_a[data->len];
				data->len += 1;
				data->space = 0;
			}
			else if (argv[data->i][data->j] == ' ')
				data->space = 1;
			data->j += 1;
		}
		data->i += 1;
	}
}

void	init_stacks(t_data *data, int argc, char *argv[])
{
	data->stack_a = malloc(sizeof(int) * data->len);
	data->stack_b = malloc(sizeof(int) * data->len);
	data->stack_c = malloc(sizeof(int) * data->len);
	data->original_stack_a = malloc(sizeof(int) * data->len);
	init_stacks_1(data, argc, argv);
	data->index_a = data->len;
	data->index_b = 0;
	data->index_c = data->len;
}

void	free_stacks(t_data *data)
{
	free(data->stack_a);
	free(data->stack_b);
	free(data->stack_c);
	free(data->original_stack_a);
}
