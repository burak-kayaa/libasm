#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "libasm.h"

void test_read(void)
{
    char buf1[100];
    char buf2[100];
    ssize_t ret;

    printf("==== READ INVALID FD TEST ====\n");
    errno = 0;
    ret = read(-1, buf1, 10);
    printf("read return    : %zd\n", ret);
    printf("read errno     : %d (%s)\n\n", errno, strerror(errno));
    errno = 0;
    ret = ft_read(-1, buf2, 10);
    printf("ft_read return : %zd\n", ret);
    printf("ft_read errno  : %d (%s)\n\n", errno, strerror(errno));

    printf("==== READ STDIN TEST ====\n");
    printf("Bir sey yaz ve enter'a bas:\n");
    ret = ft_read(0, buf2, 99);
    if (ret >= 0)
    {
        buf2[ret] = '\0';
        printf("ft_read read   : %zd bytes\n", ret);
        printf("buffer         : %s\n", buf2);
    }
    else
        printf("ft_read failed : errno=%d (%s)\n", errno, strerror(errno));
}