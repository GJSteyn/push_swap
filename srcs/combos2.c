/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combos2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:40:44 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/13 11:04:50 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort ends b:
** Order first and last elements.
*/

void	sort_ends_a(t_s_hold *st)
{
	if (get_last(st->stack_b) < get_first(st->stack_b))
		rotate_b(st);
}
