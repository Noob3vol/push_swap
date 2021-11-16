#include "libft.h"

bool	ft_strequ(char *str_ref, char *str)
{
	if (str_ref == str)
		return (1);
	if (!str_ref || !str)
		return (0);
	while (*str_ref && *str == *str_ref)
	{
		str++;
		str_ref++;
	}
	if (!*str_ref && !*str)
		return (1);
	return (0);
}
