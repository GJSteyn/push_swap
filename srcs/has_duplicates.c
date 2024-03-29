/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_duplicates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 07:02:34 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/19 07:45:04 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			has_duplicates(t_list *lst)
{
	int			curr;
	t_list		*tmp;

	if (!lst)
		return (0);
	while (lst)
	{
		tmp = lst;
		curr = *(int*)tmp->content;
		while (tmp->next)
		{
			if (curr == *(int*)(tmp->next->content))
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}
