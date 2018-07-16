#include "push_swap.h"


		if (ft_lstlen(st->stack_a) < curr * 2)
		{
			sort_a(st);
			merge_to_b(st, ft_lstlen(st->stack_a));
		}

static void	sort_a_top2(t_s_hold *st)
{
	if (get_first(st->stack_a) > get_second(st->stack_a))
		swap_a(st);
}

static void	sort_a_top2_rev(t_s_hold *st)
{
	if (get_first(st->stack_a) < get_second(st->stack_a))
		swap_a(st);
}

static void	merge_to_b(t_s_hold *st, int left, int right)
{
	int		total;


	total = left + right;
	while (total > 0)
	{
		if (left > 0)
		{
			if (get_first(st->stack_a) > get_first(st->stack_b))
			{
				push_b_bot(st);
				left--;
				total--;
			}
			else
			{
				rotate_b(st);
				total--;
			}
		}
		else
			while (total > 0)
				rotate_b(st);
	}
}

// I'm not even sure if this would work. Too tired right now to think straight.
static void	sort_a_remain(t_s_hold *st, int i)
{
	while (!is_sorted_rev(st->stack_a))
	{
		if (get_first(st->stack_a) < get_second(st->stack_a))
			swap_a(st);
		else if (get_first(st->stack_a) < get_last(st->stack_a))
			rev_rotate_a(st);
		else
		{
			push_b(st);
			i++;
		}
	}
	while (i > 0)
	{
		push_a(st);
		i--;
		if (!is_sorted_rev(st->stack_a))
			sort_a_remain(st, i);
	}
}

void		merge_sort(t_s_hold *st)
{
	int		curr;

	curr = 2;
	while (ft_lstlen(st->stack_a) > curr * 2)
	{
		sort_a_top2(st);
		push_b(st);
		push_b(st);
		sort_a_top2_rev(st);
		merge_to_b(st, curr, curr);
	}
	if (ft_lstlen(st->stack_a) < curr * 2 && ft_lstlen(st->stack_a) != 0)
	{
		sort_a_remain(st, 0);
		merge_to_b(st, ft_lstlen(st->stack_a), curr * 2);
	}
	curr *= 2;
	while (ft_lstlen(st->stack_b) > curr * 2)
	{
		merge_to_a(st, curr, curr
		//sort_a_top2(st);
		//push_b(st);
		//push_b(st);
		//sort_a_top2_rev(st);
		//merge_to_b(st, curr, curr);
	}
}

// To do: Instead of legit merge sorting, first try and improve the previous merge
// algorithm by reading the values back to a more efficiently. Do this by reading
// them to a in much the same way you read them to b. Find the next one and the
// closest path to it, rotate there and push it back.
