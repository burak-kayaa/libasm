#include <stdio.h>
#include <string.h>
#include "libasm.h"

void test_strlen(void)
{
    printf("strlen(\"hello\") = %zu\n", strlen("hello"));
    printf("ft_strlen(\"hello\") = %zu\n", ft_strlen("hello"));

    printf("strlen(\"\") = %zu\n", strlen(""));
    printf("ft_strlen(\"\") = %zu\n", ft_strlen(""));
}