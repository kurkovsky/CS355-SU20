#include <stdio.h>

// introduction to pointers

int main() {
    int x = 5;      // just a regular integer
    int *p = 0;     // an integer pointer

    p = &x;         // p now points to x
    printf("x = %d, *p = %d\n", x, *p);

    x = 15;         // change the value of x
    printf("x = %d, *p = %d\n", x, *p);

    *p = 17;        // change the value pointed to by p
    printf("x = %d, *p = %d\n", x, *p);

    int y = 100;    // another regular integer
    printf("x = %d, y = %d, *p = %d\n", x, y, *p);

    p = &y;         // p now points to y
    printf("x = %d, y = %d, *p = %d\n", x, y, *p);
}