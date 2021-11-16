#include "common.h"

void	ft_pa_wrap(t_stack **a, t_stack **b)
{
	ft_push_stack(a, b);
}

void	ft_sa_wrap(t_stack **a, t_stack **b)
{
	(void)b;
	ft_swap_stack(a);
}

void	ft_ra_wrap(t_stack **a, t_stack **b)
{
	(void)b;
	ft_rotate_stack(a);
}

void	ft_rra_wrap(t_stack **a, t_stack **b)
{
	(void)b;
	ft_rev_rotate_stack(a);
}
