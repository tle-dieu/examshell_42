#include "list.h"

int		cycle_detector(const t_list *list)
{
	t_list *next;

	next = list->next;
	while (next)
	{
		if (next == list)
			return (1);
		next = next->next;
	}
	return (0);
}
