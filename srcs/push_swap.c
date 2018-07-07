/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:29:23 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/07 12:03:25 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int		main(int arc, char **arv)
{
	int		i;
	t_list	*args;

	i = 1;
	if (!args_valid(arc, arv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	args = get_args(arc, arv);
	if (is_sorted(args))
		ft_putstr_fd("Sorted\n", 2);
	else
		ft_putstr_fd("Not sorted\n", 2);
	return (0);
}
