%{ 
  #include<stdio.h> 
  #include<stdlib.h> 
 %} 
  
%token A B C NL 
  
/* Rule Section */
%% 
E: A B B B B S C C K NL {printf("valid string\n"); 
             exit(0);} 
; 
S: S B
|
; 
K: K C
|
;
%% 
  
int yyerror(char *msg) 
 { 
  printf("invalid string\n"); 
  exit(0); 
 } 
  
  
//driver code  
main() 
 { 
  printf("enter the string\n"); 
  yyparse();
 }