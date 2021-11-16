int	ft_median_of_3(int begin, int middle, int end)
{
	if ((begin < middle) ^ (begin < end))
		return (begin);
	if ((middle < begin) ^ (middle < end))
		return (middle);
	return (end);
}

int	ft_median_of_3_tab(int *tab, int begin, int middle, int end)
{
	if ((tab[begin] < tab[middle]) ^ (tab[begin] < tab[end]))
		return (begin);
	if ((tab[middle] < tab[begin]) ^ (tab[middle] < tab[end]))
		return (middle);
	return (end);
}
