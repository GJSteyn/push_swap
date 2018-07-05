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
