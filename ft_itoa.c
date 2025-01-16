char	*ft_zero(char *space)
{
	space = (char *)malloc((1 + 1) * sizeof(char));
	if (space == NULL)
		return (NULL);
	space[0] = '0';
	space[1] = '\0';
	return (space);
}

char	*ft_int_min(char *space)
{
	space = (char *)malloc((11 + 1) * sizeof(char));
	if (space == NULL)
		return (NULL);
	space[0] = '-';
	space[1] = '2';
	space[2] = '1';
	space[3] = '4';
	space[4] = '7';
	space[5] = '4';
	space[6] = '8';
	space[7] = '3';
	space[8] = '6';
	space[9] = '4';
	space[10] = '8';
	space[11] = '\0';
	return (space);
}

char	*ft_common_second(char *space, int count, int n, int i)
{
	long	one;
	int		n_dummy;

	one = 1;
	n_dummy = 0;
	while (count > 0)
	{
		one *= 10;
		count--;
	}
	one /= 10;
	while (one)
	{
		n_dummy = n;
		n_dummy /= one;
		n %= one;
		space[i] = n_dummy + 48;
		one /= 10;
		i++;
	}
	space[i] = '\0';
	return (space);
}

char	*ft_common_first(int n_dummy, int *count, int one, int *i)
{
	char	*space;

	while (n_dummy > 0)
	{
		n_dummy /= 10;
		(*count)++;
	}
	space = (char *)malloc(((*count) + one + 1) * sizeof(char));
	if (space == NULL)
		return (NULL);
	if (one == 1)
	{
		space[0] = '-';
		(*i)++;
	}
	return (space);
}

char	*ft_itoa(int n)
{
	int		count;
	int		n_dummy;
	long	one;
	int		i;
	char	*space;

	count = 0;
	one = 0;
	i = 0;
	space = 0;
	if (n == 0)
		return (ft_zero(space));
	if (n == -2147483648)
		return (ft_int_min(space));
	if (n < 0)
	{
		n *= (-1);
		one = 1;
	}
	n_dummy = n;
	space = ft_common_first(n_dummy, &count, one, &i);
	if (n > 0)
		space = ft_common_second(space, count, n, i);
	return (space);
}
