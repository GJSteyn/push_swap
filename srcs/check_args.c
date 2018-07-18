/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:29:03 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/18 16:03:22 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap.h"

int			is_option(char *arg)
{
	if (ft_strlen(arg) < 2)
		return (0);
	else if (arg[0] == '-' && ft_isalpha(arg[1]))
		return (1);
}

static int		arg_is_int(char *arg)
{
	long		result;

	result = ft_atol(arg);
	if (result > 2147483647 || result < -2147483648)
		return (0);
	return (1);
}

static int		args_are_nums(char **args)
{
	int		i;

	i = -1;
	while (args[++i])
	{
		if (is_option(args[i]))
			continue ;
		if (!ft_is_num(args[i]))
			return (0);
		if (!arg_is_int(args[i]))
			return (0);
	}
	return (1);
}

int				args_valid(int arc, char **arv)
{
	char	**split;
	int		i;

	i = 0;
	if (arc == 1)
		return (0);
	while (++i < arc)
	{
		split = ft_strsplit(arv[i], ' ');
		if (!args_are_nums(split))
		{
			ft_strldel(&split);
			return (0);
		}
		ft_strldel(&split);
	}
	return (1);
}
