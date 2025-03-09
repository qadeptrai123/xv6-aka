#include "types.h"
#ifndef _SYSINFO_H_
#define _SYSINFO_H_

struct sysinfo
{
    uint64 freemem;    // Số byte bộ nhớ trống
    uint64 nproc;      // Số tiến trình đang chạy (không phải UNUSED)
    uint64 nopenfiles; // Số file đang mở trên toàn hệ thống
};

#endif // _SYSINFO_H_