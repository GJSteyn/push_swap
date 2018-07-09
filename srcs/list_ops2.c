/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 05:23:57 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/09 05:23:58 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/* Append:
 * Appends a list item to the end of a list.
 */

void		lst_append(t_list *dst, t_list *ins)
{
	if (dst && ins)
	{
		while (dst->next)
			dst = dst->next;
		dst->next = ins;
	}
}

/* Insert:
 * Inserts a list item between two existing list items.
 */

void		lst_insert(t_list *dst, t_list *ins)
{
	if (dst && ins)
	{
		ins->next = dst->next;
		dst->next = ins;
	}
}
