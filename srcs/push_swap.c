#include "libft.h"
#include "get_next_line.h"
#include "push_swap.h"

int		main(int arc, char **arv)
{
	int		i;

	i = 1;
	while (i < arc)
	{
		if (!ft_only_digits(arv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	}
	return (0);
}
