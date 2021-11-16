int compute_int_max(void)
{
	int		max;

	max = 0;
	max = (~max) ^ (1 << (sizeof(int) * 8 - 1));
	return (max);
}
