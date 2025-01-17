char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len_s;
	char			*space;

	i = 0;
	len_s = 0;
	while (s[len_s] != '\0')
		len_s++;
	space = (char *)malloc((len_s + 1) * sizeof(char));
	if (space == NULL)
		return (NULL);
	while (i < len_s)
	{
		space[i] = f(i, s[i]);
		i++;
	}
	space[i] = '\0';
	return (space);
}
