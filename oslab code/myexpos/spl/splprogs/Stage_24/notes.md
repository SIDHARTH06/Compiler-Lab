# Stage 24

1. The global data structure, Open file table keeps track of all the open file instances in the system. (A new entry is created in this table whenever the Open system call is invoked with any file name.) File status table is a global data structure that maintains an entry for every file in the system (not just opened files).

2. Open system call invokes Open function of file manager module to deal with global data structures - file status table and open file table.

3. It is necessary not to be confused between FILE OPEN COUNT (in the file status table) and OPEN INSTANCE COUNT (in the open file table). The former keeps track of the global count of how many times Open system call has been invoked with each file in the system - that is the number of open instances of a file at a given point of time. This count is decremented each time when a Close is invoked on the file by any process. Each open instance could be further shared between multiple processes (via Fork). OPEN INSTANCE COUNT value of a particular open instance essentially keeps track of this "share count".

4. Note that the Root file is different from the other files - It has a reserved memory page copy. 

5. Reading from the root file does not require a buffer, as root file is already loaded into the memory at boot-time.

6. A process needs to acquire a buffer before accessing it to prevent data inconsistency that may arise if other processes are allowed to access the buffer concurrently.

7. Read system call needs to lock the resources - Inode (file), buffer and disk before using them. These are locked in the order 1) Inode 2) buffer and 3) disk and released in the reverse order. This order is also followed while writing to a file. Ordering of resource acquisition is imposed in order to avoid processes getting into circular wait for resources. Avoiding circular wait prevents deadlocks.




# Questions

1. Why did we not check if the file is locked?
A. Because the file descriptor is unique for the process and its children and the change only affects the the process that is closing it.The children can access the file, as resource table of the child process is not changed

# Questions I did not get
1. Why don't we need to maintain file open count for the root file? We still need to maintain open instance count for the root file, why?

2. After acquiring the inode, why do we check if the input file name matches the inode table entry?



# My Questions 
1. Why is the type of the file checked after acquiring the inode in open function in file manager.


# Errors
1. Modification in test 5 (check tst5md.expl)