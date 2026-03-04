AIM:  
To study the ambiguity, perform Left recursion and Left factoring. 
1.Eliminating Ambiguity 
In Compiler, an ambiguous grammar is a context-free grammar for which there exists 
a string that can have more than one leftmost derivation or parse tree,[1] while an unambiguous 
grammar is a context-free grammar for which every valid string has a unique leftmost derivation 
or parse tree.   
Converting Ambiguous Grammar Into Unambiguous Grammar- 
● Causes such as left recursion, common prefixes etc makes the grammar ambiguous. 
● The removal of these causes may convert the grammar into unambiguous grammar. 
● However, it is not always compulsory. 
Methods To Remove Ambiguity- 
The ambiguity from the grammar may be removed using the following methods- 
● By fixing the grammar 
● By adding grouping rules 
● By using semantics and choosing the parse that makes the most sense 
● By adding the precedence rules or other context sensitive parsing rules 
Removing Ambiguity By Precedence & Associativity Rules- 
An ambiguous grammar may be converted into an unambiguous grammar by implementing- 
● Precedence Constraints 
● Associativity Constraints 
These constraints are implemented using the following rules- 
Rule-01: 
The precedence constraint is implemented using the following rules- 
● The level at which the production is present defines the priority of the operator contained in it. 
● The higher the level of the production, the lower the priority of operator. 
● The lower the level of the production, the higher the priority of operator. 
Rule-02: 
The associativity constraint is implemented using the following rules- 
● If the operator is left associative, induce left recursion in its production. 
● If the operator is right associative, induce right recursion in its production. 
PROBLEMS BASED ON CONVERSION INTO UNAMBIGUOUS GRAMMAR- 
Problem-01: 
Convert the following ambiguous grammar into unambiguous grammar- 
R → R + R / R . R / R* / a / b where * is kleen closure and . is concatenation. 
Solution- 
To convert the given grammar into its corresponding unambiguous grammar, we implement the 
precedence and associativity constraints. 
We have- 
● Given grammar consists of the following operators- 
+ , . , * 
● Given grammar consists of the following operands- 
a , b 
The priority order is- 
(a , b) > * > . > +
where- 
● . operator is left associative 
● + operator is left associative 
Using the precedence and associativity rules, we write the corresponding unambiguous grammar 
as- 
E → E + T / T 
T → T . F / F 
F → F* / G 
G → a / b 
Unambiguous Grammar 
OR 
E → E + T / T 
T → T . F / F 
F → F* / a / b 
Unambiguous Grammar 
2. Left Recursion 
● Left Recursion. The production is left-recursive if the leftmost symbol on the right side 
is the same as the non-terminal on the left side. 
● For example, expr → expr + term. If one were to code this production in a recursive
descent parser, the parser would go in an infinite loop. 
Elimination of left Recursion 
We eliminate left-recursion in three steps. 
● eliminate ɛ -productions (impossible to generate ɛ!) 
● eliminate cycles (A ⇒+ A) 
● eliminate left-recursion 
Elimination of Left Recursion 
Left recursion is eliminated by converting the grammar into a right recursive grammar. 
If we have the left-recursive pair of productions- 
A → Aα / β 
(Left Recursive Grammar)
where β does not begin with an A. 
Then, we can eliminate left recursion by replacing the pair of productions with- 
A → βA’ 
A’ → αA’ / ∈ 
(Right Recursive Grammar) 
This right recursive grammar functions same as left recursive grammar. 
3.Left Factoring 
Left factoring is another useful grammar transformation used in parsing 
Left Factoring is a grammar transformation technique. It consists in "factoring out" prefixes 
which are common to two or more productions. 
For example, going from: 
A -> α β | α γ 
to: 
A -> α A' 
A' -> β | γ 
Left factor: 
Let the given grammar: A-->ab1 | ab2 | ab3 
1)We can see that, for every production, there is a common prefix & if we choose any production 
here, it is not confirmed that we will not need to backtrack. 2)It is non deterministic, because we 
cannot choice any production and be assured that we will reach at our desired string by making 
the correct parse tree. But if we rewrite the grammar in a way that is deterministic and also leaves 
us to be flexible enough to make it any string that may be possible without backtracking.... it will 
be: 
● A --> aA', A' --> b1 | b2| b3 now if we are asked to make the parse tree for string ab2.... we 
don't need back tracking. Because we can always choose the correct production when we 
get A' thus we will generate the correct parse tree. 
● Left factoring is required to eliminate non-determinism of a grammar. Suppose a grammar, 
S -> abS | aSb 
● Here, S is deriving the same terminal a in the production rule (two alternative choices for 
S), which follows non-determinism. We can rewrite the production to defer the decision of 
S as- 
S -> aS' 
S' -> bS | Sb 
Thus, S' can be replaced for bS or Sb
PROGRAM: 
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
OUTPUT: 
Enter the Productions: E-E+T 
The productions after eliminating Left Recursion are:E->+TE’ E-> 
Enter the Productions: 
T->T*F 
The productions after eliminating Left Recursion are: T-> *FT’ T-> 
Enter the Productions: 
F->id
The Given Grammar has no Left Recursion 
/* Program to Implement Recursive Descent Parsing */ 
#include<stdio.h> 
#include<conio.h> 
#include<string.h> 
char input[100]; 
int i,l; 
int main() 
{ 
printf("recursive decent parsing for the grammar"); 
printf("\n E->TEP|\nEP->+TEP|@|\nT->FTP|\nTP->*FTP|@|\nF- 
>(E)|ID\n"); 
printf("enter the string to check:"); 
scanf("%s",input); 
if(E()){ 
if(input[i]=='$') 
printf("\n string is accepted\n"); else 
printf("\n string is not accepted\n"); 
} 
} 
E(){ 
if(T()){ 
if(EP()) 
return(1); 
else 
return(0); 
} 
else 
return(0); 
} 
EP(){ 
if(input[i]=='+'){ 
i++; 
if(T()){ 
if(EP()) 
return(1); else return(0); 
}
else 
return(1); 
} 
} 
T(){ 
if(F()){ 
if(TP()) 
return(1); 
else 
return(0); 
} 
else 
return(0); 
printf("String is not accpeted\n"); 
} 
TP(){ 
if(input[i]=='*'){ 
i++; 
if(F()){ 
if(TP()) 
return(1); 
else 
return(0); 
} 
else 
return(0); 
printf("The string is not accepted\n"); 
} 
else 
return(1); 
} 
F(){ 
if(input[i]=='('){ 
i++; 
if(E()){ 
if(input[i]==')'){ 
i++; 
return(1); 
} 
else 
{ 
return(0); 
Downloaded by Mohammed Shafeek (toxiifired@gmail.com)
lOMoARcPSD|51944412
printf("String is not accepted\n"); 
} 
} 
else 
return(0); 
} 
else if(input[i]>='a'&&input[i]<='z'||input[i]>='A'&&input[i]<='Z') 
{ 
i++; 
return(1); 
} 
else 
return(0); 
} 
OUTPUT: 
$ cc rdp.c 
$ ./a.out 
recursive decent parsing for the grammar E
>TEP| 
EP->+TEP|@| 
T->FTP| 
TP->*FTP|@| 
F->(E)|ID 
enter the string to check:(i+i)*i string is accepted 
RESULT: 
Thus, the process Elimination of Ambiguity,Left Recursion & Left Factoring have been 
studied.
