#include "push_swap.h"

void		simplify(t_list *ops)
{
	t_list	*tmp;
	char	*curr;
	char	*next;

	if (!ops)
		return ;
	tmp = ops;
	while (tmp->next)
	{
		curr = (char*)tmp->content;
		next = (char*)tmp->next->content;
		if ((RA(curr) && RB(next)) || (RB(curr) && RA(next)))
		{
			lst_rem_next(tmp);
			ft_memcpy(tmp->content, "rr\0", 3);
		}
		else if ((SA(curr) && SB(next)) || (SB(curr) && SA(next)))
		{
			lst_rem_next(tmp);
			ft_memcpy(tmp->content, "ss\0", 3);
		}
		tmp = tmp->next;
	}
}
