/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:29:03 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/03 11:53:28 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap.h"

int		args_valid(int arc, char **arv)
{
	int		i;

	i = 1;
	while (i < arc)
	{
		if (!ft_only_digits(arv[i]) || !args_are_ints()
			return (0);
	}
	return (1);
}

int		args_are_ints(int arc, char **arv)
{
	int			i;
	long		result;

	i = 0;
	while (++i < arc)
	{
		result = ft_atoi(arv[i]);
		if (result > 2147483647 || result < -2147483648)
			return (0);
	}
	return (1);
}

int		no_duplicates(
