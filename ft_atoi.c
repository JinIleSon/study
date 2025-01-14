const char	*whitesp(const char *nptr)
{
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	return (nptr);
}

const char	*plus(const char *nptr, int *count_p)
{
	*count_p = 0;
	while (*nptr == '+')
	{
		(*count_p)++;
		nptr++;
	}
	return (nptr);
}

const char	*minus(const char *nptr, int *count_m)
{
	*count_m = 0;
	while (*nptr == '-')
	{
		(*count_m)++;
		nptr++;
	}
	return (nptr);
}

int	ft_atoi(const char *nptr)
{
	int	count_plus;
	int	count_minus;
	int	num;

	count_plus = 0;
	count_minus = 0;
	nptr = whitesp(nptr);
	nptr = plus(nptr, &count_plus);
	nptr = minus(nptr, &count_minus);
	if (count_plus > 1 || count_minus > 1)
		return (0);
	if (count_plus == 1 && count_minus == 1)
		return (0);
	while (*nptr >= 48 && *nptr <= 57)
	{
		num += *nptr - 48;
		if (*(nptr + 1) >= 48 && *(nptr + 1) <= 57)
			num *= 10;
		nptr++;
	}
	if (count_plus == 1 || (count_plus == 0 && count_minus == 0))
		return (num);
	else if (count_minus == 1)
		return (-num);
	return (0);
}
