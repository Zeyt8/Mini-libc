#include <unistd.h>
#include <time.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    while (nanosleep(&req, &rem) == -1) {
        if (errno == EINTR) {
            req = rem;
        } else {
            return;
        }
    }
}