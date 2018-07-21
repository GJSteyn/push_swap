/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 05:59:56 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/21 14:54:27 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_closest_dir(t_list *lst, int target, int lstlen)
{
	int		best;
	int		half;
	int		i;
	int		curr;

	best = lstlen;
	half = lstlen / 2;
	i = 0;
	if (*(int*)lst->content <= target)
		return (0);
	while (lst)
	{
		if (i > half)
			curr = i - lstlen;
		else
			curr = i;
		if (*(int*)lst->content <= target && ft_abs(curr) < ft_abs(best))
			best = curr;
		i++;
		lst = lst->next;
	}
	return (best);
}

static int	get_closest_dir2(t_list *lst, int target)
{
	int		best;
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
		if (*(int*)lst->content == target && ft_abs(curr) < ft_abs(best))
			best = curr;
		i++;
		lst = lst->next;
	}
	return (best);
}

static void	put_back(t_s_hold *st, int size)
{
	int		side;

	while (size > 0)
	{
		side = get_closest_dir2(st->stack_b, size);
		while (side != 0)
		{
			if (side < 0)
			{
				rev_rotate_b(st, 0);
				side++;
			}
			else if (side > 0)
			{
				rotate_b(st, 0);
				side--;
			}
		}
		push_a(st, 0);
		size--;
	}
}

static void	block_to_b(t_s_hold *st, int len, int blocksize, int curr)
{
	int			i;
	int			len2;
	int			side;

	i = 0;
	len2 = ft_lstlen(st->stack_a);
	while (i < blocksize && len2 > 0)
	{
		side = get_closest_dir(st->stack_a, curr, len);
		if (side > 0)
			while (*(int*)st->stack_a->content > curr)
				rotate_a(st, 0);
		else if (side < blocksize)
			while (*(int*)st->stack_a->content > curr)
				rev_rotate_a(st, 0);
		push_b(st, 0);
		i++;
		if (get_first(st->stack_b) < get_second(st->stack_b))
			swap_b(st, 0);
		len2--;
	}
}

void		sort_blocks(t_s_hold *st)
{
	int		len;
	int		curr;
	int		blocksize;

	len = ft_lstlen(st->stack_a);
	blocksize = len / 5;
	curr = blocksize;
	while (1)
	{
		block_to_b(st, len, blocksize, curr);
		if (blocksize > 5)
			blocksize -= blocksize / 5;
		if (curr == len)
			break ;
		else if (curr < len - blocksize)
			curr += blocksize;
		else
			curr += len - curr;
	}
	put_back(st, len);
}
