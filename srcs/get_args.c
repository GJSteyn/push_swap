/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 05:23:14 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/12 08:45:08 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
** Get Args
** Retrieves the arguments fed from terminal and
** returns them in a list with integers as content.
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
	ret = NULL;
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
		lst_append(*dst, insert);
	else
	{
		tmp = *dst;
		while (*(int*)tmp->next->content < *(int*)insert->content)
			tmp = tmp->next;
		lst_insert(tmp, insert);
	}
}

t_list		*get_sorted_args(int arc, char **arv)
{
	t_list		*ret;
	t_list		*tmp;
	char		**split;
	int			i;
	int			j;
	int			curr;

	i = 0;
	ret = NULL;
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
				sorted_insert(&ret, tmp);
			}
		}
		ft_strldel(&split);
	}
	return (ret);
}
