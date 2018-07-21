/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:29:03 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/21 17:26:48 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap.h"

int				is_option(char *arg)
{
	if (ft_strlen(arg) < 2)
		return (0);
	else if (arg[0] == '-' && ft_isalpha(arg[1]))
		return (1);
	return (0);
}

int				is_op(char *arg)
{
	if (SA(arg))
		return (1);
	else if (SB(arg))
		return (1);
	else if (SS(arg))
		return (1);
	else if (PA(arg))
		return (1);
	else if (PB(arg))
		return (1);
	else if (RA(arg))
		return (1);
	else if (RB(arg))
		return (1);
	else if (RR(arg))
		return (1);
	else if (RRA(arg))
		return (1);
	else if (RRB(arg))
		return (1);
	else if (RRR(arg))
		return (1);
	else
		return (0);
}

static int		arg_is_int(char *arg)
{
	long		result;

	result = ft_atol(arg);
	if (result > 2147483647 || result < -2147483648)
		return (0);
	return (1);
}

static int		arg_is_valid(char *arg)
{
	if (is_option(arg))
		return (1);
	if (!ft_is_num(arg))
		return (0);
	if (!arg_is_int(arg))
		return (0);
	return (1);
}

int				args_valid(int arc, t_list *args)
{
	char		*curr;

	if (arc == 1)
		return (0);
	while (args)
	{
		curr = (char*)args->content;
		if (!arg_is_valid(curr))
			return (0);
		args = args->next;
	}
	return (1);
}
