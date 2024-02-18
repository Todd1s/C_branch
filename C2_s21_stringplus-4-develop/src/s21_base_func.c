#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t i = 0;
  void *str2;
  str2 = s21_NULL;
  while (i < n) {
    if (*((unsigned char *)str + i) == (char)c) {
      str2 = (void *)str + i;
      break;
    }
    i++;
  }
  return str2;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *p1 = (unsigned char *)str1;
  unsigned char *p2 = (unsigned char *)str2;
  int z = 0;
  s21_size_t i = 0;
  for (; i < n; i++) {
    if (p1[i] != p2[i]) break;
  }
  if (0 == n || i == n)
    ;
  else
    z = p1[i] - p2[i];
  return z;
  // int result = 0;
  // s21_size_t i = 0;
  // unsigned char *st1 = (unsigned char *)str1;
  // unsigned char *st2 = (unsigned char *)str2;
  // while (i < n) {
  //   if (st1[i] != st2[i]) {
  //     break;
  //   }
  //   i++;
  // }
  // if (0 == n || i == n)
  //   result = 0;
  // else
  //   result = st1[i] - st2[i];
  // return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  s21_size_t i = 0;
  unsigned char *dest2 = (unsigned char *)dest;
  unsigned char *src2 = (unsigned char *)src;
  for (; i < n && dest2 != s21_NULL && src2 != s21_NULL; i++) {
    dest2[i] = src2[i];
  }
  return dest2;
};

void *s21_memset(void *str, int c, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n) {
    (*((unsigned char *)str + i) = (char)c);
    i++;
  }
  return str;
};

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  s21_size_t k = s21_strlen(dest);

  for (; i < n && (src[i] != '\0'); i++, k++) {
    dest[k] = src[i];
  }
  return dest;
};

char *s21_strcat(char *dest, const char *src) {
  s21_size_t k = s21_strlen(dest);
  for (int i = 0; (src[i] != '\0'); i++, k++) {
    dest[k] = src[i];
  }
  return dest;
};

char *s21_strchr(const char *str, int c) {
  char *res;
  s21_size_t t = s21_strlen(str);
  res = (char *)str + t;
  if (c != '\0') {
    res = (char *)s21_memchr(str, c, t);
  }
  return res;
};

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t k = s21_strlen(str1);
  s21_size_t k2 = s21_strlen(str2);
  if (n > k && str1 && str2 && n > 0 && (k == k2)) {
    n = k;
  }
  return s21_memcmp(str1, str2, n);
};

int s21_strcmp(const char *str1, const char *str2) {
  s21_size_t k = s21_strlen(str1);
  s21_size_t k2 = s21_strlen(str2);
  s21_size_t len = 0;
  if (k >= k2) {
    len = k2 + 1;
  } else {
    len = k + 1;
  }
  return s21_memcmp(str1, str2, len);
};

