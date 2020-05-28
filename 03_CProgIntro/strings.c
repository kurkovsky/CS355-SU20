#include <stdio.h>
#include <string.h>     // standard C string library

// how to work with strings in C

int main() {
    char *str1 = "Hello, world!";       // a pointer to a string constant
    printf("str1: %s\n", str1);         

    char str2[20] = "Hello, world!";    // a character array
    printf("str2: %s\n", str2);

    // print all characters in str2 including the terminating 0
    for(int i=0; i<=strlen(str2); i++) {    
        printf("str2[%d]=%c (%d)\n", i, str2[i], str2[i]);
    }

    // this will not work because the string constant is too long for teh array
    //char str3[5] = "This is a long string";  

    // this will not work because str2 is an array and cannot be changed using 
    // the assignment operator
    // instead, strcpy should be used
    //str2 = "This is another string";

    // but this works because str1 is a pointer
    str1 = "This is another string";

    // this will cause a segmentation fault because the source string is longer than
    // the number of characters that str2 can hold
    //strcpy(str2, "This is yet another string, but it is really long");

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
}