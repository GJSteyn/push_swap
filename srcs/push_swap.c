/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:29:23 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/06 11:54:33 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "push_swap.h"

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
	while (args)
	{
		ft_putnbr(*((int*)(args->content)));
		ft_putchar('\n');
		args = args->next;
	}
	return (0);
}
