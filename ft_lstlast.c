t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next != NULL)
			lst = lst->next;
		else
			break ;
	}
	return (lst);
}
