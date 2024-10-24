#include<sbrk.hpp>
#define SYS_BRK 12
void* msbrk(long increment) { // size in bytes
    static void* program_break = nullptr;  // Track the program break (initially null)
    // If this is the first call, initialize the program break with the current break
    if (!program_break) {
        program_break = msyscall(SYS_BRK, nullptr);
    }
    // Request new memory by increasing the program break
    void* old_break = program_break;
    void* new_break = msyscall(SYS_BRK, static_cast<char*>(program_break) + increment);
    // If the syscall failed, return (void*) -1
    if (new_break == (void*) -1) {
        return (void*) -1;
    }
    // Update the program break and return the old one
    program_break = new_break;
    return old_break;
}