/// Рома
// s21_strcspn//////////////////////////////////////////////////////////////////
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t c = 0;
  if (str1 == s21_NULL || str2 == s21_NULL) {
  } else {
    int flag = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
      for (int j = 0; str2[j] != '\0'; j++) {
        if (str2[j] != str1[i]) {
        } else {
          flag = 1;
          break;
        }
      }
      if (flag == 1) {
      } else {
        c++;
      }
    }
  }
  return c;
}
// s21_strerror//////////////////////////////////////////////////////////////////
#if defined(__linux__)
#define SYS 0
#define N 134
#define ERRORS                                          \
  {"Success",                                           \
   "Operation not permitted",                           \
   "No such file or directory",                         \
   "No such process",                                   \
   "Interrupted system call",                           \
   "Input/output error",                                \
   "No such device or address",                         \
   "Argument list too long",                            \
   "Exec format error",                                 \
   "Bad file descriptor",                               \
   "No child processes",                                \
   "Resource temporarily unavailable",                  \
   "Cannot allocate memory",                            \
   "Permission denied",                                 \
   "Bad address",                                       \
   "Block device required",                             \
   "Device or resource busy",                           \
   "File exists",                                       \
   "Invalid cross-device link",                         \
   "No such device",                                    \
   "Not a directory",                                   \
   "Is a directory",                                    \
   "Invalid argument",                                  \
   "Too many open files in system",                     \
   "Too many open files",                               \
   "Inappropriate ioctl for device",                    \
   "Text file busy",                                    \
   "File too large",                                    \
   "No space left on device",                           \
   "Illegal seek",                                      \
   "Read-only file system",                             \
   "Too many links",                                    \
   "Broken pipe",                                       \
   "Numerical argument out of domain",                  \
   "Numerical result out of range",                     \
   "Resource deadlock avoided",                         \
   "File name too long",                                \
   "No locks available",                                \
   "Function not implemented",                          \
   "Directory not empty",                               \
   "Too many levels of symbolic links",                 \
   "Unknown error 41",                                  \
   "No message of desired type",                        \
   "Identifier removed",                                \
   "Channel number out of range",                       \
   "Level 2 not synchronized",                          \
   "Level 3 halted",                                    \
   "Level 3 reset",                                     \
   "Link number out of range",                          \
   "Protocol driver not attached",                      \
   "No CSI structure available",                        \
   "Level 2 halted",                                    \
   "Invalid exchange",                                  \
   "Invalid request descriptor",                        \
   "Exchange full",                                     \
   "No anode",                                          \
   "Invalid request code",                              \
   "Invalid slot",                                      \
   "Unknown error 58",                                  \
   "Bad font file format",                              \
   "Device not a stream",                               \
   "No data available",                                 \
   "Timer expired",                                     \
   "Out of streams resources",                          \
   "Machine is not on the network",                     \
   "Package not installed",                             \
   "Object is remote",                                  \
   "Link has been severed",                             \
   "Advertise error",                                   \
   "Srmount error",                                     \
   "Communication error on send",                       \
   "Protocol error",                                    \
   "Multihop attempted",                                \
   "RFS specific error",                                \
   "Bad message",                                       \
   "Value too large for defined data type",             \
   "Name not unique on network",                        \
   "File descriptor in bad state",                      \
   "Remote address changed",                            \
   "Can not access a needed shared library",            \
   "Accessing a corrupted shared library",              \
   ".lib section in a.out corrupted",                   \
   "Attempting to link in too many shared libraries",   \
   "Cannot exec a shared library directly",             \
   "Invalid or incomplete multibyte or wide character", \
   "Interrupted system call should be restarted",       \
   "Streams pipe error",                                \
   "Too many users",                                    \
   "Socket operation on non-socket",                    \
   "Destination address required",                      \
   "Message too long",                                  \
   "Protocol wrong type for socket",                    \
   "Protocol not available",                            \
   "Protocol not supported",                            \
   "Socket type not supported",                         \
   "Operation not supported",                           \
   "Protocol family not supported",                     \
   "Address family not supported by protocol",          \
   "Address already in use",                            \
   "Cannot assign requested address",                   \
   "Network is down",                                   \
   "Network is unreachable",                            \
   "Network dropped connection on reset",               \
   "Software caused connection abort",                  \
   "Connection reset by peer",                          \
   "No buffer space available",                         \
   "Transport endpoint is already connected",           \
   "Transport endpoint is not connected",               \
   "Cannot send after transport endpoint shutdown",     \
   "Too many references: cannot splice",                \
   "Connection timed out",                              \
   "Connection refused",                                \
   "Host is down",                                      \
   "No route to host",                                  \
   "Operation already in progress",                     \
   "Operation now in progress",                         \
   "Stale file handle",                                 \
   "Structure needs cleaning",                          \
   "Not a XENIX named type file",                       \
   "No XENIX semaphores available",                     \
   "Is a named type file",                              \
   "Remote I/O error",                                  \
   "Disk quota exceeded",                               \
   "No medium found",                                   \
   "Wrong medium type",                                 \
   "Operation canceled",                                \
   "Required key not available",                        \
   "Key has expired",                                   \
   "Key has been revoked",                              \
   "Key was rejected by service",                       \
   "Owner died",                                        \
   "State not recoverable",                             \
   "Operation not possible due to RF-kill",             \
   "Memory page has hardware error"};

#endif

