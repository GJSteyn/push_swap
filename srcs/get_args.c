/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 05:23:14 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/10 07:18:19 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/* Get Args
 * Retrieves the arguments fed from terminal and
 * returns them in a list with integers as content.
 */

t_list		*get_args(int arc, char **arv)
{
	t_list		*ret;
	t_list		*tmp;
	char		**split;
	int			i;
	int			j;
	int			curr;

	i = 0;
	while (++i < arc)
	{
		j = -1;
		split = ft_strsplit(arv[i], ' ');
		while (split[++j])
		{
			curr = ft_atoi(split[j]);
			if (!ret)
				ret = ft_lstnew(&curr, sizeof(int));
			else
			{
				tmp = ft_lstnew(&curr, sizeof(int));
				lst_append(ret, tmp);
			}
		}
		ft_strldel(&split);
	}
	return (ret);
}
