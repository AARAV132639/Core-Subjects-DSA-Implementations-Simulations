#include<bits/stdc++.h>
using namespace std;

//defining global cpu modes
enum CPU_MODE{
    USER_MODE,
    KERNEL_MODE
};

//defining global cpu instructions that change the cpu mode
enum CPU_EVENT {
    INTERRUPT,
    SYSCALL,
    RETURN_TO_USER
};

//simulating the state transistion logic
//user cannot directly enter kernel mode without a specific event

void handleEvent(CPU_MODE &mode, CPU_EVENT event) {
    if (mode == USER_MODE) {
        if (event == INTERRUPT || event == SYSCALL) {
            cout << "Transition: USER -> KERNEL\n";
            mode = KERNEL_MODE;
        } else {
            cout << "Illegal event in USER mode\n";
        }
    } 
    else if (mode == KERNEL_MODE) {
        if (event == RETURN_TO_USER) {
            cout << "Transition: KERNEL -> USER\n";
            mode = USER_MODE;
        } else {
            cout << "Kernel handling event\n";
        }
    }
}

int main() {
    CPU_MODE mode = USER_MODE;

    handleEvent(mode, SYSCALL);        // USER -> KERNEL
    handleEvent(mode, RETURN_TO_USER); // KERNEL -> USER

    handleEvent(mode, RETURN_TO_USER); // Illegal when cpu already in user mode

    return 0;
}


