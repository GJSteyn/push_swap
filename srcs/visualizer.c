/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 07:41:46 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/21 13:38:18 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		get_color(int num, int max)
{
	if (num < max / 3)
		wattron(stdscr, COLOR_PAIR(1));
	else if (num < max / 3 * 2)
		wattron(stdscr, COLOR_PAIR(2));
	else
		wattron(stdscr, COLOR_PAIR(3));
}

static void		print_stack(t_list *lst, int *x, int y, int max)
{
	int			i;

	while (lst)
	{
		i = max;
		y = *(int*)lst->content;
		get_color(y, max);
		while (i > y)
		{
			mvprintw(i, *x, "#");
			i--;
		}
		while (i >= 1)
		{
			wattron(stdscr, COLOR_PAIR(5));
			mvprintw(i, *x, " ");
			i--;
		}
		refresh();
		(*x)++;
		lst = lst->next;
	}
}

void			visualize(t_s_hold *st)
{
	int		x;
	int		y;
	int		i;
	int		max;
	t_list	*tmp;

	tmp = st->stack_b;
	x = 0;
	y = 0;
	mvprintw(0, 0, "Push_Swap Visualizer!");
	max = ft_lstlen(st->stack_a) + ft_lstlen(st->stack_b);
	wattron(stdscr, COLOR_PAIR(1));
	print_stack(st->stack_b, &x, y, max);
	i = max;
	wattron(stdscr, COLOR_PAIR(4));
	while (i >= 1)
		mvprintw(i--, x, "|");
	x++;
	tmp = st->stack_a;
	print_stack(st->stack_a, &x, y, max);
	usleep(300);
}
