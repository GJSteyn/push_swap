/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:29:23 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/28 19:07:13 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int			main(int arc, char **arv)
{
	t_list		*args;
	t_list		*sargs;
	t_s_hold	*stacks;

	args = get_args(arc, arv);
	if (!args_valid(arc, args))
		ft_error("Error\n");
	stacks = sh_init(args);
	if (has_usage_op(stacks->options))
		print_usage();
	if (has_duplicates(stacks->stack_a))
		ft_error("Error\n");
	sargs = get_sorted_args(args);
	normlist(stacks->stack_a, sargs);
	if (is_sorted(stacks->stack_a))
		return (0);
	do_sort(stacks);
	print_ops(stacks->ops);
	destroy_stacks(&stacks);
	destroy_stack(&sargs);
	return (0);
}
