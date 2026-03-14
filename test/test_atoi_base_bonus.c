#include <stdio.h>
#include "libasm_bonus.h"

void test_atoi_base(void)
{
    printf("bin 1011           -> %d\n", ft_atoi_base("1011", "01"));
    printf("dec -42            -> %d\n", ft_atoi_base("   -42", "0123456789"));
    printf("hex 2A             -> %d\n", ft_atoi_base("2A", "0123456789ABCDEF"));
    printf("hex ---2A          -> %d\n", ft_atoi_base("---2A", "0123456789ABCDEF"));
    printf("oct 777            -> %d\n", ft_atoi_base("777", "01234567"));
    printf("invalid base dup   -> %d\n", ft_atoi_base("123", "00123"));
    printf("invalid base one   -> %d\n", ft_atoi_base("123", "0"));
    printf("stop on invalid    -> %d\n", ft_atoi_base("123xyz", "0123456789"));
}