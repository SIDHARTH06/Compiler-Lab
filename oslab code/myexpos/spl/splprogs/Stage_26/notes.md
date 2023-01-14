# Notes
1.  The starting IP of the shell process is stored at first word of user stack of shell, so that the next time when a new user is logged in and shell process is scheduled for the first time in the context of the new user, shell will run as newly created process.



# Questions
1. Login process does not load the shell process, but sets it's state to CREATED. Can it happen that the shell is not present in memory?
A. The shell is loaded into the memory in the boot module ig

2. Why don't we kill the current process (shell) by using the exit_process() module function?
A. Exit process deallocates all pages used by process, but we dont have to as the shell process is to be scheduled in the next login.

# Doubts
1. No ireturn in int12


# Error
1. Username in lu.expl is set as int