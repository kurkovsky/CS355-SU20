// Demonstration of using signal()

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// prints a message and puts the process to sleep for 1 second over 10 iterations
void long_loop() {
    for(int i=0; i<20; i++) {
        printf("Hello %d!\n", i);
        sleep(1);
    }
}

// forward delaration of a signal handler
void ouch(int);

int main() {
    //signal(SIGINT, SIG_IGN);      // ignores the interrupt signal
    signal(SIGINT, ouch);           // reprograms the interrupt signal handler
    long_loop();
}

int ouch_count=0;                   // counts how many times Ctrl-C was pressed

// interrupt signal handler
void ouch(int signum) {
    printf("---OUCH!!!\n");
    ouch_count++;                   
    if(ouch_count>=3) {             // the process will terminate after 3 interrupts
        printf("You are killing me...\n");
        signal(SIGINT, SIG_DFL);    // restore the default interrupt signal handler
        raise(SIGINT);              // generates an interrupt signal, which kills the process
    }
}