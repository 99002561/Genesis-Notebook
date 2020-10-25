Practice8: shell history
1. Issue the command 
echo The answer to the meaning of life, the universe and everything is 42.

echo The answer to the meaning of life, the universe and everything is 42

2. Repeat the previous command using only two characters (there are two solutions!)

!!
OR
!e

3. Display the last 5 commands you typed.

paul@ubu1010:~$ history 5
 52  ls -l
 53  ls
 54  df -h | grep sda
 55  echo The answer to the meaning of life, the universe and everything is 42
 56  history 5

4. Issue the long echo from question 1 again, using the line numbers you received from the command in question 3.

paul@ubu1010:~$ !55
echo The answer to the meaning of life, the universe and everything is 42
The answer to the meaning of life, the universe and everything is 42

5. How many commands can be kept in memory for your current shell session ?

echo $HISTSIZE

6. Is the current session history stored to ~/.bashrc_history?

echo $HISTFILE


7. Where are these commands stored when exiting the shell ?

echo $HISTFILESIZE


8. How many commands can be written to the history file when exiting your current shell session ?

HISTSIZE=5000


9. Make sure your current bash shell remembers the only 10 commands you type.

when you type exit


10. When is command history written to the history file ?

when the command is executed, the exists at the last.

