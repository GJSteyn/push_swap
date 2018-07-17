/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 05:59:56 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/17 09:11:28 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_closest_dir(t_list *lst, int target, int lstlen)
{
	int		best;
	int		best_ret;
	int		i;
	int		half;
	int		curr;

	best = lstlen;
	i = 0;
	half = lstlen / 2;
	if (*(int*)lst->content <= target)
		return (0);
	while (lst)
	{
		if (i > half)
			curr = i - lstlen;
		else
			curr = i;
		if (*(int*)lst->content <= target && ft_abs(curr) < best)
		{
			best = ft_abs(curr);
			best_ret = curr;
		}
		i++;
		lst = lst->next;
	}
	return (best_ret);
}

/*
static void	put_back(t_s_hold *st)
{
	int		len;
	int		back;

	len = ft_lstlen(st->stack_b);
	back = 0;
	push_a(st);
	len--;
	while (len > 0)
	{
		while (get_first(st->stack_b) > get_first(st->stack_a))
		{
			rotate_a(st);
			back++;
		}
		push_a(st);
		while (back > 0)
		{
			rev_rotate_a(st);
			back--;
		}
		len--;
	}
}
*/

static int 	get_closest_dir2(t_list *lst, int target)
{
	int		best;
	int		best_ret;
	int		i;
	int		curr;
	int		half;

	if (*(int*)lst->content == target)
		return (0);
	i = 0;
	best = ft_lstlen(lst);
	half = best / 2;
	while (lst)
	{
		if (i > half)
			curr = i - target;
		else
			curr = i;
		if (*(int*)lst->content == target && ft_abs(curr) < best)
		{
			best = ft_abs(curr);
			best_ret = curr;
		}
		i++;
		lst = lst->next;
	}
	return (best_ret);
}

static void	put_back2(t_s_hold *st, int size)
{
	int		side;

	while (size > 0)
	{
		side = get_closest_dir2(st->stack_b, size);
		while (side != 0)
		{
			if (side < 0)
			{
				rev_rotate_b(st);
				side++;
			}
			else if (side > 0)
			{
				rotate_b(st);
				side--;
			}
		}
		push_a(st);
		size--;
	}
}

void		sort4(t_s_hold *st)
{
	int		len;
	int		len2;
	int		curr;
	int		i;
	int		side;
	int		blocksize;

	blocksize = 21;
	len = ft_lstlen(st->stack_a);
	curr = blocksize;
	while (1)
	{
		len2 = ft_lstlen(st->stack_a);
		i = 0;
		while (i < blocksize && len2 > 0)
		{
			side = get_closest_dir(st->stack_a, curr, len);
			if (side > 0)
				while (*(int*)st->stack_a->content > curr)
					rotate_a(st);
			else if (side < blocksize)
				while (*(int*)st->stack_a->content > curr)
					rev_rotate_a(st);
			push_b(st);
			i++;
			if (get_first(st->stack_b) < get_second(st->stack_b))
				swap_b(st);
			len2--;
		}
		if (curr == len)
			break ;
		else if (curr < len - blocksize)
			curr += blocksize;
		else
			curr += len - curr;
	}
	put_back2(st, len);
}
