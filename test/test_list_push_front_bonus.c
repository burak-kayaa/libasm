#include <stdio.h>
#include <stdlib.h>
#include "libasm_bonus.h"

void test_list_push_front(void)
{
    t_list *head = NULL;

    ft_list_push_front(&head, "world");
    ft_list_push_front(&head, "hello");

    printf("size = %d\n", ft_list_size(head));
    if (head)
        printf("head data = %s\n", (char *)head->data);
    if (head && head->next)
        printf("next data = %s\n", (char *)head->next->data);

    while (head)
    {
        t_list *tmp = head->next;
        free(head);
        head = tmp;
    }
}