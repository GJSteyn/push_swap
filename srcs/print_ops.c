/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 07:46:54 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/19 07:49:14 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_ops(t_list *ops)
{
	if (!ops)
		return ;
	while (ops)
	{
		ft_putstr_fd((char*)ops->content, 1);
		ft_putchar_fd('\n', 1);
		ops = ops->next;
	}
}
