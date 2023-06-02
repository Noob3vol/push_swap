/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:34:13 by iguidado          #+#    #+#             */
/*   Updated: 2021/12/13 21:35:03 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_inst(t_stack **a, int index)
{
	t_list			*inst;
	static t_list	*(*ft_sort[])(t_stack **) = {
		ft_stack_sort_bubble_max_a,
		ft_stack_sort_slct,
		ft_stack_srt_insrt,
		ft_launch_quicksort,
		NULL};

	if (!ft_sort[index])
		return (NULL);
	inst = ft_sort[index](a);
	return (inst);
}

t_list	*ft_select_inst(t_list *inst, t_list *next_inst, t_stack *a)
{
	int	len_inst;
	int	len_inst_next;

	if (!next_inst)
		return (inst);
	if (!inst)
		return (next_inst);
	len_inst = ft_lstlen(inst);
	len_inst_next = ft_lstlen(next_inst);
	if (len_inst > len_inst_next && ft_stack_issort(a))
	{
		ft_lstclear(&inst, free);
		return (next_inst);
	}
	ft_lstclear(&next_inst, free);
	return (inst);
}

t_list	*ft_choose(t_stack **a)
{
	t_stack	*a_copy;
	t_list	*inst;
	t_list	*next_inst;
	int		i;

	i = 0;
	a_copy = ft_copy_stack(*a);
	inst = ft_get_inst(&a_copy, 0);
	ft_free_stack(&a_copy);
	a_copy = ft_copy_stack(*a);
	next_inst = ft_get_inst(&a_copy, ++i);
	while ((next_inst))
	{
		inst = ft_select_inst(inst, next_inst, a_copy);
		ft_free_stack(&a_copy);
		a_copy = ft_copy_stack(*a);
		next_inst = ft_get_inst(&a_copy, ++i);
	}
	ft_free_stack(&a_copy);
	ft_free_stack(a);
	return (inst);
}

int	ft_check_ubiquity(t_stack *a)
{
	t_stack	*header;
	t_stack	*curr;

	curr = a;
	while (curr->prev)
	{
		header = curr->prev;
		while (header)
		{
			if (curr->nbr == header->nbr)
			{
				ft_putendl("Error");
				ft_free_stack(&a);
				return (0);
			}
			header = header->prev;
		}
		curr = curr->prev;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_list	*inst;

	inst = NULL;
	a = NULL;
	if (ac == 1)
		return (0);
	a = ft_store_stack(ac - 1, av + 1);
	if (!(a) || !(ft_check_ubiquity(a)))
	{
		return (-1);
	}
	if (ft_stack_issort(a))
		return (ft_free_stack(&a));
	if (ac > 130)
		inst = ft_launch_quicksort(&a);
	else
		inst = ft_choose(&a);
	ft_lstiter(inst, ft_print_inst);
	ft_lstclear(&inst, (void (*)(void *))free);
	return (0);
}
