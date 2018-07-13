/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 05:23:57 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/13 07:00:42 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
** Append:
** Appends a list item to the end of a list.
*/

void		lst_append(t_list **dst, t_list *ins)
{
	t_list		*tmp;

	if (!(*dst) && ins)
		*dst = ins;
	else if (*dst && ins)
	{
		tmp = *dst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ins;
	}
}

/*
** Insert:
** Inserts a list item between two existing list items.
*/

void		lst_insert(t_list *dst, t_list *ins)
{
	if (dst && ins)
	{
		ins->next = dst->next;
		dst->next = ins;
	}
}

/*
** Get last:
** Retrieves the integer value of the last element's
** content from a list.
*/

int			get_last(t_list *lst)
{
	int		ret;
	t_list	*tmp;

	ret = 0;
	tmp = lst;
	if (lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		ret = *(int*)tmp->content;
	}
	return (ret);
}

/*
** Get first:
** Retrieves the integer value of the first element's
** content from a list.
*/

int			get_first(t_list *lst)
{
	int		ret;

	ret = 0;
	if (lst)
		ret = *(int*)lst->content;
	return (ret);
}

/*
** Get second:
** Retrieves the integer value of the second element's
** content from a list if there is a second element.
*/

int			get_second(t_list *lst)
{
	int		ret;

	ret = 0;
	if (lst)
	{
		if (lst->next)
		{
			ret = *(int*)lst->next->content;
		}
	}
	return (ret);
}
