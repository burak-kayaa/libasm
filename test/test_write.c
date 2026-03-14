#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "libasm.h"

void test_write(void)
{
    ssize_t ret;

    printf("==== WRITE STDOUT TEST ====\n");
    ret = write(1, "write hello\n", 12);
    printf("write return    : %zd\n", ret);

    ret = ft_write(1, "ft_write hello\n", 15);
    printf("ft_write return : %zd\n\n", ret);

    printf("==== WRITE EMPTY STRING TEST ====\n");
    ret = write(1, "", 0);
    printf("write return    : %zd\n", ret);

    ret = ft_write(1, "", 0);
    printf("ft_write return : %zd\n\n", ret);

    printf("==== WRITE INVALID FD TEST ====\n");
    errno = 0;
    ret = write(-1, "abc", 3);
    printf("write return    : %zd\n", ret);
    printf("write errno     : %d (%s)\n\n", errno, strerror(errno));

    errno = 0;
    ret = ft_write(-1, "abc", 3);
    printf("ft_write return : %zd\n", ret);
    printf("ft_write errno  : %d (%s)\n\n", errno, strerror(errno));
}