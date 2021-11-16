#include "common.h"

static void	ft_print_footer(void)
{
	ft_putchar('\t');
	ft_putchar('a');
	ft_putchar('\t');
	ft_putchar('b');
	ft_putchar('\n');
}

static int	ft_condition_printing(t_stack *stack, int max_depth)
{
	int stack_depth;

	stack_depth = ft_stack_depth(stack);
	ft_putchar('\t');
	if (stack_depth > max_depth && stack)
	{
		ft_putnbr(stack->nbr);
		return (1);
	}
	ft_putchar(' ');
	return (0);
}

//	static int	ft_condition_printing_b(t_stack *stack, int max_depth)
//	{
//		int stack_depth;
//	
//		stack_depth = ft_stack_depth(stack);
//		ft_putchar('\t');
//		if (stack_depth > max_depth && stack)
//		{
//			ft_putnbr(stack->nbr);
//			return (1);
//		}
//		ft_putchar(' ');
//		return (0);
//	}

int		ft_max_depth_stack(t_stack *a, t_stack *b)
{
	int max_depth;
	int depth_a;
	int depth_b;

	depth_a = ft_stack_depth(a);
	depth_b = ft_stack_depth(b);
	max_depth = (depth_a > depth_b ? depth_a : depth_b);
	return (max_depth);
}

void		ft_print_stacks(t_stack *a, t_stack *b)
{
	int depth_max;

	depth_max = ft_max_depth_stack(a, b);
	ft_putchar('\n');
	ft_putchar('\n');
	while (depth_max--)
	{
		if (ft_condition_printing(a, depth_max))
			a = a->prev;
		if (ft_condition_printing(b, depth_max))
			b = b->prev;
		ft_putchar('\n');
	}
	ft_print_footer();
}
