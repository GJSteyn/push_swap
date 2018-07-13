/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:29:23 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/13 12:04:04 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int		main(int arc, char **arv)
{
	//int		i;
	t_list		*args;
	t_list		*sargs;
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
	if (is_sorted(args))
		return (0);
	sargs = get_sorted_args(arc, arv);
	normlist(args, sargs);
	stacks = sh_init(args, stack_b);
	if (ft_lstlen(args) > 8)
		reorder(stacks);
	//push_and_swap(stacks);
	//simplify(stacks->ops);
	sort2(stacks);
	t_list		*tmp;
	tmp = stacks->ops;
	while (tmp)
	{
		ft_putstr_fd((char*)tmp->content, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
	return (0);
}
