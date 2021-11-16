#include "common.h"

void	ft_pb_wrap(t_stack **a, t_stack **b)
{
	ft_push_stack(b, a);
}

void	ft_sb_wrap(t_stack **a, t_stack **b)
{
	(void)a;
	ft_swap_stack(b);
}

void	ft_rb_wrap(t_stack **a, t_stack **b)
{
	(void)a;
	ft_rotate_stack(b);
}

void	ft_rrb_wrap(t_stack **a, t_stack **b)
{
	(void)a;
	ft_rev_rotate_stack(b);
}
