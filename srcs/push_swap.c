/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:29:23 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/19 07:57:22 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int		main(int arc, char **arv)
{
	t_list		*args;
	t_list		*sargs;
	t_s_hold	*stacks;

	args = get_args(arc, arv);
	if (!args_valid(arc, args))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stacks = sh_init(args);
	sargs = get_sorted_args(args);
	normlist(stacks->stack_a, sargs);
	if (has_duplicates(stacks->stack_a))
	{
		ft_putstr_fd("Error\n--Duplicates\n", 2);
		return (0);
	}
	if (is_sorted(stacks->stack_a))
		return (0);
	if (ft_lstlen(args) > 8)
		sort4(stacks);
	else
		push_and_swap(stacks);
	//simplify(stacks->ops);
	print_ops(stacks->ops);
	return (0);
}
