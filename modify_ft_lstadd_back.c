void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*position;

	position = 0;
	if (*lst == NULL)
		*lst = new;
	else
	{
		position = *lst;
		while (position->next != NULL)
			position = position->next;
		position->next = new;
	}
}
