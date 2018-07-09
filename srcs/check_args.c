/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:29:03 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/09 13:59:21 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap.h"

int		args_valid(int arc, char **arv)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (arc == 1)
		return (0);
	while (++i < arc)
	{
		split = ft_strsplit(arv[i], ' ');
		while (split[++j])
		{
			if (!ft_is_num(split[j]))
			{
				ft_strldel(&split);
				return (0);
			}
		}
		if (!args_are_ints(arc, arv))
			return (0);
		ft_strldel(&split);
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

//int		no_duplicates(
