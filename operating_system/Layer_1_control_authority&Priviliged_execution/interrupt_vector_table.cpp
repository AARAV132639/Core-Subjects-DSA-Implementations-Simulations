//Invariant: One interrupt number ---> exactly one handler
// Behaviour: Recieved the interupt number then searching for handler corresponding to interrupt
// Structure: fixed size table indexed by interrupt table


#include<bits/stdc++.h>
using namespace std;

// What data structure enforces this invariant?
const int MAXINTERRUPT = 256;
using InterruptHandler = function<void()>;

//INterrupt vector table [IVT]
InterruptHandler IVT[MAXINTERRUPT];

//Initializing the IVT with default handlers
void initialize()
{
    for(int i=0; i<256;i++)
    {
        IVT[i]= []()
        {
            cout<<" Unhandled interrupt"<<endl;
        };
    }
}

//Registering an interrupt handler(kernel mode simulation)
void registerHandler(int interruptNumber, InterruptHandler handler){
    if(interruptNumber<0||interruptNumber>= MAXINTERRUPT){
        cout<<"Invalid interrupt number!"<<endl;
        return;
    }
    IVT[interruptNumber]= handler;
}
 
//simulate interrupt dispatch
void triggerInterrupt(int interruptNumber)
{
    if(interruptNumber<0||interruptNumber>= MAXINTERRUPT){
        cout<<"Invalid interrupt number!"<<endl;
        return;
    }
    IVT[interruptNumber](); //jump to handler
}

int main(){

    initialize(); //calling the default 

    //register a sample interrupt handler. Here we are over writing the default case
    registerHandler(5,[](){
        cout<<"keyboard interrupt handled"<<endl;
    });

    //simulate interrupt
    triggerInterrupt(5);
    triggerInterrupt(10);
    return 0;
}
