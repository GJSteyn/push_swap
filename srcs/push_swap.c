/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:29:23 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/11 18:43:20 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int		main(int arc, char **arv)
{
	//int		i;
	t_list		*args;
	t_list		*stack_b;
	t_s_hold	*stacks;

	//i = 1;
	stack_b = NULL;
	if (!args_valid(arc, arv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	args = get_args(arc, arv);
	if (has_duplicates(args))
	{
		ft_putstr_fd("Error\n--Duplicates\n", 2);
		return (0);
	}
	stacks = sh_init(args, stack_b);
	push_and_swap(stacks);
	return (0);
}