#if defined(__APPLE__)
#define SYS 1
#define N 107
#define ERRORS                                        \
  {"Undefined error: 0",                              \
   "Operation not permitted",                         \
   "No such file or directory",                       \
   "No such process",                                 \
   "Interrupted system call",                         \
   "Input/output error",                              \
   "Device not configured",                           \
   "Argument list too long",                          \
   "Exec format error",                               \
   "Bad file descriptor",                             \
   "No child processes",                              \
   "Resource deadlock avoided",                       \
   "Cannot allocate memory",                          \
   "Permission denied",                               \
   "Bad address",                                     \
   "Block device required",                           \
   "Resource busy",                                   \
   "File exists",                                     \
   "Cross-device link",                               \
   "Operation not supported by device",               \
   "Not a directory",                                 \
   "Is a directory",                                  \
   "Invalid argument",                                \
   "Too many open files in system",                   \
   "Too many open files",                             \
   "Inappropriate ioctl for device",                  \
   "Text file busy",                                  \
   "File too large",                                  \
   "No space left on device",                         \
   "Illegal seek",                                    \
   "Read-only file system",                           \
   "Too many links",                                  \
   "Broken pipe",                                     \
   "Numerical argument out of domain",                \
   "Result too large",                                \
   "Resource temporarily unavailable",                \
   "Operation now in progress",                       \
   "Operation already in progress",                   \
   "Socket operation on non-socket",                  \
   "Destination address required",                    \
   "Message too long",                                \
   "Protocol wrong type for socket",                  \
   "Protocol not available",                          \
   "Protocol not supported",                          \
   "Socket type not supported",                       \
   "Operation not supported",                         \
   "Protocol family not supported",                   \
   "Address family not supported by protocol family", \
   "Address already in use",                          \
   "Can't assign requested address",                  \
   "Network is down",                                 \
   "Network is unreachable",                          \
   "Network dropped connection on reset",             \
   "Software caused connection abort",                \
   "Connection reset by peer",                        \
   "No buffer space available",                       \
   "Socket is already connected",                     \
   "Socket is not connected",                         \
   "Can\'t send after socket shutdown",               \
   "Too many references: can\'t splice",              \
   "Operation timed out",                             \
   "Connection refused",                              \
   "Too many levels of symbolic links",               \
   "File name too long",                              \
   "Host is down",                                    \
   "No route to host",                                \
   "Directory not empty",                             \
   "Too many processes",                              \
   "Too many users",                                  \
   "Disc quota exceeded",                             \
   "Stale NFS file handle",                           \
   "Too many levels of remote in path",               \
   "RPC struct is bad",                               \
   "RPC version wrong",                               \
   "RPC prog. not avail",                             \
   "Program version wrong",                           \
   "Bad procedure for program",                       \
   "No locks available",                              \
   "Function not implemented",                        \
   "Inappropriate file type or format",               \
   "Authentication error",                            \
   "Need authenticator",                              \
   "Device power is off",                             \
   "Device error",                                    \
   "Value too large to be stored in data type",       \
   "Bad executable (or shared library)",              \
   "Bad CPU type in executable",                      \
   "Shared library version mismatch",                 \
   "Malformed Mach-o file",                           \
   "Operation canceled",                              \
   "Identifier removed",                              \
   "No message of desired type",                      \
   "Illegal byte sequence",                           \
   "Attribute not found",                             \
   "Bad message",                                     \
   "EMULTIHOP (Reserved)",                            \
   "No message available on STREAM",                  \
   "ENOLINK (Reserved)",                              \
   "No STREAM resources",                             \
   "Not a STREAM",                                    \
   "Protocol error",                                  \
   "STREAM ioctl timeout",                            \
   "Operation not supported on socket",               \
   "Policy not found",                                \
   "State not recoverable",                           \
   "Previous owner died",                             \
   "Interface output queue is full"};

#endif

void compil(char *buf, char *str, int errnum);
int signedToStringE(char *str, int a);
int getCiferE(char *str, int a);

char *s21_strerror(int errnum) {
  char *result = s21_NULL;
  char *errors[] = ERRORS;
  static char bufal[100] = {0};
  s21_memset(bufal, 0, 100);
  if (errnum >= 0 && errnum < N)
    result = errors[errnum];
  else {
    int sys = SYS;
    if (sys == 0) {
      compil(bufal, "Unknown error ", errnum);
    } else {
      compil(bufal, "Unknown error: ", errnum);
    }
    result = bufal;
  }
  return result;
}

void compil(char *buf, char *str, int errnum) {
  s21_strcpy(buf, str);
  char bus[100] = {0};
  signedToStringE(bus, errnum);
  s21_strcat(buf, bus);
}

