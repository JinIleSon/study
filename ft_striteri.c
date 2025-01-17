void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	len_s;

	i = 0;
	len_s = 0;
	while (s[len_s] != '\0')
		len_s++;
	while (i < len_s)
	{
		f(i, &s[i]);
		i++;
	}
}
