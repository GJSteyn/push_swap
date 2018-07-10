/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_hold_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 08:45:35 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/10 08:54:33 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

t_s_hold		*sh_init(t_list *stack_a, t_list *stack_b)
{
	t_s_hold		*ret;

	ret = (t_s_hold*)malloc(sizeof(t_s_hold));
	ret->stack_a = stack_a;
	ret->stack_b = stack_b;
	return (ret);
}
