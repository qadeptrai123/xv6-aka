#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
#ifdef LAB_PGTBL
  // In page table của chính tiến trình `test_vmprint`
  kpgtbl();
#endif

  // Nếu không có lệnh nào được truyền, chỉ in page table là đủ
  if (argc < 2)
  {
    // báo lỗi
    fprintf(2, "Usage: %s command [args]\n", argv[0]);
    exit(0);
  }

  int pid = fork();
  if (pid == 0)
  {
    // Tiến trình con thực thi lệnh người dùng truyền vào
    exec(argv[1], &argv[1]);
    fprintf(2, "exec %s failed\n", argv[1]);
    exit(1);
  }
  else
  {
    // Cha chờ con kết thúc
    wait(0);
  }

  exit(0);
}
