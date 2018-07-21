/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:56:00 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/21 16:29:47 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Get Options:
** Current available options: -d -> debugger; -v -> visualizer
*/

unsigned int	get_options(t_list *args)
{
	unsigned int		options;
	char				*curr;
	unsigned int		add;
	int					i;

	options = 0;
	if (!args)
		return (0);
	while (args)
	{
		i = 1;
		curr = (char*)args->content;
		if (is_option(curr) && ft_islower(curr[i]))
		{
			while (curr[i])
			{
				add = ft_2pow(curr[i++] - 'a');
				if (!(add & options))
					options += add;
			}
		}
		args = args->next;
	}
	return (options);
}

/* Has Debug Option:
** Checks whether the debug option has been set.
*/

int				has_debug_op(unsigned int options)
{
	if (ft_2pow('d' - 'a') & options)
		return (1);
	return (0);
}

/* Has Visualizer Option:
** Checks whether the visualizer option has been set.
*/

int				has_vis_op(unsigned int options)
{
	if (ft_2pow('v' - 'a') & options)
		return (1);
	return (0);
}
