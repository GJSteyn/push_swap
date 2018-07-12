#include "push_swap.h"

void		lst_rem_next(t_list *lst)
{
	if (!lst)
		return ;
	if (!lst->next)
		return ;
	lst->next = lst->next->next;
	// to do: free removed list item
}
