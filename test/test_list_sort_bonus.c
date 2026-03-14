#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libasm_bonus.h"

static int cmp_str(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}

static void print_list(t_list *head)
{
    while (head)
    {
        printf("%s", (char *)head->data);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

void test_list_sort(void)
{
    t_list *head = NULL;

    ft_list_push_front(&head, "pear");
    ft_list_push_front(&head, "apple");
    ft_list_push_front(&head, "orange");
    ft_list_push_front(&head, "banana");

    printf("before sort: ");
    print_list(head);

    ft_list_sort(&head, cmp_str);

    printf("after sort : ");
    print_list(head);

    while (head)
    {
        t_list *tmp = head->next;
        free(head);
        head = tmp;
    }
}