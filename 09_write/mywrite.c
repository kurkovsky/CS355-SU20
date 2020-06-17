// Working scaffolding for the write system command

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 1024

int main(int ac, char  *av[]) {
    if(ac!=2)   // the program requires one parameter: the target terminal name
                // you may need to add /dev before ttyname, e.g. /dev/pts/1
        fprintf(stderr, "usage: %s ttyname\n", av[0]);
    else {
        int fd=open(av[1], O_WRONLY);   // open the target terminal for writing
        if(fd==-1)                      // what if it could not be opened
            perror(av[1]);
        else {
            char buf[BUFSIZE];
            char byeMessage[]="EOF";
            while(fgets(buf, BUFSIZE,stdin)!=0) {   // read a string from the current terminal
                if(write(fd,buf,strlen(buf))==-1)   // and write it to teh target terminal
                    break;
            }
            write(fd, byeMessage, strlen(byeMessage));  // print EOF at the very end of the session
            close(fd);
        }
    }
}