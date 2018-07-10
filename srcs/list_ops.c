/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:57:13 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/10 10:05:29 by gsteyn           ###   ########.fr       */
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
	t_list		*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = tmp->next;
		tmp->next = *lst;
		*lst = tmp;
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

	if (*src)
	{
		tmp = lst_pop(src);
		tmp->next = *dst;
		*dst = tmp;
	}
}

/* Rotate:
 * Shift up all elements of a stack by 1.
 * The first element becomes the last one.
 */

void		lst_rotate(t_list **lst)
{
	t_list		*tmp;
	t_list		*move;

	if (*lst)
	{
		if (ft_lstlen(*lst) > 1)
		{
			tmp = *lst;
			move = *lst;
			*lst = (*lst)->next;
			while (tmp->next)
				tmp = tmp->next;
			move->next = NULL;
			tmp->next = move;
		}
	}
}

/* Reverse Rotate:
 * Shift down all elements of a stack by 1.
 * The last element becomes the first one.
 */

void		lst_rev_rotate(t_list **lst)
{
	t_list		*tmp;
	t_list		*move;

	if (*lst)
	{
		if (ft_lstlen(*lst) == 1)
			return ;
		tmp = *lst;
		while (tmp->next)
		{
			if (!(tmp->next->next))
				break;
			tmp = tmp->next;
		}
		move = tmp->next;
		tmp->next = NULL;
		move->next = *lst;
		*lst = move;
	}
}
