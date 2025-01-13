char	*ft_strrchr(const char *s, int c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (((char *)s)[i] != '\0')
	{
		if (((char *)s)[i] == c)
			count += 1;
		i++;
	}
	i = 0;
	while (*s != '\0')
	{
		if (((char *)s)[i] == c)
			i += 1;
		if ((*s == c) && (i == count))
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
