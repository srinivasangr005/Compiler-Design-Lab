AIM: 
To write a C program to implement the concept of operator precedence. 
ALGORITHM: 
1. Start the program. 
2. Include the required header files and start the declaration of main method. 
3. Declare the required variable and define the function for pushing and poping the 
characters. 
4. The operators are displayed in coliumn and row wise and stored it in a queue. 
5. Using  a switch case find the values of the operators. 
6. Display the precedence of the operator and generate the code for precedence of operator 
for the given expression. 
7. Compile and execute the program for the output.  
8. Stop the program 
 
PROGRAM 
 
#include<stdlib.h>  
#include<stdio.h>  
#include<string.h>  
   
// function f to exit from the loop  
// if given condition is not true  
void f()  
{  
    printf("Not operator grammar");  
    exit(0);  
}  
   
void main()  
{  
    char grm[20][20], c;  
   
    // Here using flag variable,  
    // considering grammar is not operator grammar  
    int i, n, j = 2, flag = 0;  
   
    // taking number of productions from user  
    scanf("%d", &n);  
    for (i = 0; i < n; i++)  
        scanf("%s", grm[i]);  
   
    for (i = 0; i < n; i++) {  
        c = grm[i][2];  
   
        while (c != '\0') {  
   
            if (grm[i][3] == '+' || grm[i][3] == '-' 
                || grm[i][3] == '*' || grm[i][3] == '/')  
   
                flag = 1;  
   
            else {  
   
                flag = 0;  
                f();  
            }  

 
 
            if (c == '$') {  
                flag = 0;  
                f();  
            }  
   
            c = grm[i][++j];  
        }  
    }  
   
    if (flag == 1)  
        printf("Operator grammar");  
}  
 
Input :3 
A=A*A 
B=AA 
A=$ 
 
Output : Not operator grammar 
 
Input :2 
A=A/A 
B=A+A 
 
Output : Operator grammar 
 
 
 
 
 
 
RESULT: 
   Thus the C program implementation for operator precedence is executed and verified. 
