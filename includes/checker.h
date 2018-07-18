/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:30:19 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/18 16:03:01 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "get_next_line.h"
# include "push_swap.h"
# include <unistd.h>
# include <stdlib.h>

int					args_valid(int arc, char **arv);
int					is_option(char *arg);

int					is_sorted(t_list *lst);
int					is_sorted_rev(t_list *lst);

int					has_duplicates(t_list *lst);

#endif
