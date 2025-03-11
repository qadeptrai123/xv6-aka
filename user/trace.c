#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h" 

int main(int argc, char* argv[]) { 
    if (argc < 3) {
        fprintf(2, "Invalid syntax Trace\n");
        exit(1);
    }
    
    
    int trace_mask = atoi(argv[1]);
    if (trace(trace_mask) < 0) {
        fprintf(2, "trace failed\n");
        exit(1);
    };
    exec(argv[2], &argv[2]);
    printf("exec failed\n");
    exit(0);
    
     
} 