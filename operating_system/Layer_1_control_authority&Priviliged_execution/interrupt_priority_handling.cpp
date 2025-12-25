/*
1. Simulating the interrupt handling using priority queues
2. Interrupts are handled by Hardware 
3. Here only a mental model, work flow and working is being simulated
*/

#include<bits/stdc++.h>
using namespace std;

//Encapsulating priority and action
struct Interrupt{
    
    int Interrupt_Number;
    int Priority;
};

// setting comparision rule. Highest priority comes first
struct Comparision{
    bool operator()(const Interrupt &a,const Interrupt &b){
        return a.Priority<b.Priority;
    }
};

priority_queue<Interrupt, vector<Interrupt>, Comparision>interruptQueue; //basically storing--> 1. What? 2. Where? 3. How?. Thus, priority queue here is a "vector" storing "interrupts" in "descending order"(highest to lowest priority value)

//interrupt being raised ie. multiple signals ariving
void raiseInterrupt(int num, int priority) {
    interruptQueue.push({num, priority});
    cout << "Interrupt_Number " << num << " raised with priority " << priority << endl;
}

//handling the interrupts one by one
void handleNextInterrupt() {
    if (interruptQueue.empty()) {
        cout << "No pending interrupts\n";
        return;
    }

    Interrupt current = interruptQueue.top();
    interruptQueue.pop();

    cout << "Handling interrupt " << current.Interrupt_Number
         << " with priority " << current.Priority << endl;

   }

//testing
int main() {
    raiseInterrupt(1, 1);   // keyboard
    raiseInterrupt(2, 5);   // timer
    raiseInterrupt(3, 10);  // power failure

    cout << "\n--- Processing Order ---\n";
    handleNextInterrupt();
    handleNextInterrupt();
    handleNextInterrupt();

    return 0;
}






