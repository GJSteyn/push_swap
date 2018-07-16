/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 08:12:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/16 08:45:35 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		recurse_quick(t_s_hold *st, int size1, int size2)
{

}

void			quicksort(t_s_hold * st)
{
	int			len;
	int			half1;
	int			half2;

	len = ft_lstlen(st->stack_a);
	half1 = len / 2;
	half2 = half1 + (len % 2);
	recurse_quick(st, half1, half2);
}
