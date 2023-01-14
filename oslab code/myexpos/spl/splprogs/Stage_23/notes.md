# Stage 23

1. The compiler generates executable file that is dependent on the operating system as well as the target machine.

2. File access permissions are not used for executable files. They can only be created externally and loaded using the external interface.

3. eXpOS allows only data files to be created using ​Create ​system call. 

4. As noted previously, as data is written into the file by the ​Write ​system call, new disk blocks may be allocated

5. The reason for this duplication is that root file is designed to be readable by user programs using the ​Read ​system call.(unlike the inode table, which is accessed exclusively by OS routines only)

6. OPEN INSTANCE COUNT (1 word) - specifies the number of processes sharing the open instance of the file represented by this open file table entry.

FILE OPEN COUNT (1 word) - specifies the number of open instances of the file. This field is set to -1 if there are no open instances of the file in the system.(File Status Table)


7. Inode - each file descriptor
   Buffer- temp storage
   disk- disk storage

8. The resources are acquired in the order Inode-buffer-disk and must be released in the reverse order when the actions are completed. This avoids circular wait - a sufficient condition for deadlock prevention.

# Question
1. What would happen if we do not initilize the FILE OPEN COUNT in the File Status Table to -1?
2. Does disk blocks get freed anywhere else other than the delete system call?


# Doubt
1. In shutdown system call , should the current process pid taken from system status table