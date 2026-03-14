#include <stdio.h>
#include <string.h>
#include "libasm.h"

void test_strcpy(void)
{
    char src1[] = "hello";
    char src2[] = "";
    char src3[] = "42 Istanbul";

    char dst1[100];
    char dst2[100];

    strcpy(dst1, src1);
    ft_strcpy(dst2, src1);

    printf("src: %s\n", src1);
    printf("strcpy   : %s\n", dst1);
    printf("ft_strcpy: %s\n\n", dst2);

    strcpy(dst1, src2);
    ft_strcpy(dst2, src2);

    printf("src: \"%s\"\n", src2);
    printf("strcpy   : \"%s\"\n", dst1);
    printf("ft_strcpy: \"%s\"\n\n", dst2);

    strcpy(dst1, src3);
    ft_strcpy(dst2, src3);

    printf("src: %s\n", src3);
    printf("strcpy   : %s\n", dst1);
    printf("ft_strcpy: %s\n\n", dst2);

    printf("Return pointer test:\n");

    char *ret = ft_strcpy(dst2, src1);
    printf("returned pointer: %p\n", ret);
    printf("dst pointer     : %p\n", dst2);
}