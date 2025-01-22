t_list	*ft_lstnew(void *content)
{
	t_list	*space;

	space = malloc(sizeof(t_list));
	if (space == NULL)
		return (0);
	space -> content = content;
	space -> next = 0;
	return (space);
}
