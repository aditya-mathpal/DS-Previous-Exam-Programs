/*
Define a structure Employee having following members
i) Name -a char array type
ii) Empcode-an int type
iii) Age- an int type( at the time of join)
iv) Joining date -a pointer to a structure
Date which has three integer members for storing day, month and year.
v) Salary-a float type.

Write a C program to create an array of structure of type Employee to hold details of 'n' employees.
Read the data into the structure array and display the same in main function. Write a function Retire
which takes a pointer of the type structure Employee and compute the retirement year of each
employee and the salary at that time considering 20% hike per year. (standard age of retirement is
60). Test this function from the main function.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Date {
    int day, month, year;
};

struct Employee {
    char name[100];
    int empcode, age;
    struct Date* joiningDate;
    float salary;
};

void Retire(struct Employee* e) {
    printf("Retirement year of employee %s is %d, salary at the time will be %.2f\n",e->name,(60-e->age)+e->joiningDate->year,e->salary*pow(1.2,60-e->age));
}

int main() {
    printf("Enter number of employees: ");
    int n;
    scanf("%d",&n);
    struct Employee *arr = (struct Employee*)malloc(n*sizeof(struct Employee));
    for(int i=0;i<n;i++) {
        arr[i].joiningDate = (struct Date*)malloc(sizeof(struct Date));
        printf("Enter details of employee %d:\n",i+1);
        printf("Name: ");
        getchar();
        fgets(arr[i].name,100,stdin);
        arr[i].name[strlen(arr[i].name)-1] = 0; // remove trailing newline char
        printf("Employee code: ");
        scanf("%d",&arr[i].empcode);
        printf("Age: ");
        scanf("%d",&arr[i].age);
        printf("Date of joining (<day> <month> <year>): ");
        scanf("%d%d%d",&arr[i].joiningDate->day,&arr[i].joiningDate->month,&arr[i].joiningDate->year);
        printf("Salary: ");
        scanf("%f",&arr[i].salary);
        Retire(&arr[i]);
    }
    for(int i = 0;i<n;i++) free(arr[i].joiningDate);
    free(arr);
    return 0;
}

/*
sample output:
Enter number of employees: 1
Enter details of employee 1:
Name: Aditya
Employee code: 2309
Age: 19
Date of joining (<day> <month> <year>): 1 7 2024
Salary: 1000000 
Retirement year of employee Aditya is 2065, salary at the time will be 1763725881.56
*/