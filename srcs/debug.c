/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 09:28:53 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/21 13:34:09 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

static void	single_line(t_list **a, t_list **b)
{
	if (*a)
	{
		ft_putnbr_fd(*(int*)(*a)->content, 2);
		*a = (*a)->next;
	}
	else
		ft_putchar_fd('-', 2);
	ft_putchar_fd('\t', 2);
	if (*b)
	{
		ft_putnbr_fd(*(int*)(*b)->content, 2);
		*b = (*b)->next;
	}
	else
		ft_putchar_fd('-', 2);
	ft_putchar_fd('\n', 2);
}

void		debugger(t_s_hold *st, char *op)
{
	t_list		*a;
	t_list		*b;

	if (!st)
		return ;
	a = st->stack_a;
	b = st->stack_b;
	ft_putstr_fd("\n----------------------------------------------\n", 2);
	ft_putstr_fd(GGRN"Exec "GCLR, 2);
	ft_putstr_fd(op, 2);
	ft_putstr_fd(":\n", 2);
	ft_putstr_fd("----------------------------------------------\n", 2);
	while (a != NULL || b != NULL)
	{
		single_line(&a, &b);
	}
	ft_putstr_fd("_\t_\n", 2);
	ft_putstr_fd("a\tb\n", 2);
}

int		has_debug_op(unsigned int options)
{
	if (ft_2pow('v' - 'a') & options)
		return (1);
	return (0);
}

int		has_vis_op(unsigned int options)
{
	if (ft_2pow('p' - 'a') & options)
		return (1);
	return (0);
}

void		print_init(t_s_hold *st)
{
	t_list		*a;
	t_list		*b;

	if (!st)
		return ;
	a = st->stack_a;
	b = st->stack_b;
	ft_putstr_fd("\n----------------------------------------------\n", 2);
	ft_putstr_fd(GGRN"Init"GCLR" a and b:\n", 2);
	ft_putstr_fd("----------------------------------------------\n", 2);
	while (a != NULL || b != NULL)
	{
		single_line(&a, &b);
	}
}
