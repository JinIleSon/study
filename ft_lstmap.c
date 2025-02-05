void	fail_return(t_list *space, void (*del)(void *), void *new_content)
{
	ft_lstclear(&space, del);
	del(new_content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*space;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	space = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(&space, del);
			return (NULL);
		}
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			fail_return(space, del, new_content);
			return (NULL);
		}
		ft_lstadd_back(&space, new_node);
		lst = lst->next;
	}
	return (space);
}
