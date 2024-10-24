void* msyscall(long number, void* arg) {
    void* result;
    asm volatile (
        "movq %1, %%rax\n"   // Load the syscall number into rax
        "movq %2, %%rdi\n"   // Load the first argument into rdi (brk pointer)
        "syscall\n"          // Perform the system call
        "movq %%rax, %0\n"   // Store the result in the return variable
        : "=r"(result)       // Output variable (result)
        : "r"(number), "r"(arg)  // Input variables (number, arg)
        : "rax", "rdi"       // Clobbered registers
    );
    return result;
}
void* msyscall(long number, void* arg1,void* arg2, unsigned long arg3)
{
    void* result;
    asm volatile (
        "movq %1, %%rax\n"    // Load the syscall number into rax
        "movq %2, %%rdi\n"    // Load the first argument into rdi
        "movq %3, %%rsi\n"    // Load the second argument into rsi
        "movq %4, %%rdx\n"    // Load the third argument into rdx
        "syscall\n"           // Perform the syscall
        "movq %%rax, %0\n"    // Store the result in the return variable
        : "=r"(result)        // Output variable (result)
        : "r"(number), "r"(arg1), "r"(arg2), "r"(arg3) // Input variables
        : "rax", "rdi", "rsi", "rdx" // Clobbered registers
    );
    return result;
}