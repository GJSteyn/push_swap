/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 07:08:54 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/12 07:26:32 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		normlist(t_list *chaos, t_list *order)
{
	int			i;
	int			curr;
	int			curr_o;
	t_list		*tmp;

	while (chaos)
	{
		i = 1;
		tmp = order;
		curr = *(int*)chaos->content;
		while (tmp)
		{
			curr_o = *(int*)tmp->content;
			if (curr == curr_o)
			{
				ft_memcpy(chaos->content, &i, sizeof(int));
				break ;
			}
			i++;
			tmp = tmp->next;
		}
		chaos = chaos->next;
	}
}
