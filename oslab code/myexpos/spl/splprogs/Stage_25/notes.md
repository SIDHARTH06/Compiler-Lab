# Stage 25
1. eXpOS design ensures that the value of LSEEK can never exceed the file size. This ensures that a write operation allocates exactly one new block for a file when the LSEEK value is a multiple of 512 and is equal to the file size.


//Seek System Call Questions
1. What concurrency issue can occur if the inode is not locked before reading the lseek position?
A. If some other process has acquired the inode and is reading/writing, lseek value would change in unexpected ways.So we would have to lock the inode , so that other processes are blocked from reading/writing.

2. What goes wrong if the LSEEK is stored in the File Status Table instead of the Open File table?
A.In file status table every file has a single entry, but a file could have multiple file descriptors open in different processes with different lseek value.

3. What goes wrong if the LSEEK is stored in the per-process resource table instead of the Open File table?
A. In this case the file descriptor would not be able to be shared with other processes

4. Which all file system calls set the FILE_SIZE field in the inode status table?
A.Create,Write (Maybe delete also)

5. If your OS code has no bugs, acquire_inode() in the above code will never fail. Why?
A.Since we are getting the Inode index of the file just before acquire_inode, the file is ensured to be present in the disk, so the acquire inode cannot fail. (It can only fail if File was deleted by the time the inode was acquired */)


# Notes
1. Assumed that shell process has process id 1
2. Only basic error checking is implemented shell utilities

# Eureka
1. Found an error in exception handler , using registers before backing up.