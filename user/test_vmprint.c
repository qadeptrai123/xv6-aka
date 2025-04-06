#include "kernel/types.h"
#include "user/user.h"

// int main(int argc, char *argv[])
// {
//   vmprint();  
//   exit(0);
// }
// int main(int argc, char *argv[]) {
//   if (argc > 1 && strcmp(argv[1], "test_vmprint") == 0) {
//       int pid = fork();
//       if (pid == 0) {  // Quá trình con
//           // In bảng trang trước khi thực thi exec
//           vmprint();
//           exec(argv[2], argv + 2);  // Chạy lệnh echo hello (hoặc lệnh khác)
//           printf("Exec failed\n");  // In lỗi nếu exec thất bại
//           exit(0);  // Đảm bảo tiến trình con kết thúc
//       } else if (pid > 0) {  // Quá trình cha
//           wait(0);  // Chờ quá trình con kết thúc
//       } else {
//           printf("Fork failed\n");
//           exit(1);
//       }
//   } else {
//       // Nếu không có "test_vmprint", chỉ gọi exec bình thường
//       exec(argv[1], argv + 1);
//   }
//   exit(0);
// }
int main(int argc, char* argv[]) { 
  if (argc > 1 && strcmp(argv[1], "test_vmprint") == 0) {
    int pid = fork();
    if (pid == 0) {  // Child process
      vmprint();  // Print the page table
      exec(argv[2], argv + 2);  // Execute the command
      printf("Exec failed\n");  // If exec fails
      exit(0);  // Ensure child process exits
    } else if (pid > 0) {  // Parent process
      wait(0);  // Wait for child process to finish
    } else {
      printf("Fork failed\n");
      exit(1);
    }
  } else {
    exec(argv[1], argv + 1);  // Execute the command normally
  }
  exit(0);
}