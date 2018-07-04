/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:57:13 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/03 13:49:29 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/* Swap:
 * Swap the first two element at the top of a stack.
 * Do nothing if there is only one or no elements.
 */

t_list		*swap(t_list *lst)
{
	if (lst && lst->next)
	{
		lst->next = lst->next->next;
		lst->next->next = lst;
	}
}

t_list		*pop(t_list *dest, t_list *src)
{

}
