/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:51:58 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/23 16:09:14 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

void			print_usage(void)
{
	int		fd;
	char	*in;

	fd = open("srcs/usage.txt", O_RDONLY);
	ft_putchar_fd('\n', 2);
	while (get_next_line(fd, &in) > 0)
	{
		ft_putendl_fd(in, 2);
		ft_strdel(&in);
	}
	ft_putchar_fd('\n', 2);
	close(fd);
	exit(1);
}
