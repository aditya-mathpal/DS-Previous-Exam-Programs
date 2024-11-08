/*
Solve the following problem of sorting the elements in a ragged array using a C program. Write a
function called Create that accepts an integer pointer to pointer and an integer 'n' and creates a
ragged array consisting of 'n' rows using dynamic memory allocation functions.

Write a recursive function called Sort which accepts an integer pointer and an integer 'm' to sort
each row of the ragged array. Write the main function to test the above two functions and to display
the ragged array before and after sorting.
*/

// solution:
#include<stdio.h>
#include<stdlib.h>

int** Create(int** p, int n) {
    p = (int**)malloc(n*sizeof(int*));
    int num, e;
    for(int i = 0;i<n;i++) {
        printf("Enter number of elements in row %d: ", i+1);
        scanf("%d",&num);
        p[i] = (int*)malloc((num+1)*sizeof(int));
        p[i][0] = num;
        printf("Enter elements of row %d: ", i+1);
        for(int j=1;j<=num;j++) {
            scanf("%d",&e);
            p[i][j] = e;
        }
    }
    return p;
}

int* Sort(int* p, int m) {
    if(m<=1) return p;
    int max = m;
    for(int i=1;i<=m;i++) {
        if(p[i]>p[max]) max = i;
    }
    if(max!=m) {
        int temp = p[m];
        p[m] = p[max];
        p[max] = temp;
    }
    Sort(p,m-1);
}

int main() {
    int **p = NULL, n;
    printf("Enter number of rows: ");
    scanf("%d",&n);
    p = Create(p,n);
    printf("The ragged array is:\n");
    for(int i=0;i<n;i++) {
        for(int j=1;j<=p[i][0];j++) {
            printf("%5d",p[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++) p[i] = Sort(p[i],p[i][0]);
    printf("The sorted ragged array is:\n");
    for(int i=0;i<n;i++) {
        for(int j=1;j<=p[i][0];j++) {
            printf("%5d",p[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++) free(p[i]);
    free(p);
    return 0;
}

/*
sample output:
Enter number of rows: 3
Enter number of elements in row 1: 3
Enter elements of row 1: 3 1 2
Enter number of elements in row 2: 2
Enter elements of row 2: 5 4
Enter number of elements in row 3: 4
Enter elements of row 3: 5 4 3 2
The ragged array is:
    3    1    2
    5    4
    5    4    3    2
The sorted ragged array is:
    1    2    3
    4    5
    2    3    4    5
*/