#ifndef PROCESS_TABLE_H
/*
1. #ifndef means IF NOT DEFINED
2.The entire block literally means that if PROCESS_TABLE_H has NOT been define yet
then define it now and include everything inside it

3.Why this exists?----> Because in future this header will be included multiple times, thus it is to prevent same declarations getting copies multiple times
4. This single says : Read this file only once, no matter how many times it's included
*/
#define PROCESS_TABLE_H

#include "process.h"

//These defines what operations are "allowed" on the process table. 
// process.h is the truth these are the law

//Any file is allowed to:
void init_process_table(); //1. Initialize the table
int add_process(pcb_t* pcb);//2. Add a process
pcb_t* get_process(int pid);//3. Look up a process
void remove_process(int pid);//4. Remove a process

#endif

/*
intit_process_table(): Intializes the global registry
o clears all slots o sets system to a known state

add_process(pcb_t* pcb): Regists a process in the system--->this process now officially exists
o Stores pcb pointer in the table oAssigns or validates PID o Makes the process exists

get_process(int pid): Retrieves the PCB of a specific process---> Selection done by Scheduler
o LookUp by PID o Returns PCB

remove_process(int pid): Removes a process from the system
o Deletes PCB refrenece from the table o Frees slot
!!! Does not free memory automatically

Hence, the process_table is a registry, not a decision-maker
*/