/*
1. process.h defines what the os agrees to remember about a process when it is not running

2. At any instant, each process occupies exactly one legal lifecycle state.

3. cpu_context_t stores the minimum execution snapshot required to resume a process as if it never stopped
# This is process context not CPU context.
# CPU has one real context
# We are storing a virtualized copy per process
Thus context of CPU---> context "belonging" to the process that was on CPU

4. PCB is to OS what a struct node is to a Linked List
*/



//Process states. State must never be a free integer.
// Stores information where in lifecycles
typedef enum{
    NEW,
    READY,
    RUNNING,
    BLOCKED,
    TERMINATED
} process_state_t;

//Context Snapshot
//Stores information about how to resume
typedef struct{
    int program_counter;
    int stack_pointer;
    int registers[8]; //simualting general-purpose registers
    } cpu_context_t;

//PCB struct(core)
// Binds identity, lifecycle position and execution snapshot into one unit
typedef struct{
    int pid;//---> who?
    process_state_t state;//--->where in lifecyle?
    cpu_context_t context;//--->how to resume?

    int priority;//information about how important is the process
    int time_slice;// information about how long it may run
} pcb_t;

/*
"int registers[8]"--->What does it mean?

registers[8] represents all volatile working values that must survive preemption
Inshort, If I stop a process right now, what temporary values must I not lose?

Analogy:Imagine a paused human
Program Counter: sentence they were reading
Stack Pointer: Depth Of Thought
Registers: Numbers in their head

Thus, its simulating the "idea" not exactly the registers
*/
