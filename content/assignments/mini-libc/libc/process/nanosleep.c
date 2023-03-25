#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    if (req == NULL)
    {
        errno = EFAULT;
        return -1;
    }

    int result = syscall(__NR_nanosleep, req, rem);

    if (result == -1)
    {
        errno = EINTR;
        return -1;
    }
    else if (result < 0)
    {
        errno = -result;
        return -1;
    }
    return 0;
}