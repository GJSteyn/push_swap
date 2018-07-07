/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:57:14 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/07 12:11:07 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

/* Is sorted:
 * Determine whether a list is sorted in ascending order.
 */

int			is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (*((int*)(lst->content)) >= *((int*)(lst->next->content)))
			return (0);
		lst = lst->next;
	}
	return (1);
}

/* Is sorted reverse:
 * Determine whether a list is sorted in descending order.
 */

int			is_sorted_rev(t_list *lst)
{
	while (lst->next)
	{
		if (*((int*)(lst->content)) <= *((int*)(lst->next->content)))
			return (0);
		lst = lst->next;
	}
	return (1);
}
