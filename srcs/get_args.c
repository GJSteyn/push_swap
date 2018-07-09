/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 05:23:14 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/09 10:27:56 by gsteyn           ###   ########.fr       */
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
	j = -1;
	while (++i < arc)
	{
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
		//ft_strldel(&split);
	}
	return (ret);
}

/*	Old get_args. Might still be useful?
t_list		*get_args(int arc, char **arv)
{
	t_list		*ret;
	t_list		*tmp;
	int			curr;
	int			i;

	curr = ft_atoi(arv[1]);
	ret = ft_lstnew(&curr, sizeof(int));
	i = 1;
	while (++i < arc)
	{
		curr = ft_atoi(arv[i]);
		tmp = ft_lstnew(&curr, sizeof(int));
		lst_append(ret, tmp);
	}
	return (ret);
}
*/
