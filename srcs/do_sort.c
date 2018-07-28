/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:33:05 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/28 18:36:18 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_sort(t_s_hold *st)
{
	int			arglen;

	arglen = ft_lstlen(st->args);
	if (arglen > 5)
		sort_blocks(st);
	else if (arglen == 5)
		sort5(st);
	else
		push_and_swap(st);
}
