int	check(char const *charset, char str)
{
	if (*charset != str)
		return (1);
	else
		return (0);
}

char	**str_store_2(char const *str, char *charset)
{
	char	**str_store;
	int		i;
	int		word_count;

	i = 0;
	word_count = 0;
	str_store = 0;
	while (str[i] != '\0')
	{
		if (check(charset, str[i]) == 1)
		{
			word_count++;
			while (check(charset, str[i]) == 1 && str[i] != '\0')
				i++;
		}
		if (str[i] != '\0')
			i++;
	}
	str_store = (char **)malloc(sizeof(char *) * (1 + word_count));
	if (!str_store)
	{
		free(str_store);
		return (NULL);
	}
	return (str_store);
}

char	**str_store_1(char const *str, char *charset, char **str_store)
{
	int	i;
	int	j;
	int	word_count;

	i = 0;
	j = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		while (check(charset, str[i]) == 1 && str[i] != '\0')
		{
			word_count++;
			i++;
		}
		if (word_count != 0)
		{
			str_store[j++] = (char *)malloc(sizeof(char) * (word_count + 1));
			if (!str_store[j - 1])
				return (NULL);
		}
		word_count = 0;
		if (str[i] != '\0')
			i++;
	}
	return (str_store);
}

char	**str_printf(char const *str, char *charset, char **str_store)
{
	int	i;
	int	j;

	i = 0;
	while (*str != '\0')
	{
		j = 0;
		while (check(charset, *str) == 1 && *str != '\0')
		{
			str_store[i][j] = *str;
			str++;
			j++;
		}
		if (j != 0)
		{
			str_store[i][j] = '\0';
			i++;
		}
		if (*str == '\0')
			break ;
		str++;
	}
	str_store[i] = 0;
	return (str_store);
}

char	**ft_split(char const *s, char c)
{
	char	**str_store;

	str_store = 0;
	if (!s)
		return (NULL);
	str_store = str_store_2(s, &c);
	if (!str_store)
	{
		free(str_store);
		return (NULL);
	}
	str_store = str_store_1(s, &c, str_store);
	if (!str_store)
	{
		free(str_store);
		return (NULL);
	}
	str_store = str_printf(s, &c, str_store);
	if (!str_store)
	{
		free(str_store);
		return (NULL);
	}
	return (str_store);
}
