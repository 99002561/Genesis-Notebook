Practise5: commands and arguments
1. How many arguments are in this line (not counting the command itself).

touch '/etc/cron/cron.allow' 'file 42.txt' "file 33.txt"
answer: three

2. Is tac a shell builtin command ?

Yes..
type tac


3. Is there an existing alias for rm ?

alias rm

4. What is -i option of rm. Create and remove a file to test the -i option.

man rm
touch testfile
rm -i testfile
answer-interactive deletetion

5. Execute: alias rm='rm -i' . Test your alias with a test file. Does this work as expected ?


touch testfile
rm testfile (should ask for confirmation)

sol: yes it asks for confirmation.

6. List all current aliases.

alias
sol-lists all the aliases.

7a. Create an alias called 'city' that echoes your hometown.

alias city='echo "Ballari"'



7b. Use your alias to test that it works.

$ city
sol-Ballari

8. Execute set -x to display shell expansion for every command.

set -x

9. Test the functionality of set -x by executing your city and rm aliases.

shell should display the resolved aliases and then execute the command:
$ set -x
$ city
+ echo antwerp
antwerp

10. Execute set +x to stop displaying shell expansion.

set +x

11. Remove your city alias.

unalias city

12. What is the location of the cat and the passwd commands ?

which cat ( which cat (probably /bin/cat))
which passwd (probably /usr/bin/passwd)

13. Explain the difference between the following commands:
echo
/bin/echo

sol-The echo command will be interpreted by the shell as the built-in echo command. The /bin/echo command will make the shell execute the echo binary located in the /bin directory


14. Explain the difference between the following commands:
echo Hello
echo -n Hello

sol-The -n option of the echo command will prevent echo from echoing a trailing newline. echo Hello will echo six characters in total, echo -n hello only echoes five characters.

15. Display A B C with two spaces between B and C.

echo "A B  C"
sol-A B  C

16. Display (do not use spaces) exactly the following output:
4+4		=8
10+14 	=24

echo -e "4+4\t=8" ; echo -e "10+14\t=24"

17. Use echo to display the following exactly :??\\
Find two solutions with single quotes, two with double quotes and one without quotes.

??\\
echo '??\\'
echo -e '??\\\\'
echo "??\\\\"
echo -e "??\\\\\\"
echo ??\\\\


18. Use one echo command to display three words on three lines.
sol:
echo -e "hello\\nhi\\nBallari" 


