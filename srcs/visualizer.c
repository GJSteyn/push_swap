/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 07:41:46 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/20 07:59:38 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_largest(t_s_hold *st)
{
	int			largest;
	t_list		*tmp;

	largest = 0;
	tmp = st->stack_a;
	while (tmp)
	{
		if (*(int*)tmp->content > largest)
			largest = *(int*)tmp->content;
		tmp = tmp->next;
	}
	tmp = st->stack_b;
	while (tmp)
	{
		if (*(int*)tmp->content > largest)
			largest = *(int*)tmp->content;
		tmp = tmp->next;
	}
	return (largest);
}

void		visualize(t_s_hold *st)
{
	int			i;
	int			j;
	int			curr;
	int			a_len;
	int			b_len;
	int			total;
	t_list		*tmp;

	i = 0;
	j = 0;
	curr = get_largest(st);
	a_len = ft_lstlen(st->stack_a);
	b_len = ft_lstlen(st->stack_b);
	total = a_len + b_len;
	while (curr > 0)
	{
		tmp = st->stack_a;
		while (tmp)
		{
			if (*(int*)tmp->content >= curr)
				ft_putstr_fd(GGRN"|"GCLR, 2);
			else
				ft_putstr_fd(" ", 2);
			tmp = tmp->next;
		}
		ft_putstr_fd(GRED"-"GCLR, 2);
		tmp = st->stack_b;
		while (tmp)
		{
			if (*(int*)tmp->content >= curr)
				ft_putstr_fd(GYEL "|"GCLR, 2);
			else
				ft_putstr_fd(" ", 2);
			tmp = tmp->next;
		}
		ft_putchar_fd('\n', 2);
		curr--;
	}
}
