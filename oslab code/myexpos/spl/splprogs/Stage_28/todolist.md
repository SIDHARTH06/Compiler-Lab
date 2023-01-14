1. Current issue of block exceeding 2 at int4.spl
2. Need to update to call module after changing to kernel stack
3. Need to update release lock before changing to user stack(from int 4)
4. Check SP value getting coorrepted by release lock

//This has not been yet done
5. Check whether mode is changed before kern lock