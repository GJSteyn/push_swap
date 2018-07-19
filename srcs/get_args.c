/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 05:23:14 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/19 07:55:23 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
** Get Args:
** Retrieves the arguments fed from terminal and
** returns them in a list.
*/

t_list		*get_args(int arc, char **arv)
{
	t_list		*ret;
	t_list		*tmp;
	char		**split;
	int			i;
	int			j;

	i = 0;
	ret = NULL;
	while (++i < arc)
	{
		j = -1;
		split = ft_strsplit(arv[i], ' ');
		while (split[++j])
		{
			if (!ret)
				ret = ft_lstnew(split[j], ft_strlen(split[j]));
			else
			{
				tmp = ft_lstnew(split[j], ft_strlen(split[j]));
				lst_append(&ret, tmp);
			}
		}
		ft_strldel(&split);
	}
	return (ret);
}

/* Sorted Insert:
** Inserts list items into an existing list
** in ascending order.
*/

static void	sorted_insert(t_list **dst, t_list *insert)
{
	int		largest;
	int		smallest;
	t_list	*tmp;

	tmp = *dst;
	smallest = *(int*)tmp->content;
	while (tmp->next)
		tmp = tmp->next;
	largest = *(int*)tmp->content;
	if (*(int*)insert->content < smallest)
		lst_push(dst, &insert);
	else if (*(int*)insert->content > largest)
		lst_append(dst, insert);
	else
	{
		tmp = *dst;
		while (*(int*)tmp->next->content < *(int*)insert->content)
			tmp = tmp->next;
		lst_insert(tmp, insert);
	}
}

/*
** Get Sorted Args:
** Retrieves the arguments fed from terminal and
** returns them in a list with integers as content,
** while sorting them in ascending order in the process.
*/

t_list		*get_sorted_args(t_list *args)
{
	t_list		*ret;
	int			num;
	char		*curr;

	ret = NULL;
	if (!args)
		return (NULL);
	while (args)
	{
		curr = (char*)args->content;
		if (!is_option(curr))
		{
			num = ft_atoi(curr);
			if (!ret)
				ret = ft_lstnew(&num, sizeof(int));
			else
				sorted_insert(&ret, ft_lstnew(&num, sizeof(int)));
		}
		args = args->next;
	}
	return (ret);
}
