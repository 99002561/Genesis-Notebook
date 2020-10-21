# File handling
The fstream library allows us to work with files.

* Library
   - #include <iostream>
   - #include <fstream> 

* Object/Data   Type 	Description
    - ofstream 	Creates and writes to files
    - ifstream 	Reads from files
    - fstream 	A combination of ofstream and ifstream: creates, reads, and writes to files

1. Opening a File
    void open(const char *filename, ios::openmode mode);

    Sr.No 	Mode Flag & Description
    1. 	ios::app
        Append mode. All output to that file to be appended to the end.

    2. 	ios::ate
        Open a file for output and move the read/write control to the end of the file.

    3. 	ios::in
        Open a file for reading.

    4.	ios::out
        Open a file for writing.

    5.	ios::trunc
        If the file already exists, its contents will be truncated before opening the file.
    
    * if you want to open a file in write mode and want to truncate it in case that already exists, following will be the syntax −

    ofstream outfile;
    outfile.open("file.dat", ios::out | ios::trunc );

    * Similar way, you can open a file for reading and writing purpose as follows −

    fstream  afile;
    afile.open("file.dat", ios::out | ios::in );

2. void close();

3. Reading from a File
    You read information from a file into your program using the stream extraction operator (>>) just as you use that operator to input information from the keyboard. 

* [link](https://www.geeksforgeeks.org/csv-file-management-using-c/)
* [link](https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm)