/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:57:13 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/04 08:00:58 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/* Swap:
 * Swap the first two element at the top of a stack.
 * Do nothing if there is only one or no elements.
 */

void		lst_swap(t_list **lst)
{
	if (lst && lst->next)
	{
		lst->next = lst->next->next;
		lst->next->next = lst;
	}
}

t_list		*lst_pop(t_list **lst)
{
	t_list		*ret;

	if (*lst)
	{
		ret = *lst;
		*lst = (*lst)->next;
		ret->next = NULL;
		return (ret);
	}
	return (NULL);
}

void		lst_push(t_list **dst, t_list **src)
{
	t_list		*tmp;

	if (*dst && *src)
	{
		tmp = lst_pop(src);
		tmp->next = *dst;
		*dst = tmp;
	}
}
