/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:57:14 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/06 12:00:43 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int			is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if ((int*)(lst->content) >= (int*)(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}
