/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 06:57:50 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/13 06:57:51 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		lst_rem_next(t_list *lst)
{
	if (!lst)
		return ;
	if (!lst->next)
		return ;
	lst->next = lst->next->next;
	// to do: free removed list item
}
