#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libasm.h"

void test_strdup(void)
{
    char *s1 = "hello";
    char *s2 = "";
    char *s3 = "42 Istanbul libasm";

    char *libc_dup;
    char *ft_dup;

    printf("==== STRDUP TEST 1 ====\n");
    libc_dup = strdup(s1);
    ft_dup = ft_strdup(s1);
    printf("strdup    : %s\n", libc_dup);
    printf("ft_strdup : %s\n", ft_dup);
    printf("strcmp    : %d\n\n", strcmp(libc_dup, ft_dup));
    free(libc_dup);
    free(ft_dup);

    printf("==== STRDUP TEST 2 ====\n");
    libc_dup = strdup(s2);
    ft_dup = ft_strdup(s2);
    printf("strdup    : \"%s\"\n", libc_dup);
    printf("ft_strdup : \"%s\"\n", ft_dup);
    printf("strcmp    : %d\n\n", strcmp(libc_dup, ft_dup));
    free(libc_dup);
    free(ft_dup);

    printf("==== STRDUP TEST 3 ====\n");
    libc_dup = strdup(s3);
    ft_dup = ft_strdup(s3);
    printf("strdup    : %s\n", libc_dup);
    printf("ft_strdup : %s\n", ft_dup);
    printf("strcmp    : %d\n", strcmp(libc_dup, ft_dup));
    printf("same ptr? : %s\n\n", (libc_dup == ft_dup) ? "yes" : "no");
    free(libc_dup);
    free(ft_dup);
}