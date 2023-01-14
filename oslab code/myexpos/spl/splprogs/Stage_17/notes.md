# Stage 17

1. Exec system call is the program loader

2. Note that the newly scheduled process will have the same PID as that of the invoking process, while using exec

3. Exec calls the Exit Process function in the process manager module (module 1) to deallocate the pages and to terminate the current process.

4. There are 128 entries in the memory free list corresponding to each page of memory.

5.  The user area page holds the kernel stack of the current process. Hence, releasing this page means that the page holding the return address for the call to Free User Area Page function itself has been released! Neverthless the return address and the saved context of the calling process will not be lost. This is because Release Page function is non blocking and hence the page will never be allocated to another process before control transfers back to the caller.

6. The same process table entry and page table of the invoking process will be used by the newly loaded process. But the pages allocated will be different.


# Doubts
1. What do you mean by non blocking?(as in point 5) (IG there wont be any other process in waiting state)

2. Why didnt we make changes in process table entry of user stack in int9?
(Ig it is used only when the process invokes a system call and then it takes care of it)

3. Is multipush() and multipop() necessary everywhere in module to module call?
(Ig its not required , but its better to follow convention).

4. How to check whether a page table entry is valid ? (To see what I did,go to mod_1.spl).

