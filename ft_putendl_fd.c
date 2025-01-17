void	ft_putendl_fd(char *s, int fd)
{
	int	len_s;
	int	i;

	len_s = 0;
	i = 0;
	while (s[len_s] != '\0')
		len_s++;
	while (i < len_s)
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
