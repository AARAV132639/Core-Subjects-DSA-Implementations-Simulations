//software equivalent of IVT
#include<bits/stdc++.h>
using namespace std;

//defining syscal handler
using SyscallHandler = function<void()>; //defining custom data type but for functions

//creating syscal table that will map to syscal handler
const int MAX_SYSCALLS = 128;

SyscallHandler syscallTable[MAX_SYSCALLS]; //this means each slot in syscallTable includes a void function. Similar to int arr[10]

//initializing with default handler
void initSyscallTable() {
    for (int i = 0; i < MAX_SYSCALLS; i++) {
        syscallTable[i] = []() {
            cout << "Invalid system call\n";
        };
    }
}

//registering in syscall_table--> privileged instruction-->happens only in kernel mode
void registerSyscall(int num, SyscallHandler handler) {
    if (num < 0 || num >= MAX_SYSCALLS) {
        cout << "Invalid syscall number\n";
        return;
    }
    syscallTable[num] = handler;
}

//dispatching the corresponding syscall service
void dispatchSyscall(int num) {
    if (num < 0 || num >= MAX_SYSCALLS) {
        cout << "Syscall out of range\n";
        return;
    }
    syscallTable[num]();
}

//main funciton to test
int main() {
    initSyscallTable();

    registerSyscall(1, []() {
        cout << "read() syscall executed\n";
    });

    registerSyscall(2, []() {
        cout << "write() syscall executed\n";
    });

    dispatchSyscall(1);
    dispatchSyscall(2);
    dispatchSyscall(99);

    return 0;
}

