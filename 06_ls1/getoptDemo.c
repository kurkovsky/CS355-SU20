#include <stdio.h>
#include <unistd.h>

// a demo of using getopt() to parse input flags

int flagA=0, flagS=0, flagR=0;      // these flags match the three options used in ls1 lab

int main(int argc, char **argv) {
    char option;
    while ((option = getopt(argc, argv, "asr")) != -1){
        switch (option) {
            case 'a': 
                flagA=1;
                printf("flag A enabled\n");
                break;
            case 's':
                flagS=1;
                printf("flag S enabled\n");
                break;
            case 'r': 
                flagR=1;
                printf("flag R enabled\n");
        }
    }

    return 0;
}