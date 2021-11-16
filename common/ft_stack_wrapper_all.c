#include "common.h"

void	ft_ss_wrap(t_stack **a, t_stack **b)
{
	ft_swap_stack(a);
	ft_swap_stack(b);
}

void	ft_rr_wrap(t_stack **a, t_stack **b)
{
	ft_rotate_stack(a);
	ft_rotate_stack(b);
}

void	ft_rrr_wrap(t_stack **a, t_stack **b)
{
	ft_rev_rotate_stack(a);
	ft_rev_rotate_stack(b);
}
