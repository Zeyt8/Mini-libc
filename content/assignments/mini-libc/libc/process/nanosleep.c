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

    int response = syscall(__NR_nanosleep, req, rem);

    if (response == -1)
    {
        errno = EINTR;
        return -1;
    }
    else if (response < 0)
    {
        errno = -response;
        return -1;
    }
    return 0;
}