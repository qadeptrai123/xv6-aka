#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  // Nếu không có lệnh nào được truyền, chỉ in page table là đủ
  if (argc < 2)
  {
    // báo lỗi
    fprintf(2, "Usage: %s command [args]\n", argv[0]);
    exit(1);
  }

  vmprint_on();

  exec(argv[1], &argv[1]);
  fprintf(2, "exec %s failed\n", argv[1]);
  exit(0);
}
