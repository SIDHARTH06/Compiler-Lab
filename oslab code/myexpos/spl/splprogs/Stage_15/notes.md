# Stage 15

## Notes

1. Resource Manager Module (Module 0)
2. Before the use of a resource, a process has to first acquire the required resource by invoking the resource manager. A process can acquire a resource if the resource is not already acquired by some other process. If the resource requested by a process is not available, then that process has to be blocked until the resource becomes free.
3. When a process releases a resource, the state of other processes waiting for the resource must be set to READY. 
4. The OS maintains a data structure called the Terminal Status Table. The Terminal Status table contains details of the process that has acquired the terminal.
5. In the Resource Manager module, Acquire Terminal and Release Terminal have function numbers 8 and 9 respectively.
6. Acquire Terminal and Release Terminal are not directly invoked from the write system call. Write system call invokes a function called Terminal Write present in device manager module (Module 4). Terminal Write function acts as an abstract layer between the write system call and terminal handling functions in resource manager module. 
7. Terminal Write first acquires the terminal by calling Acquire Terminal. It prints the word (present in R3) passed as an argument. It then frees the terminal by invoking Release Terminal.
8. Since the invoked module will be modifying the contents of the machine registers during its execution, The invoker must save the registers in use into the (kernel) stack of the process before invoking the module.
9. The Acquire Terminal function described above waits in a loop, in which it repeatedly invokes the scheduler if the terminal is not free. This kind of a waiting loop is called a busy loop or busy wait. 
10. We haven't saved any registers into the stack while invoking the boot module from the OS startup code or the scheduler module from the timer interrupt routine as there was no register context to be saved. However, to invoke scheduler module from other modules or interrupt routines, it is necessary to save the register context into the stack for proper resumption of execution.


## Doubts
1.Pop the registers pushed before. (Note that this code will be executed only after the scheduler schedules the process again, which in turn occurs only after the terminal was released by the holding process by invoking the release terminal function.)

What does the content in the bracket mean?

2. Doubt in Q1.Conditions for the deadlock to occur , the preemption contidion is also valid ryt?

3. Is the output of Stage 15 as expected