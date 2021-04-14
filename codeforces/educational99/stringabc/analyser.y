%{ 
  #include<stdio.h> 
  #include<stdlib.h> 
  int counta =0;
  int countb =0;
  int countc =0;
  int fincount = 0;
 %} 
  
%token A B C NL 
  
/* Rule Section */
%% 
E: P Q R NL {
            if(counta <= countb && counta <= countc) fincount+= counta;
            else if(countb <= counta && countb<= countc) fincount+= countb;
            else if(countc <=counta && countc<= countb) fincount+= countc;
            printf("%d %d %d\n", counta, countb,countc);
            printf("Count is : %d", fincount); 
             exit(0);} 
; 
P : A P Q R {
   
        counta++;
        if(counta <= countb && counta <= countc) fincount+= counta;
        else if(countb <= counta && countb<= countc) fincount+= countb;
        else if(countc <=counta && countc<= countb) fincount+= countc;
}
|
; 
Q : B P Q R {
        countb++;
}
|
;
R : C P Q R {
        countc++;
        if(counta <= countb && counta <= countc) fincount+= counta;
        else if(countb <= counta && countb<= countc) fincount+= countb;
        else if(countc <=counta && countc<= countb) fincount+= countc;
};
|
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