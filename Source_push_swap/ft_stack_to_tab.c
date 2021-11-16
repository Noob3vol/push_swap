/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:40:46 by iguidado          #+#    #+#             */
/*   Updated: 2021/10/30 14:16:45 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_stack_to_tab(t_stack *stack, int tab_len)
{
	int	*tab;
	int	i;

	tab = (int *)malloc(sizeof(int) * tab_len);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < tab_len && stack)
	{
		tab[i] = stack->nbr;
		stack = stack->prev;
		i++;
	}
	return (tab);
}

int	ft_quickpivot(int **tab, int begin, int end, int pivot)
{
	int	i;
	int	j;

	i = begin;
	if (pivot != end)
		ft_swapi(&(*tab)[pivot], &(*tab)[end]);
	while (i != end)
	{
		if ((*tab)[i] > (*tab)[end])
		{
			j = i;
			while ((*tab)[j] > (*tab)[end])
				j++;
			if (j != end)
				ft_swapi(&(*tab)[i], &(*tab)[j]);
		}
		i++;
	}
	i = begin;
	while ((*tab)[i] < (*tab)[end])
		i++;
	if (i != end)
		ft_swapi(&(*tab)[i], &(*tab)[end]);
	return (i);
}

int	*ft_quicksort(int *tab, int begin, int end)
{
	int	pivot;
	int	middle;

	if (end <= begin)
		return (tab);
	middle = (begin + end) / 2;
	pivot = ft_median_of_3_tab(tab, begin, (begin + end) / 2, end);
	pivot = ft_quickpivot(&tab, begin, end, pivot);
	ft_quicksort(tab, begin, pivot - 1);
	ft_quicksort(tab, pivot + 1, end);
	return (tab);
}

int	*ft_stack_tab_sort(t_stack *stack)
{
	int	*stack_tab;
	int	stack_len;

	stack_len = ft_stack_depth(stack);
	stack_tab = ft_stack_to_tab(stack, stack_len);
	if (!stack_tab)
		return (NULL);
	stack_tab = ft_quicksort(stack_tab, 0, stack_len - 1);
	return (stack_tab);
}
