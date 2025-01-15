char	*ft_strdup(const char *s)
{
	int		len_s;
	int		i;
	char	*space;

	i = 0;
	len_s = 0;
	while (s[i] != '\0')
	{
		len_s++;
		i++;
	}
	i = 0;
	space = (char *)malloc((len_s * sizeof(char)) + 1);
	if (space == NULL)
		return (NULL);
	while (i < len_s)
	{
		space[i] = s[i];
		i++;
	}
	if (i == len_s)
		space[i] = '\0';
	return (space);
}
