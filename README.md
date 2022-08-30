
# Star Wars Themed Shell

The robust shell interface program with the Star Wars theme. It supports the execution of system commands as well as built-in commands. Piping is allowed.

Built-in commands include : 

-cd : A command used to change the current directory. 

-ls : A command that lists all files in a current directory.

-exit : A command used to exit the shell.

-cp : A command used to copy files and directories to another location.

-history : A command that displays a list of commands used in the shell terminal. Options: -r (print a list of commands in reverse order) 

-fortune : A command  that displays random quotes from a database. Options : -all (displays all quotes from the database) 

-free : A command which provides information about the total amount of the physical and swap memory, as well as the free and used memory. Options : -b (displays information in bytes), -k (displays information in kilobytes), -m (displays information in megabytes), -g (displays information in gigabytes)

-forkbomb : A command which calls fork system call recursively until the system eventually becomes overloaded and is unable to respond to any input.


## Instructions for compiling

gcc -Wall shell.c -o shell -lreadline

./shell
## Challenges

- Understanding of writing a shell in C.
- Implementation of piping.
- Implementation of the free command, which required specific C functions that were unfamiliar to us. 
- Some time complexitiy problems for our built-in commands.
## Sources

https://www.geeksforgeeks.org/making-linux-shell-c/ 
https://www.geeksforgeeks.org/introduction-of-system-call/
https://stackoverflow.com/questions/20447187/c-linux-shell-repeat-the-recent-commands
https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/
https://www.geeksforgeeks.org/fork-bomb/
https://stackoverflow.com/questions/349889/how-do-you-determine-the-amount-of-linux-system-ram-in-c
https://www.theurbanpenguin.com/4184-2/
https://stackoverflow.com/questions/20974717/why-does-read-have-to-be-a-system-call-run-in-kernel-mode


## Questions


Q1: Do the following actions require the OS to use kernel mode or user mode is sufficient? Explain.

1. A program wants to read from disk.

User mode cannot be sufficient for this task. If a program wants to read from disk, the OS has to switch from user to kernel mode because it is a privileged action which cannot be executed from the user mode. The program that requires reading from the disk has to ask the OS to access the hardware (disk). In order to do that, the program uses system calls. For this example, a program has to use read() system call.

2. Reading the current time from the hardware clock.

Reading the current time from the hardware clock is not a privileged action. It is rather harmless so it can be done in the user mode with corresponding functions.

Q2: Explain the purpose of a system call. There are different sets of system calls: list them and give at least 2 examples of a system call for each category.

The main purpose of system calls is for the application to be able to communicate with the operating system. System calls provide an interface to the services of the OS via Application Program Interface (API). They allow user-level processes to switch to the kernel mode and request services from the OS. 

There are 5 different sets of system calls:

1.Process control -  System calls that are directly related to the processes such as fork(), exec() and wait().
2.File management - System calls for handling the files such as read(), write() and open().
3.Information maintenance - System calls used to maintain information such as getpid(),sleep() and alarm().
4.Device management - System calls that deal with devices such as ioctl(), read() and write().
5.Communication- System calls used for communication such as pipe(), shmget() and mmap().

## Authors

- [@eminasirbubalo](https://github.com/eminasirbubalo)
- [@MakAlijevic](https://github.com/MakAlijevic)



