/*
An implementation of a very basic verison of cp:
copy a source file into a destination file

Pseudocode:
    open sourcefile for reading
    open destinationfile for writing
    while not EOF
        read from sourcefile into buffer
        write from buffer into destinationfile
    close sourcefile
    close destinationfile
 */

 #include <stdio.h>
 #include <fcntl.h>
 #include <unistd.h>

 #define BUFFERSIZE 1024       
 #define COPYMODE 0644

 int main(int ac, char *av[]) {
    int source, dest; 
    char buffer[BUFFERSIZE];
    int numBytes;

    if(ac!=3) {                     // this program must be used with exactly two parameters
        printf("Usage: %s source destination\n", av[0]);
        return 1;
    }
    source=open(av[1],O_RDONLY);    // attempt to open the source file
    if(source==-1) {
        perror(av[1]);
        return 1;
    }

    dest=creat(av[2],COPYMODE);     // attempt to open teh destination file
    if(dest==-1) {
        perror(av[2]);
        return 1;
    }
    
    /*
    What happens when read() is called several times: at the last iteration, 
    read() will not be able to read the entire buffer worth of data
    Source file content: [-----   -----   -----   -----   ---]
    Buffer content:      [=====] [=====] [=====] [=====] [===]
    Iterations:             1       2       3       4      5    
    */

    // attempt read the entire buffer[] worth of data in a loop,
    // as long as there is data to be read from the file, 
    // i.e. until we reach the end of file
    while((numBytes=read(source, buffer, BUFFERSIZE))>0) {
        // if the number of bytes obtained by read() is not the same
        // as the number of bytes written by write()
        if(write(dest, buffer, numBytes)!=numBytes) {
            perror("Write error");  
            return 1;
        }
    }
    
    // It is possible that although the source file was succesfully open,
    // it was nto possible to read from it
    if (numBytes == -1) {
        perror("Read error");
        return 1;
    }

    if(close(source)==-1 || close(dest)==-1) {
        perror("Error closing files");
        return 1;
    }
    return 0;
 }