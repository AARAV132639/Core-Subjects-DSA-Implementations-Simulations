#include <stddef.h>
# include "process_table.h" //including the contract

#define MAX_PROCESSES 64 //At most 64 processes may at once. However Real OS is dynamic in nature

//defining the actualy process table
static pcb_t* process_table[MAX_PROCESSES]; 

/*
static ---> this variable is visible only inside this file. Thus, by this no other file can touch the table directly
pcb_t*---> pointer to a PCB
process_table[i]---> one process slot
NULL---> no process exists at this slot
*/

//Initializing the table
void init_process_table()
{
    for(int i=0;i<MAX_PROCESSES;i++) {process_table[i]=NULL;}
}
/*
1. Clears all slots
2. Declares: No process exists yet
3. This must be done before adding any process
*/

//Adding a process. System law enforcement
int add_process(pcb_t* pcb)
{
    if(!pcb) return -1; //pcb must exist
    
    int pid= pcb->pid;
    if(pid<0||pid>=MAX_PROCESSES) return-1; //pid must be in range

    if(process_table[pid]!=NULL) return -1;//slot must be empty and no duplicate PIDs

    process_table[pid]=pcb;
    return 0;
}

//Give me the PCB if it exists, else NULL
pcb_t* get_process(int pid){
    if(pid<0||pid>=MAX_PROCESSES) return NULL;

    return process_table[pid];
}

// Remove a process---> This process no longer exists in the system registry
void remove_process(int pid)
{
    if(pid<0||pid>=MAX_PROCESSES) return;

    process_table[pid]= NULL;
}

/*
Summary uptil now:

1. process.h---> what must exist
2. process_table.h---> what is allowed to be done with what exist
3. process_table.cpp--> decides whether a process may exist be register or be remvoved
*/



