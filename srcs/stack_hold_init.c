/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_hold_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 08:45:35 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/18 17:27:03 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

/* Get Stack A:
** Parses the arguments received in list form and retrieves all the
** integer values in the order they were fed into the command line.
*/

static t_list		*get_stack_a(t_list *args)
{
	t_list		*stack_a;
	int		curr;

	stack_a = NULL;
	if (args)
	{
		while (args)
		{
			if (!is_option((char*)args->content))
			{
				curr = ft_atoi((char*)args->content);
				if (!stack_a)
					stack_a = ft_lstnew(&curr, sizeof(int));
				else
					lst_append(stack_a, ft_lstnew(&curr, sizeof(int)));
			}
			args = args->next;
		}
	}
	return (stack_a);
}

/* Get Options:
** Current available options: -v -> debugger.
*/

static unsigned int	get_options(t_list *args)
{
	unsigned int		options;
	char			*curr;
	unsigned int		add;

	options = 0;
	if (!args)
		return (0);
	while (args)
	{
		curr = (char*)args->content;
		if (is_option(curr) && ft_islower(curr[1]))
		{
			add = ft_2pow(curr[1] - 'a');
			if (!(add & options))
				options += add;
		}
		args = args->next;
	}
}

/* Stack Hold Init:
** Initializes the struct that holds both stacks, as well as the arguments
** and the options if they occur within the arguments.
** Stack b gets initialized to NULL while stack a will contain all the
** integer value arguments retrieved from args.
*/

t_s_hold		*sh_init(t_list *args)
{
	t_s_hold		*ret;

	ret = (t_s_hold*)malloc(sizeof(t_s_hold));
	ret->args = args;
	ret->stack_a = get_stack_a(args);
	ret->stack_b = NULL;
	ret->ops = NULL;
	ret->options = get_options(args);
	return (ret);
}
