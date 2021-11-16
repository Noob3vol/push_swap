#include "push_swap.h"

/*
 ** Partitionning system : a lot of optimization can be done at this level
 */

int	ft_quickpiv(t_stack **a, t_stack **b, t_stkpart *info, t_list **inst)
{
	if ((*a)->nbr >= info->pivot->nbr && (*a) != *(info->end))
	{
		*inst = ft_exec_op(*inst, a, b, "pb");
		if (!(*inst))
			return (0);
	}
	else
	{
		if (!info->next_debut)
			info->next_debut = (*a);
		*inst = ft_exec_op(*inst, a, b, "ra");
		if (!(*inst))
			return (0);
	}
	return (1);
}

int	ft_quickpivot_l(t_stack **a, t_stack **b, t_stkpart *nfo, t_list **inst)
{
	while ((*a) != *(nfo->end) && (*b) != nfo->pivot)
	{
		if (!ft_quickpiv(a, b, nfo, inst))
			return (0);
//		ft_print_stacks(*a, *b);
	}
	if ((*b) == nfo->pivot)
	{
		(*inst) = ft_exec_op((*inst), a, b, "rb");
		if (!*inst)
			return (0);
	}
	return (1);
}

int	ft_quickpivot_h(t_stack **a, t_stack **b, t_stkpart *nfo, t_list **inst)
{
//	while ((*a) != *(nfo->end))
	while (!ft_part_check_h(*a, nfo->pivot, *(nfo->end)))
	{
		if (!(ft_quickpiv(a, b, nfo, inst)))
			return (0);
//		ft_print_stacks(*a, *b);
	}
	if ((*a) == *(nfo->end) && (*a)->nbr <= nfo->pivot->nbr)
	{
		(nfo->next_end) = *(b);
		*inst = ft_exec_op(*inst, a, b, "ra");
		if (!(inst))
				return (0);
	}
	return (1);
}

int	ft_quickpart(t_stack **a, t_stkpart *part_nfo, t_list **inst)
{
	t_stack		*b;

	b = NULL;
	if (!ft_quickpivot_l(a, &b, part_nfo, inst))
	{
		ft_putendl("Error 1");
		return (0);
	}
//	ft_putendl("####### LOW PART DONE #########");
	if (!ft_quickpivot_h(a, &b, part_nfo, inst))
	{
		ft_putendl("Error 2");
		return (0);
	}
//	ft_putendl("####### HIGH PART DONE #########");
//	ft_print_stacks(*a, b);
	*(inst) = ft_stack_push_all_b(a, &b, *(inst));
	if (!inst)
		return (0);
	return (1);
}

int	ft_quickpart_rec(t_stack **head, t_stkpart *nfo, t_list **inst)
{
	t_list		*inst_added;

//	ft_putendl("========= Stack init ===========");
//	ft_print_stacks(*head, NULL);
	if (!ft_check_pivot_parted(*head, nfo->pivot, *(nfo->end)))
	{
		if (!ft_quickpart(head, nfo, inst))
			return (0);
	}
//	ft_putendl("====================== after pivot =================");
//	ft_print_stkpart_info(*head, NULL, nfo);
	if (nfo->next_debut)
		*(nfo->debut) = nfo->next_debut;
	if (nfo->next_end)
		*(nfo->end) = nfo->next_end;
	inst_added = ft_quickrec(head, *(nfo->debut), *(nfo->end), nfo->pivot);
	if (!(inst_added))
	{
		ft_lstclear(inst, free);
		return (0);
	}
	ft_lstadd_back(inst, inst_added);
	free(nfo);
	return (1);
}

t_list	*ft_stack_quicksort(t_stack **head, t_stack *begin, t_stack *end)
{
	t_list			*inst;
	t_stkpart		*part_nfo;

	inst = NULL;
	if (!ft_quickprep(head, begin, end, &inst))
	{
		return (inst);
	}
	part_nfo = ft_stkpart_info(*head, &begin, &end);
	if (!ft_quickpart_rec(head, part_nfo, &inst))
		return (NULL);
	return (inst);
}

t_list	*ft_launch_quicksort(t_stack **a)
{
	t_list	*inst;
	t_list	*inst_added;

	inst = ft_stack_quicksort(a, *a, ft_stack_last_node(*a));
	inst_added = ft_crawl_stack(a, ft_stack_min(*a), 'a');
	ft_lstadd_back(&inst, inst_added);
//	ft_print_stacks(*a, NULL);
	return (inst);
}
