/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:57:14 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/12 08:45:38 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

/*
** Is sorted:
** Determine whether a list is sorted in ascending order.
*/

int			is_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (tmp)
	{
		while (tmp->next)
		{
			if (*((int*)(tmp->content)) >= *((int*)(tmp->next->content)))
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

/*
** Is sorted reverse:
** Determine whether a list is sorted in descending order.
*/

int			is_sorted_rev(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (*((int*)(tmp->content)) <= *((int*)(tmp->next->content)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
