#include <cstdio>



void *memcpy(void *src, void *dest, size_t len)
{
    if (src == nullptr || dest == nullptr)
        return;
    if (len == 0)
        return dest;
    void *ret = dest;
    //src = static_cast<char *>(src);
    //dest = static_cast<char *>(dest);
    if (dest <= src || (char *)dest >= (char *)src + len)
    {
        while (len-- > 0)
        {
            *(char*)dest = *(char*)src;
            dest = (char *)dest + 1;
            src = (char *)src + 1;
        }
    }
    else
    {
        src = (char *)src + len - 1;
        dest = (char *)dest + len - 1;
        while (len--)
        {
            *(char*)dest = *(char*)src;
            dest = (char*)dest - 1;
            src = (char*)src - 1;
        }
    }
    return ret;
}