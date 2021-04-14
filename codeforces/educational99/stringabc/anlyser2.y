%{ 
  #include<stdio.h> 
  #include<stdlib.h> 
  int fincount = 0;
 %} 
  
%token A B C NL 
  
/* Rule Section */
%% 
E: P Q NL {
            if(fincount) fincount--;
            printf("Count is : %d", fincount); 
             exit(0);} 
; 

P : B C Q{
    fincount++;
}
| R
;
Q : A P{
    fincount++;
}
;
R : P 
| Q 
|
;
%% 
  
int yyerror(char *msg) 
 {   printf("%d", fincount);
     printf("erronious string\n");
 } 
  
  
//driver code  
main() 
 { 
  printf("enter the string\n"); 
  yyparse();

 }