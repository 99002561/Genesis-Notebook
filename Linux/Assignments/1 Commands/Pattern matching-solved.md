Practice9: shell Pattern matching
1. Create a test directory and enter it.
2. Create the following files :
file1 file10 file11 file2 File2 File3 file33 fileAB filea fileA fileAAA file( file 2
(the last one has 6 characters including a space)


3. List (with ls) all files starting with file

sol:user@BLTSP01938:~/testfile$ ls file*
'file('   file10  'file 2'   file33   fileA     fileAB
 file1    file11   file2     filea    fileAAA

4. List (with ls) all files starting with File

sol: user@BLTSP01938:~/testfile$ ls File*
     File2  File3

5. List (with ls) all files starting with file and ending in a number.

sol:  user@BLTSP01938:~/testfile$ ls File*
       File2  File3

6. List (with ls) all files starting with file and ending with a letter

sol: user@BLTSP01938:~/testfile$ ls file*[a-zA-z]
     filea  fileA  fileAAA  fileAB

7. List (with ls) all files starting with File and having a digit as fifth character.

sol: user@BLTSP01938:~/testfile$ ls file[0-9]
     file1  file2

8. List (with ls) all files starting with File and having a digit as fifth character and nothing else.

sol:user@BLTSP01938:~/testfile$ ls File[0-9]
File2  File3

9. List (with ls) all files starting with a letter and ending in a number.

sol: user@BLTSP01938:~/testfile$ ls [a-zA-z]*[0-9]
     file1   file10   file11  'file 2'   file2   File2   File3   file33
     
10. List (with ls) all files that have exactly five characters.
      
sol:    user@BLTSP01938:~/testfile$ ls ?????
       'file('   file1   file2   File2   File3   filea   fileA

11. List (with ls) all files that start with f or F and end with 3 or A.

sol: user@BLTSP01938:~/testfile$ ls f*&&*3 || F*&&*3
'file('   file10  'file 2'   file33   fileA     fileAB
 file1    file11   file2     filea    fileAAA


12. List (with ls) all files that start with f have i or R as second character and end in a number.

sol: user@BLTSP01938:~/testfile$ ls fi*[0-9]||fR*[0-9]
 file1   file10   file11  'file 2'   file2   file33

13. List all files that do not start with the letter F.

sol: ser@BLTSP01938:~/testfile$ ls !F*
'file('   file10  'file 2'   File2   file33   fileA     fileAB
 file1    file11   file2     File3   filea    fileAAA

14. Can echo replace ls ? How can you list the files in the current directory with echo ?

sol:echo *
15. Is there another command besides cd to change directories ?

sol:
