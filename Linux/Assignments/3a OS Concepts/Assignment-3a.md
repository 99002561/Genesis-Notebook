# Assignment - 1

1. Write a program to copy one file contents to other using open,read,write,close system 
   calls (like cp command, which takes source, destination files as cmd line args). 

2. Write a program to display file contents on console (like cat command)

3. Write a program to count no.of lines, words, characters in given file (like wc command)

4. Design a mini shell of your own as follows
   * take command name as input from user (string format)
   * launch the command in the child process using execl/execlp
   * parent will wait for completion of child and print exit status

5. Write a program to compile & link any c/c++ program within child process by launching gcc using execl/execlp.

6. Write a program to compute parallel sum of large array using threads. For e.g. if there are 1000 elements in array, you may create 10 threads where each thread will compute some of 100 elements each, on completion of threads main thread will consolidate final total

7. Write a program to run few threads with different attributes (scheduling policy, scheduling priority, CPU affinity)

8. Write a program to find min/max element from large array using parallel computations (multthreading)

9. Write a program to print current time periodically (Hint:- alarm, time, ctime)

10. Write a program to send specific signal to a target process (with given id, like kill command)

11. Write a program to compute time taken for execution of a function/code snippet (Hint:- gettimeofday or clock_gettime)

12. Write a program to print various resource limits using getrlimit system call (like ulimit command)

13. Write a program to build multifile program using fork & exec as follows
   * There are multiple source files holding some functions
   * Create multiple child processes to compile each source file (execl/execlp)
   * On successful completion, launch another child process for linking
   * On successful linking, launch another child process for executing

14. Extend the above problem, by creating static library with compiled object files

15. Extend mini shell problem to take command line arguments

16. Rewrite the program of copying files, to handle large files by copying small buffer at a time (chunk by chunk)

