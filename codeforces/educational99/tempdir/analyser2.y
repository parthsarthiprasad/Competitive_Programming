%{ 
  #include<stdio.h> 
  #include<stdlib.h> 
 %} 
  
%token A B C NL 
  
/* Rule Section */
%% 
E: Z A B B B S C K  {printf("valid string\n"); 
            ;} 
; 
S: S B
| B
; 
K: K C
| C
;
Z: Z NL
|
;
%% 
  
int yyerror(char *msg) 
 { 
  printf("invalid string\n\n"); 
   break;
 } 
  
  
//driver code  
main() 
 { 
  while(yyparse())printf("enter the string\n"); 
  
 }