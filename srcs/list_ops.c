/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:57:13 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/04 16:47:51 by gsteyn           ###   ########.fr       */
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

/* Pop:
 * Removes the first item in a list and returns it.
 * The second item, if it exists, becomes the new top.
 */

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

/* Push:
 * Take the first element at the top of a list and
 * put it at the top of another. Do nothing if the
 * source list is empty.
 */

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
