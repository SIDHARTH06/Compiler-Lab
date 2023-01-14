# Stage 28
1. MAX_MEM_PAGE is set to 512 in spl constants
2. Placing locks in nexpos is important
3. The process will be set to CREATED State in the end of fork system to prevent it from getting scheduled by the other core.
4. Made changes in scheduler to Schedule the Shell process if  LOGOUT_STATUS=1 and the secondary core is  running IDLE2.

5. While executing assignment 5 of Stage 27 (for peterson algorithm, tsl somehow worked), it was getting to a loop. I checked it to see that almost all processes were swapped ,  a process in CREATED STATE too was SWAPPED. Only processes in READY State were swapped in, so this has to handled in SWAP IN function of pager module.