#include <stdio.h>

// Atomic data types in C

int main() {
    int iNumber=0;      // an integer
    float fStuff=0.0;   // a floating point number
    double dfStuff=0.0; // a floating point number with double precision
    char cLetter='A';   // a character

    printf("The value of X is %d\n", iNumber);

    // Every character has a numeric (ASCII) code associated with it
    // C treats characters as integers
    printf("The value of cLetter is %c, %d\n", cLetter, cLetter);

    return 0;
}