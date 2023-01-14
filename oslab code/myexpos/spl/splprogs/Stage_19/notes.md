# Stage 19

1. There are four events that result in generation of an exception in XSM. These events are 
    - illegal memory access
    - illegal instruction
    - arithmetic exception
    - page fault.

2. In current implementation of demand paging two pages for heap is allocated instead of one (very lazy loading) because of some compllications in implementing the fork system call


3. In module 2 contrary to what I did in module 1, I am checking whether a page is valid by checking whether the address pointed by page table is "-1" rather than checking the valid bit.

4. We are not releasing code pages from disk in free page table , as we need them atleast in the disk.




5. Difference between EPN and EMA
EPN (Exception Page Number): The contents of this register are valid only in the case of a page fault exception. The logical page number that caused the page fault is stored in this register. In the above example, if MOV R0, [5000] caused a page fault because logical page 8 was invalid, then EPN will have value 8. Note that if the instruction fetch caused a page fault (say IP=3000), then EPN would have contained value 5.

EMA (Exception memory address): The value of this register is relevant only in the case of illegal memory access. The illegal memory which was tried to be accessed is stored in the register. Either the address referred to is outside the range 0 - 512*(PTLR-1) or a write is attempted to a page which is read-only.

6. The page fault exception (EC=0) occurs when the last instruction in the currently running application tried to either -
a) Access/modify data from a legal address within its address space, but the page was set to invalid in the page table or
b) fetch an instruction from a legal address within its address space, whose page table entry is invalid.

7. The XSM machine doesn't push the return address into the user stack when the exception occurs, instead it stores the address in the EIP register.



# Doubt
1. Why is pid passed for release block function? (It is not used in final version)

2. Did not understand this:


    Q2. Why does the exception handler save the contents of the EIP register immediately into the kernel stack upon entry into the exception handler?
    The execption handler may block for a disk read and invoke the scheduler during it's course of execution. The value of the EIP register must be stored before scheduling other processes as the current value will be overwritten by the machine if an exception occurs in another application that is scheduled in this way.

    So is there a chance of losing EPN also?


3.EXPL NULL is null

# Errors
1. Exception Handler has some error in Stage 19, corrected in stage 20, more info refer notes of stage 25
