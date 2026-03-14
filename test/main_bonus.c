#include <stdio.h>

void test_list_size(void);
void test_list_push_front(void);
void test_list_sort(void);
void test_list_remove_if(void);
void test_atoi_base(void);

int main(void)
{
    printf("===== FT_LIST_SIZE BONUS =====\n");
    test_list_size();

    printf("\n===== FT_LIST_PUSH_FRONT BONUS =====\n");
    test_list_push_front();

    printf("\n===== FT_LIST_SORT BONUS =====\n");
    test_list_sort();

    printf("\n===== FT_LIST_REMOVE_IF BONUS =====\n");
    test_list_remove_if();

    printf("\n===== FT_ATOI_BASE BONUS =====\n");
    test_atoi_base();
    
    return (0);
}