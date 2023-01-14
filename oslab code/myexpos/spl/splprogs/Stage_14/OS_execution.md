# OS Execution (Till Stage 14)

1. Execution starts at page 0 of the memory which contains the boot ROM code.
- The boot ROM code loads OS Startup Code from the Disk to 1st Page of the memory and then jumps to the first page of the memory.

2. Then OS Startup code is executed
- It contains code to load the Boot Module (Module 7) and idle code from disk to memory
- It sets kernel stack for idle process and calls Boot Module.


3. Boot Module
- Loads init program,user programs,Scheduler module,various interupts, exceptions handler, library code etc. from disk to memory.
- Setup Page tables and Process Table entries  for various processes.
- Store entry point of each process on the top of the stack of the correxponding process.
- Fill  the state of empty process table entries with TERMINATED state.
- Return to Startup code


4. Code Returns back to OS Startup Code
- Setup Process Table and Page Tables for IDLE Process
- Set current process in system status table to pid 0
- PTBR to Page Table base of IDLE and PTLR to 10
- Set SP to Page 8 and store Entry point of IDLE on top of the stack
- IRET to IDLE Process


5. IDLE Process
-  Its just an infinite loop.
-  Then timer interrupt occurs


When Timer Interrupt occurs the machine checks the corresponding entry in the interrupt vector table in Boot ROM and sets IP to the corresponding address of the Timer Interrupt.


6. Timer Interrupt
- Save User SP to Process Table Entry of Current Process
- Set SP to UArea Page number * 512 - 1 (Kernel Stack)
- Save user context to kernel stack
- Change state of current process from running to ready
- Loop through process table entries and increment the TICK field of each process
- Call Scheduler Module (Module 5)


7. Module 5 - Scheduler
- Push BP to the top of the kernel stack
- Save KPTR,PTBR,PTLR into the Process table
- Iterate through the Process Table entries, starting from the succeeding entry of the current process to find a process in READY or CREATED state and set it as the new process to be scheduled.
- If no such process can be found select idle process as the new process to be scheduled.
- Restore the  registers SP(Using UArea Page number and KPTR),PTBR and PTLR of the new process from the Process Table.
- Update System Status table with new PID
- If the process is in 'CREATED' state:
    - Set the state to 'RUNNING'
    - Set SP to UPTR in Process Table entry
    - Set Mode flag field to 0 (Indication the process is running in user mode)
    - Switch to user mode (goto 9.)

- Else
    - Set the state to 'RUNNING'
    - Pop BP
    - Return to Timer (of the Current Process context, this process will be different from the process in which the timer interrupt occured)



8. Timer Interrupt
-  Restore the user context from the kernel stack
- Set SP to user SP saved in process table
- Set Mode flag entry of the current process in process table to 0.
- Switch to user mode. (IRET)


9. The User Program execution continues and when a timer interrupt occurs again it goes to 6.
    - After the User Program completes execution it calls the exit system call (INT 10)


10. INT 10 (Exit System Call)
    - Change the state of the invoking process to TERMINATED
    - Find out whether all processes except idle are terminated. In that case, halt the system. Otherwise go to 7 to invoke the scheduler(Module 5).






