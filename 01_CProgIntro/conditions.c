#include <stdio.h>

// Using conditions in C

int main() {
    int iAge;
    printf("How old are you? ");
    
    // Read a value from teh terminal and verify that it was interpreted correctly by scanf()
    if(scanf("%d", &iAge)==0)       
        printf("scanf() could not read your input!\n");

    //printf("You told me that you %d years old.\n", iAge);

    if(iAge>0 && iAge<=120) {
        if(iAge<21) {
            printf("You cannot legally enjoy alcohlic beverages\n");
        }
        else {
            printf("Hello! Your age is %d\n", iAge);
        }
    }
    else
        printf("You entered an invalid age: %d\n", iAge);

    return 0;
}