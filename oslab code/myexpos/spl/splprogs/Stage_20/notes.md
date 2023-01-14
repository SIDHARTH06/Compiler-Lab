# Stage 20

1. When a new process is created using the fork system call, the child process shares the library, code and heap with the parent. The stack region of the parent and the child will be separate.

2. The stack region of a process stores the variables and stack frames during the execution of the program. Since our implementation of eXpOS does not explicitly provide an area for storing static data, they are stored on the stack.

3. Variables to be shared between different processes could also be allocated in the heap.

4. It must be noted here that an application program is free to violate the ABI conventions and decide to use its virtual address space in its own way. It is only required that the executable file follows XEXE format in order to ensure that exec system call does not fail. As long as such a process operates within its own address space, the OS permits the process to execute. However, if at any point during its execution, the process generates a virtual address beyond its permitted virtual address space, a hardware exception will be generated and the OS routine handling the exception will terminate the process.

5. After fork,the child will be allocated two new stack pages and a new user area page.
6. The process table of the child is initialized with the same values of the parent except for the values of TICK, PID, PPID, USER AREA PAGE NUMBER, KERNEL STACK POINTER, INPUT BUFFER, MODE FLAG, PTBR and PTLR. 

7. Upon successful completion, fork returns the PID of the child process to parent process.

8. The return value of fork to the child process is zero.

9. Since the Parent and child processes can concurrently access/modify the heap pages, they need support from the OS to synchronize access to the shared heap memory. eXpOS provides support for such synchronization through systems calls for semaphores and signal handling. 

10. The TICK field keep track of how long a process has been running in memory and should be initialized to 0, when a process is created.

11. PID, PTBR and PTLR fields in process table of child process during fork are initialized in  Get Pcb Entry function

12. It is not required to initialize INPUT BUFFER in process table of child process during fork


13. The eXpOS design guarentees that the stack pages and the user area page of a process will not be swapped at the time when it invokes the fork system call.

# Very Very important 
- When executing init_xfs the machine won't halt after program execution as scheduler schedules the idle process



# Doubt

1. The contents of the parent's kernel stack are not copied to the child, and the kernel stack of the child is set to empty (that is, KPTR field in the process table entry of the child is set to 0.). Why?

2.Store the value in the BP register on top of the kernel stack of child process.Why?
    - When the child is scheduled for the first time , it is in CREATED state , so how does the scheduler know there is user context to be restored? (What about BP?)
    -There is also doubt whether should I update KPTR
    - Things worked without updating KPTR, why?




# Mistake I made
1. Used load instead of loadi in boot module