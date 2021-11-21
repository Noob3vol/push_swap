/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:09:54 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/20 20:09:55 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "push_swap.h"
#include "checker.h"

void	ft_clean_stacks(t_stack *a, t_stack *b)
{
	ft_free_stack(&a);
	ft_free_stack(&b);
}

void	ft_clean_all(t_stack *a, t_stack *b, t_list *inst)
{
	ft_clean_stacks(a, b);
	ft_lstclear(&inst, free);
}

void	ft_check_stack_sort(t_stack *a, t_stack *b)
{
	if (!ft_stack_issort(a) || ft_stack_depth(b))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	ft_clean_stacks(a, b);
}

void	ft_print_arg(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
		ft_putendl(av[i]);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*inst;

	b = NULL;
	inst = NULL;
	if (ac == 1)
		return (0);
	a = ft_store_stack(ac - 1, &av[1]);
	if (!(a))
		return (-1);
	if (!(ft_store_inst(&inst)))
		return (-1);
	if (inst)
	{
		if (!(ft_run_inst(&a, &b, inst)))
		{
			ft_clean_all(a, b, inst);
			return (-1);
		}
	}
	ft_check_stack_sort(a, b);
	ft_lstclear(&inst, (void (*)(void *))free);
	return (0);
}
