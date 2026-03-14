#ifndef LIBASM_H
#define LIBASM_H

#include <stddef.h>

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, char *src);
ssize_t	ft_write(int fd, const void *buf, size_t n);
ssize_t	ft_read(int fd, void *buf, size_t nbytes);
char	*ft_strdup(const char *s);

#endif