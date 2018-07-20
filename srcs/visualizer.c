/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 07:41:46 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/20 14:51:15 by gsteyn           ###   ########.fr       */
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

void		visualize1(t_s_hold *st)
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

void		visualize2(t_s_hold *st)
{
	int		x;
	int		y;
	int		curr;
	t_list	*tmp;

	x = 0;
	y = 1;
	curr = get_largest(st);
	//clear();
	mvprintw(0, 0, "Push_Swap Visualizer!");
	while (curr > 0)
	{
		x = 0;
		tmp = st->stack_b;
		while (tmp)
		{
			init_color(COLOR_GREEN, 0, *(int*)tmp->content * 10, 0);
			wattron(stdscr, COLOR_PAIR(1));
			if (*(int*)tmp->content >= curr)
				mvprintw(y, x, "#");
			else
				mvprintw(y, x, " ");
			tmp = tmp->next;
			x++;
		}
		wattron(stdscr, COLOR_PAIR(3));
		mvprintw(y, x, "|");
		x++;
		tmp = st->stack_a;
		while (tmp)
		{
			init_color(COLOR_GREEN, 0, *(int*)tmp->content * 10, 0);
			wattron(stdscr, COLOR_PAIR(1));
			if (*(int*)tmp->content >= curr)
			{
				mvprintw(y, x, "#");
			}
			else
				mvprintw(y, x, " ");
			tmp = tmp->next;
			x++;
		}
		y++;
		curr--;
	}
	refresh();
	usleep(3000);
}

void		get_color(int num, int max)
{
	if (num < max / 3)
		wattron(stdscr, COLOR_PAIR(1));
	else if (num < max / 3 * 2)
		wattron(stdscr, COLOR_PAIR(2));
	else
		wattron(stdscr, COLOR_PAIR(3));
}

void		visualize(t_s_hold *st)
{
	int		x;
	int		y;
	int		i;
	int		max;
	t_list	*tmp;

	tmp = st->stack_b;
	x = 0;
	y = 0;
	max = ft_lstlen(st->stack_a) + ft_lstlen(st->stack_b);
	wattron(stdscr, COLOR_PAIR(1));
	while (tmp)
	{
		i = max;
		y = *(int*)tmp->content;
		get_color(y, max);
		while (i > y)
		{
			mvprintw(i, x, "#");
			i--;
		}
		while (i >= 0)
		{
			wattron(stdscr, COLOR_PAIR(5));
			mvprintw(i, x, " ");
			i--;
		}
		refresh();
		x++;
		tmp = tmp->next;
	}
	i = max;
	wattron(stdscr, COLOR_PAIR(4));
	while (i >= 0)
		mvprintw(i--, x, "|");
	x++;
	tmp = st->stack_a;
	while (tmp)
	{
		i = max;
		y = *(int*)tmp->content;
		get_color(y, max);
		while (i > y)
		{
			mvprintw(i, x, "#");
			i--;
		}
		while (i >= 0)
		{
			wattron(stdscr, COLOR_PAIR(5));
			mvprintw(i, x, " ");
			i--;
		}
		refresh();
		x++;
		tmp = tmp->next;
	}
	refresh();
	usleep(300);
}
