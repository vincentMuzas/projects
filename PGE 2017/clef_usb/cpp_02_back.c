bool_t list_add_elem_at_back(list_t *front_ptr, double elem)
{
	list_t list, tmp = *front_ptr;

	if ((list = malloc(sizeof(*list))) == NULL)
		return (FALSE);
	list->value = elem;
	list->next = NULL;
	if (*front_ptr == NULL) {
		*front_ptr = list;
		return (TRUE);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = list;
	return (TRUE);
}
