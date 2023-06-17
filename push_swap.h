/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:32:55 by mchiboub          #+#    #+#             */
/*   Updated: 2023/06/17 16:00:32 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <limits.h>
# include "printf/ft_printf.h"

typedef struct s_data
{
	int		len;
	int		*stack_a;
	int		*stack_b;
	int		*stack_c;
	int		*original_stack_a;
	int		index_a;
	int		index_b;
	int		index_c;
	int		i;
	int		j;
	int		space;
	int		min;
	int		max;
	char	str[4];
}		t_data;

int		ft_atoi(const char *nptr);
void	error_parameter(void);
void	count_elements(t_data *data, int argc, char *argv[]);
void	init_stacks(t_data *data, int argc, char *argv[]);
void	free_stacks(t_data *data);
void	sort_stack_c(t_data *data);
void	reset_stacks(t_data *data);
void	print_stacks(t_data *data);
void	read_inputs(t_data *data);
int		exec_inputs_1(t_data *data, char *str, int print);
void	exec_sa(t_data *data, int print);
void	exec_sb(t_data *data, int print);
void	exec_ss(t_data *data, int print);
void	exec_pa(t_data *data, int print);
void	exec_pb(t_data *data, int print);
void	exec_ra(t_data *data, int print);
void	exec_rb(t_data *data, int print);
void	exec_rr(t_data *data, int print);
void	exec_rra(t_data *data, int print);
void	exec_rrb(t_data *data, int print);
void	exec_rrr(t_data *data, int print);
int		smallest_b(t_data *data);
int		biggest_b(t_data *data);
int		inferior(t_data *data);
int		top_split(t_data *data, int percentage);
int		do_ra(t_data *data, int n);
int		do_rb(t_data *data, int n);
int		do_rb_or_rrb(t_data *data);
int		find_next_elem(t_data *data);
int		algo_3_elems(t_data *data, int print);
int		algo_5_elems(t_data *data, int print);
int		algo_v2(t_data *data);
void	check_stacks(t_data *data);
int		check_stack_a(t_data *data);
int		check_stack_b(t_data *data);
int		split_pushes(t_data *data, int per_sum, int print);
int		sorting_pushes(t_data *data, int print);

#endif
