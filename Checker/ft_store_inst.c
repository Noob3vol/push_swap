#include "common.h"

int	ft_store_inst(t_list **inst)
{
	char	*line;
	t_list	*new;

	while (get_next_line(0, &line))
	{
		if (!(new = ft_lstnew(line)))
		{
			free(line);
			ft_lstclear(inst, free);
			return (0);
		}
		ft_lstadd_back(inst, new);
	}
	if (*(line))
	{
		if (!(new = ft_lstnew(line)))
		{
			free(line);
			ft_lstclear(inst, free);
			return (0);
		}
		ft_lstadd_back(inst, new);
	}
	else
		free(line);
	return (1);
}

int	ft_run_inst(t_stack **a, t_stack **b, t_list *inst)
{
	t_stacks_op op;

	while (inst)
	{
		if (!(op = ft_get_op(inst->content)))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		op(a, b);
		inst = inst->next;
	}
	return (1);
}
