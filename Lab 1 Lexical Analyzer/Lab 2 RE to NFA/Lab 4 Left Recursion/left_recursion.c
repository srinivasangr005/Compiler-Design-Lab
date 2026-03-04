#include<stdio.h> 
#include<string.h> 
void main() 
{ 
char input[100], l[50],r[50],temp[10],tempprod[20],productions[25][50]; int 
i=0,j=0,flag=0,consumed=0; 
printf(“Enter the Productions:”); 
scanf(“ %ls->%s”, l, r); 
printf(“ %s”, r); 
while(sscanf(r+consumed, “ % [^l] s”, temp) == 1 &&consumed<=strlen(r)) 
{ 
if(temp[0] == l[0]) 
{ 
flag = 1; 
sprintf(productions[i++], “%s->%s%s ‘\0”, l,temp+1,1); 
} 
else 
} 
sprintf(productions[i++], “%s->%s%s ‘\0”,l, temp,1); 
consumed += strlen(temp)+1; 
if(flag==1) 
{ 
sprintf(productions[i++], “%s->€ \0”, 1); 
printf(“the productions after eliminating left recursion are:\n”); 
for(j=0;j<i;j++) 
printf(“%s \n “, productions[j]); 
} 
else 
printf(“ The Given Grammar has no Left Recursion”); 
} 
