void	ft_swapi(int *nbr_1, int *nbr_2)
{
	*nbr_1 ^= *nbr_2;
	*nbr_2 ^= *nbr_1;
	*nbr_1 ^= *nbr_2;
}
