#include "list.h"

int		cycle_detector(const t_list *list)
{
	t_list *comp;
	t_list *comp2;

	comp = (t_list *)list;
	comp2 = comp;
	while (comp2 && comp2->next)
	{
		comp = comp->next;
		comp2 = comp2->next->next;
		if (comp == comp2)
			return (1);
	}
	return (0);
}

#include <stdio.h>
#include <stdlib.h>

t_list	*lstnew(int data)
{
	t_list *new;

	if(!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->next = NULL;
	new->data = data;
	return (new);
}

int		main(void)
{
	t_list *list;

	list = lstnew(0);
	list->next = lstnew(5);
	list->next = list;
	/*list->next->next = lstnew(10);
	list->next->next->next = lstnew(15);
	list->next->next = list->next;
	*/printf("%d\n", cycle_detector(list));
	return (0);
}
