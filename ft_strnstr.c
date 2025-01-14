size_t	ft_len(const char *bili)
{
	size_t	len_bili;

	len_bili = 0;
	while (bili[len_bili] != '\0')
		len_bili++;
	return (len_bili);
}

char	*r(const char *big, const char *little, size_t len, size_t len_little)
{
	size_t	i;
	size_t	j;
	size_t	len_big;
	size_t	before_i;

	i = 0;
	j = 0;
	before_i = 0;
	len_big = ft_len(big);
	while (i < len && i < len_big)
	{
		before_i = i;
		while (big[i] == little[j] && i < len)
		{
			i++;
			j++;
			if (j == len_little)
				return ((char *)(big + before_i));
		}
		j = 0;
		i = before_i;
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;

	len_little = ft_len(little);
	if (len_little == 0)
		return ((char *)big);
	return (r(big, little, len, len_little));
}
