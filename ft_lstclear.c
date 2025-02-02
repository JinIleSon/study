void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cont;

	cont = 0;
	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		cont = (*lst)->next;
		free(*lst);
		*lst = cont;
	}
	*lst = NULL;
}
