/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:29:14 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/19 08:00:11 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int arc, char **arv)
{
	t_list		*args;
	t_s_hold	*stacks;

	args = get_args(arc, arv);
	if (!args_valid(arc, args))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	if (has_duplicates(args))
	{
		ft_putstr_fd("Error\n--Duplicates\n", 2);
		return (0);
	}
	stacks = sh_init(args);
	run_instructions(stacks, 1);
	if (is_sorted(stacks->stack_a) && ft_lstlen(stacks->stack_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}
