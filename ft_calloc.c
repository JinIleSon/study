void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*space;

	space = malloc(nmemb * size);
	if (space == NULL)
		return (NULL);
	ft_memset(space, 0, nmemb);
	return (space);
}
