#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libasm_bonus.h"

static int cmp_str(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}

static void free_data(void *data)
{
    free(data);
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

static t_list *new_node(char *s)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->data = strdup(s);
    node->next = NULL;
    return node;
}

void test_list_remove_if(void)
{
    t_list *n1 = new_node("apple");
    t_list *n2 = new_node("banana");
    t_list *n3 = new_node("apple");
    t_list *n4 = new_node("pear");
    t_list *n5 = new_node("apple");
    t_list *head = n1;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    printf("before remove: ");
    print_list(head);

    ft_list_remove_if(&head, "apple", cmp_str, free_data);

    printf("after remove : ");
    print_list(head);

    while (head)
    {
        t_list *tmp = head->next;
        free_data(head->data);
        free(head);
        head = tmp;
    }
}