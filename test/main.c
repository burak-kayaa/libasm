#include <stdio.h>

void test_strlen(void);
void test_strcmp(void);
void test_strcpy(void);
void test_write(void);
void test_read(void);
void test_strdup(void);
void test_list_size(void);

int main(void)
{
    printf("\n===== FT_STRLEN =====\n");
    test_strlen();

    printf("\n===== FT_STRCMP =====\n");
    test_strcmp();

    printf("\n===== FT_STRCPY =====\n");
    test_strcpy();
    
    printf("\n===== FT_WRITE =====\n");
    test_write();

    printf("\n===== FT_READ =====\n");
    test_read();

    printf("\n===== FT_STRDUP =====\n");
    test_strdup();

    return (0);
}