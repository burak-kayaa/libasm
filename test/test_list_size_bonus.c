#include <stdio.h>
#include <stdlib.h>
#include "libasm_bonus.h"

void test_list_size(void)
{
	t_list *n1;
	t_list *n2;
	t_list *n3;

	n1 = malloc(sizeof(t_list));
	n2 = malloc(sizeof(t_list));
	n3 = malloc(sizeof(t_list));

	if (!n1 || !n2 || !n3)
		return;

	n1->data = "one";
	n1->next = n2;

	n2->data = "two";
	n2->next = n3;

	n3->data = "three";
	n3->next = NULL;

	printf("list size = %d\n", ft_list_size(n1));
	printf("empty list size = %d\n", ft_list_size(NULL));

	free(n1);
	free(n2);
	free(n3);
}