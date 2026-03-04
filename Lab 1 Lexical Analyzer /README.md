AIM: 
To develop a lexical analyzer to identify identifiers, constants, comments, operators etc using C 
program 
ALGORITHM: 
Step1: Start the program. 
Step2: Declare all the variables and file pointers. 
Step3: Display the input program. 
Step4: Separate the keyword in the program and display it. 
Step5: Display the header files of the input program 
Step6: Separate the operators of the input program and display it. 
Step7: Print the punctuation marks. 
Step8: Print the constant that are present in input program. 
Step9: Print the identifiers of the input program 
Program 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<ctype.h> 
int isKeyword(char buffer[]){ 
char keywords[32][10] = {"auto","break","case","char","const","continue","default", 
"do","double","else","enum","extern","float","for","goto", 
"if","int","long","register","return","short","signed", 
"sizeof","static","struct","switch","typedef","union", 
"unsigned","void","volatile","while"}; 
Int i, flag = 0; 
for(i = 0; i< 32; ++i){ 
if(strcmp(keywords[i], buffer) == 0){ 
flag = 1; 
break; 
} 
} 
return flag; 
} 
int main(){ 
char ch, buffer[15], operators[] = "+-*/%="; 
FILE *fp; 
inti,j=0; 
fp = fopen("program.txt","r"); 
if(fp == NULL){ 
printf("error while opening the file\n"); 
exit(0); 
} 
while((ch = fgetc(fp)) != EOF){ 
for(i = 0; i< 6; ++i){ 
if(ch == operators[i]) 
printf("%c is operator\n", ch); 
} 
if(isalnum(ch)){ 
buffer[j++] = ch; 
} 
else if((ch == ' ' || ch == '\n') && (j != 0)){ 
buffer[j] = '\0'; 
j = 0; 
if(isKeyword(buffer) == 1) 
printf("%s is keyw88ord\n", buffer); 
else 
printf("%s is indentifier\n", buffer); 
} 
} 
fclose(fp); 
return 0; 
} 
Output 
The Program is : 'float x = a + 1b; ' 
All Tokens are : 
Valid keyword : 'float' 
Valid Identifier : 'x' 
Valid operator : '=' 
Valid Identifier : 'a' 
Valid operator : '+' 
Invalid Identifier : '1b' 
RESULT: 
Thus the C program to Implementation of Lexical Analyzer A has been executed and the 
output has been verified successfully
