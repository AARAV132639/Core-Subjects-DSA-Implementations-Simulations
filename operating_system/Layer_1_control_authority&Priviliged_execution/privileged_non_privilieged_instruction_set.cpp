#include<bits/stdc++.h>
using namespace std;

//enumerating cpu modes. This acts as custom data type
enum CPU_mode{
    USER_MODE,
    KERNEL_MODE
};

//specifying privileged instruction
set<string>Priviliged_instruction={
        "HALT",
    "DISABLE_INTERRUPTS",
    "MODIFY_IVT"

};

//simulating execution
void Execution(const string&Instruction, CPU_mode mode)
{
    if(Priviliged_instruction.count(Instruction)&&mode== USER_MODE)
    {
        cout<<"Permission Denied"<<endl; return;
    }
    cout<<"Executing instruction"<<Instruction<<endl;
}

//testing the code using main funciton
int main() {
    CPU_mode currentMode = USER_MODE;

  Execution("ADD", currentMode);
  Execution("HALT", currentMode);

    currentMode = KERNEL_MODE;
   Execution("HALT", currentMode);

    return 0;
}
