void	ft_dummy_count(int n, int n_dummy, int count, int fd)
{
	long	one;
	char	a;

	one = 1;
	a = 'a';
	while (count > 0)
	{
		one *= 10;
		count--;
	}
	one /= 10;
	while (one > 0)
	{
		n_dummy = n;
		a = (n_dummy / one) + 48;
		write(fd, &a, 1);
		n %= one;
		one /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		n_dummy;
	char	a;
	int		count;

	a = 'a';
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n < 0 && n != -2147483648)
	{
		a = '-';
		write(fd, &a, 1);
		n *= (-1);
	}
	n_dummy = n;
	count = 0;
	while (n_dummy > 0)
	{
		n_dummy /= 10;
		count++;
	}
	ft_dummy_count(n, n_dummy, count, fd);
}
