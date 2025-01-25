char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*space;

	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		start = 0;
		len = 0;
	}
	else
	{
		len_s = ft_strlen(s + start);
		s += start;
	}
	if (len_s < len)
		len = len_s;
	space = (char *)malloc((len + 1) * sizeof(char));
	if (space == NULL)
		return (NULL);
	ft_strlcpy(space, s, len + 1);
	return (space);
}