int signedToStringE(char *str, int a) {
  int count = 0;
  if (0 > a) {
    *str = '-';
    str++;
    count++;
    a *= -1;
  }
  int step = getCiferE(str, a);
  str += step;
  count += step;
  return count;
}

int getCiferE(char *str, int a) {
  int count = 0;
  if (9 < a) {
    count += getCiferE(str, a / 10);
    str += count;
  }
  int buf = a % 10;
  *str = buf + '0';
  count++;
  return count;
}

// s21_strlen//////////////////////////////////////////////////////////////////
s21_size_t s21_strlen(const char *str) {
  s21_size_t c = 0;
  if (str != s21_NULL) {
    for (int i = 0; str[i] != '\0'; i++) {
      c++;
    }
  }
  return c;
}
// s21_strncpy//////////////////////////////////////////////////////////////////
char *s21_strcpy(char *dest, const char *src) {
  char *esc = dest;
  if (dest == s21_NULL || src == s21_NULL) {
  } else {
    s21_size_t i = 0;
    while (src[i] != '\0') {
      dest[i] = src[i];
      i++;
    }
    dest[i] = '\0';
    esc = dest;
  }
  return esc;
}
// s21_strcpy//////////////////////////////////////////////////////////////////
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *esc = dest;
  if (dest == s21_NULL || src == s21_NULL || n == 0) {
  } else {
    s21_size_t i = 0;
    while (i < n && src[i] != '\0') {
      dest[i] = src[i];
      i++;
    }
    while (i < n) {
      dest[i] = '\0';
      i++;
    }
    esc = dest;
  }
  return esc;
}
// s21_strpbrk//////////////////////////////////////////////////////////////////
char *s21_strpbrk(const char *str1, const char *str2) {
  char *esc = s21_NULL;
  if (str1 == s21_NULL || str2 == s21_NULL) {
  } else {
    const char *temp;
    while (*str1 != '\0') {
      temp = str2;
      while (*temp != '\0') {
        if (*temp == *str1) {
          esc = (char *)str1;
          break;
        }
        temp++;
      }
      if (esc != s21_NULL) {
        break;
      }
      str1++;
    }
  }
  return esc;
}
// s21_strrchr//////////////////////////////////////////////////////////////////
char *s21_strrchr(const char *str, int c) {
  char *esc = s21_NULL;
  if (str == s21_NULL) {
  } else {
    while (*str != '\0') {
      if (*str == c) {
        esc = (char *)str;
      }
      str++;
    }
    if (*str == '\0') {
      if (*str == c) {
        esc = (char *)str;
      }
    }
  }
  return esc;
}
// s21_strstr//////////////////////////////////////////////////////////////////
char *s21_strstr(const char *haystack, const char *needle) {
  char *esc = s21_NULL;
  if (haystack == s21_NULL || needle == s21_NULL) {
  } else {
    const char *temp;
    const char *temp1;
    if (*needle == '\0') {
      esc = (char *)haystack;
    }
    while (*haystack != '\0' && esc != (char *)haystack) {
      temp = haystack;
      temp1 = needle;

      while (*temp1 == *temp && *temp1 != '\0') {
        if (esc == s21_NULL) {
          esc = (char *)temp;
        }
        temp1++;
        temp++;
      }
      if (*temp1 != '\0') {
        esc = s21_NULL;
      }

      if (esc != s21_NULL) {
        break;
      }
      haystack++;
    }
  }
  return esc;
}
// s21_strtok//////////////////////////////////////////////////////////////////
char *s21_strtok(char *str, const char *delim) {
  static char *saved_str = s21_NULL;
  char *esc = s21_NULL;
  if (str != s21_NULL) {
    saved_str = str;
  }
  if (saved_str == s21_NULL || *saved_str == '\0') {
  } else {
    while (*saved_str != '\0' && s21_strchr(delim, *saved_str) != s21_NULL) {
      saved_str++;
    }

    if (*saved_str == '\0') {
    } else {
      esc = saved_str;
      while (*saved_str != '\0' && s21_strchr(delim, *saved_str) == s21_NULL) {
        saved_str++;
      }

      if (*saved_str != '\0') {
        *saved_str++ = '\0';
      }
    }
  }
  return esc;
}
