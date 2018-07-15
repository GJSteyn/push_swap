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

void		sort4(t_s_hold *st)
{
	int		len;
	int		len2;
	int		curr;
	int		i;
	int		side;

	len = ft_lstlen(st->stack_a);
	curr = 4;
	while (1)
	{
		len2 = ft_lstlen(st->stack_a);
		i = 0;
		while (i < 4 && len2 > 0)
		{
			side = get_closest_dir(st->stack_a, curr, len);
			if (side > 0)
			{
				while (*(int*)st->stack_a->content > curr)
				{
					rotate_a(st);
				}
			}
			else if (side < 0)
			{
				while (*(int*)st->stack_a->content > curr)
				{
					rev_rotate_a(st);
				}
			}
			push_b(st);
			i++;
			if (get_first(st->stack_b) < get_second(st->stack_b))
				swap_b(st);
			len2--;
		}
		if (curr == len)
			break ;
		else if (curr <= len - 4)
			curr += 4;
		else
			curr += len - curr;
	}
	put_back(st);
}
