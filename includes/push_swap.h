/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:30:02 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/10 08:22:52 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"
# include "checker.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void					lst_swap(t_list **lst);
t_list					*lst_pop(t_list **lst);
void					lst_push(t_list **dst, t_list **src);
void					lst_rotate(t_list **lst);
void					lst_rev_rotate(t_list **lst);
void					lst_append(t_list *dst, t_list *ins);
void					lst_insert(t_list *dst, t_list *ins);

t_list					*get_args(int arc, char **arv);

void					run_instructions(t_list *args);
void					do_op(t_list *args, char *op);

#endif
