/*
 Illustrate the concept of dangling pointer and Write a program in C to print all the alphabets using
 pointer.
*/

// solution
#include<stdio.h>
#include<stdlib.h>

int main() {
    char *p = (char*)malloc(sizeof(char));
    free(p); // p is now a dangling pointer, the memory location it pointed to has now been freed
    p = (char*)malloc(sizeof(char)); // malloc-ed again
    *p = 'A';
    for(int i=0;i<26;i++) {
        printf("%5c",(*p)++);
    }
    return 0;
}

/*
output:
    A    B    C    D    E    F    G    H    I    J    K    L    M    N    O    P    Q    R    S    T    U    V    W    X    Y    Z
*/