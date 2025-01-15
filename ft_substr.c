char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*space;

	i = 0;
	space = (char *)malloc((len + 1) * sizeof(char));
	if (space == NULL)
		return (NULL);
	s += start;
	while (i < len)
	{
		space[i] = s[i];
		i++;
	}
	if (i == len)
		space[i] = '\0';
	return (space);
}
