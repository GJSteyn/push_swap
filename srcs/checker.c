/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:29:14 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/10 13:35:47 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int arc, char **arv)
{
	t_list		*args;
	t_list		*stack_b;
	t_s_hold	*stacks;

	stack_b = NULL;
	if (!args_valid(arc, arv))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	args = get_sorted_args(arc, arv);
	if (has_duplicates(args))
	{
		ft_putstr_fd("Error\n--Duplicates\n", 2);
		return (0);
	}
	stacks = sh_init(args, stack_b);
	run_instructions(stacks, 1);
	/*
	if (is_sorted(args) && ft_lstlen(stack_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
	*/
}
