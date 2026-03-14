#include <stdio.h>
#include <string.h>
#include "libasm.h"

void test_strcmp(void)
{
    printf("strcmp(\"hello\", \"hello\") = %d\n", strcmp("hello", "hello"));
    printf("ft_strcmp(\"hello\", \"hello\") = %d\n\n", ft_strcmp("hello", "hello"));

    printf("strcmp(\"hello\", \"hellp\") = %d\n", strcmp("hello", "hellp"));
    printf("ft_strcmp(\"hello\", \"hellp\") = %d\n\n", ft_strcmp("hello", "hellp"));

    printf("strcmp(\"hellp\", \"hello\") = %d\n", strcmp("hellp", "hello"));
    printf("ft_strcmp(\"hellp\", \"hello\") = %d\n\n", ft_strcmp("hellp", "hello"));

    printf("strcmp(\"\", \"\") = %d\n", strcmp("", ""));
    printf("ft_strcmp(\"\", \"\") = %d\n\n", ft_strcmp("", ""));

    printf("strcmp(\"a\", \"\") = %d\n", strcmp("a", ""));
    printf("ft_strcmp(\"a\", \"\") = %d\n\n", ft_strcmp("a", ""));
}