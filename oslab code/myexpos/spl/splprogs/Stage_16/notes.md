# Stage 16

## Notes

1. A process must use the XSM instruction IN to read data from the console into the input port P0

2. On encountering a load/store instruction, the XSM machine will start a disk transfer, increment IP by two and fetch the next instruction without waiting for the data transfer to be completed. When the actual disk-memory data transfer is completed, the disk controller will raise the disk interrupt.

3. Similarly, the IN instruction initiates a console input but will not suspend machine execution till some input is read. Machine execution proceeds to the next instruction in the program. When the user enters data, the data is transferred to port P0, and a console interrupt is raised by the console device.

4. The XSM machine enables interrupts only when the machine is executing in unprivileged mode.(If a previously initiated load/store/IN operation is completed while XSM is running in privileged mode, the machine waits for next transition to unprivileged mode before processing the interrupt.)

5. When does data arrive in P0? This happens when some string/number is entered from the key-board and ENTER is pressed. At this time, the XSM machine will raise the console interrupt.

6. When the Acquire Terminal function assigns the terminal to a process, it enters the PID of the process into the PID field of the terminal status table.

7. Interrupts are disabled when machine runs in the privileged mode so that there are no race conditions.

## Expl
1. All global variables, arrays and functions in a program must be declared as global.

2. The main function should return 0

3. Return statement cannot be inside an if or while statement


## Doubts
1. Does expl converts datatypes implicitly while accepting values from terminal