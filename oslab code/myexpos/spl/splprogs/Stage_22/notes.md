# Stage 22
1. Semid is basically the index of the semaphore table entry for the semaphore.
2. Index of the semaphore  entry in the per-process resource table is semaphore descriptor.

# Doubts
1. Why is pid needed for Acquire Semaphore
2. For stage 22 assignment 2,  all memory pages get filled and two process get into WAIT_MEM state.As the shell program waits only for the process it executed (pid:2),  after pid:2 is executed shell gets scheduled (leaving the other two processes in wait state,unexecuted)

# Mistakes I made
1. For Fork while copying contents of the stack from parent to child , I assumed the two stacks to be contiguous.