#include "libft.h"
#include "checker.h"
#include "push_swap.h"

int		args_valid(int arc, char **arv)
{
	int		i;

	i = 1;
	while (i < arc)
	{
		if (!ft_only_digits(arv[i]))
			return (0);
	}
	return (1);
}
