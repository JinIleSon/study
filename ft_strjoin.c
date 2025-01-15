int	ft_my_strlen(char const *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*space;
	int		len_s1;
	int		len_s2;
	int		i;

	len_s1 = ft_my_strlen(s1);
	len_s2 = ft_my_strlen(s2);
	space = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (space == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		space[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
		space[i + len_s1] = s2[i];
		i++;
	}
	if (i == len_s2)
		space[len_s1 + len_s2] = '\0';
	return (space);
}
