#include "common.h"
#include "libft.h"
#include <limits.h>

/*
 * Nbr n'est jamais negatif donc nbr == INT_MIN trigger directement
 * la condition rejetant les nombres superieur a INT_MAX
 */

int     predict_overflow(int nbr, char next_digit, int neg)
{
	if (!ft_isdigit(next_digit))
		return (0);
	if (neg < 0)
	{
		if (nbr >= INT_MAX / 10 && next_digit == '9')
			return (1);
	}
	else
		if (nbr >= INT_MAX / 10 && next_digit >= '8')
			return (1);
	return (0);
}

int	ft_atoi_crawl(char **str, int *origin_nbr)
{
	int neg;
	int nbr;

	neg = 1;
	nbr = 0;
	while (**str == ' ')
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			neg *= -1;
		(*str)++;
	}
	if (!ft_isdigit(**str))
		return (0);
	while (**str >= '0' && **str <= '9')
	{
		if (predict_overflow(nbr, **str, neg))
			return (0);
		nbr *= 10;
		nbr += **str - '0';
		(*str)++;
	}
	*origin_nbr = nbr * neg;
	return (1);
}

int	ft_check_value(char *value)
{
	int nb;
	int nb_of_value;

	nb = 0;
	nb_of_value = 0;
	if (!value)
		return (0);
	while (*value)
	{
		if (!(ft_strchr("0123456789 -+", *value)))
			return (0);
		value++;
	}
	return (nb_of_value);
}

int	ft_check_arg(int ac, char **av)
{
	while (ac--)
	{
		if (!ft_check_value(av[ac]))
			return (0);
	}
	return (1);
}

void	ft_join_stack(t_stack *head, t_stack *tail)
{
	while (head->prev)
	{
		head = head->prev;
	}
	head->prev = tail;
}

int	ft_stack_add_nb(int nbr, t_stack *stack)
{
	t_stack *new;

	if (!(new = ft_init_stack(nbr, NULL)))
		return (0);
	ft_join_stack(stack, new);
	return (1);
}

t_stack *ft_store_stack(int ac, char **av)
{
	t_stack *new;
	t_stack *head;
	int	nbr;
	int	first_nb;

	first_nb = 1;
	head = NULL;
	while (ac--)
	{
		while (*(av[ac]))
		{
			if (!ft_atoi_crawl(&av[ac], &nbr))
			{
				ft_putendl_fd("Error", 2);
				ft_free_stack(&head);
				return (NULL);
			}
			if (first_nb)
			{
				if (!(new = ft_init_stack(nbr, NULL)))
				{
					ft_putendl_fd("Error", 2);
					ft_free_stack(&head);
					return (NULL);
				}
				first_nb--;
			}
			else
			{
				if (!(ft_stack_add_nb(nbr, new)))
				{
					ft_putendl_fd("Error", 2);
					ft_free_stack(&new);
					ft_free_stack(&head);
					return (NULL);
				}
			}
			while (*(av[ac]) == ' ')
				av[ac]++;
		}
		first_nb++;
		ft_join_stack(new, head);
		head = new;
	}
	return (head);
}
