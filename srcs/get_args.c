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
	int		i;

	ret = ft_lstnew(ft_atoi(arv[1]), sizeof(int));
	i = 1;
	while (++i < arc)
	{
		tmp = ft_lstnew(ft_atoi(arv[i]), sizeof(int));
		lst_append(ret, tmp);
	}
	return (ret);
}
