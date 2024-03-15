%{
	#include "quad.c"
	#include <stddef.h>
	#include <stdio.h>
	#include <string.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <time.h>
	#include "pile.h"

	
	int line_number=1, Col=0;

	int yylex();
	int yyerror(char* msg);

	void afficheErreur(char* d , int a)
    {   
    }
    void initialisationMC();
    void afficherMS();
    void afficher();
    void afficherDecl();

%} 



%union {
int num;
float real;
char car;
char * str;
struct {
char * type;
char * val;
} EXP;

}

%type <str> var 
%type <str> INIT_FINISH
%type <str> OPER
%type <EXP> CMP
%type <EXP> CONDITION
%type <EXP> RIGHT_SIDE
%type <EXP> LEFT_SIDE
%type <EXP> ELEMENT 
%type <EXP> case
%type<str>  TYPE  
%type<EXP>  VALUE

%token mc_var mc_dec mc_inst mc_read mc_write <str>mc_int <str>mc_float mc_const mc_struct mc_if mc_else mc_for mc_while 
%token <str>idf <num>entier <num>entier_sign <real>reel <real>reel_sign <str>chaineC
%token<str> and or negation sup inf sup_eg inf_eg egal not_egal 
%token <str>slash <str>plus <str>minus <str>multiply 
%token<str> pnt_vir virgule aff square_brackets_o square_brackets_f curly_brackets_o curly_brackets_f round_brackets_o round_brackets_f pnt double_pnt 

%left entier entier_sign 
%left reel reel_sign
%left plus minus
%left multiply slash
%left and
%left or
%left sup inf sup_eg inf_eg egal not_egal


%start S

%% 

S : mc_var curly_brackets_o PARTIE_DECLARATION curly_brackets_f mc_dec curly_brackets_o PARTIE_DECLARATION curly_brackets_f mc_inst curly_brackets_o PARTIE_CODE curly_brackets_f
{ printf ("\n\nProgramme syntaxiquement correcte\n\n"); YYACCEPT; }
;

PARTIE_DECLARATION :  DECLARATION_VARIABLE PARTIE_DECLARATION
					| DECLARATION_CONST PARTIE_DECLARATION
					| DECLARATION_TABLEAU PARTIE_DECLARATION
					|
;

DECLARATION_VARIABLE : TYPE LISTE_VAR pnt_vir 
					| TYPE idf aff VALUE pnt_vir 
;

TYPE :    mc_int 
		| mc_float 
;

LISTE_VAR : idf virgule LISTE_VAR 		
			|idf  
;

DECLARATION_CONST : mc_const idf aff VALUE pnt_vir
;

VALUE :  entier
		|round_brackets_o entier_sign round_brackets_f
		| reel  
		| reel_sign  
;


DECLARATION_TABLEAU : TYPE idf square_brackets_o entier square_brackets_f pnt_vir 
                     |TYPE idf square_brackets_o entier_sign square_brackets_f pnt_vir

;

PARTIE_CODE :     SIMPLE_INSTRUCTIONS PARTIE_CODE
				| COMPLEX_INSTRUCTIONS PARTIE_CODE
				|
;




SIMPLE_INSTRUCTIONS :  LEFT_SIDE aff RIGHT_SIDE pnt_vir	 		
;


LEFT_SIDE :  idf 
			| case
			  
;


RIGHT_SIDE :  ELEMENT 		
			| ELEMENT OPER RIGHT_SIDE  
		    | round_brackets_o ELEMENT round_brackets_f OPER RIGHT_SIDE
			| round_brackets_o ELEMENT round_brackets_f
		    | round_brackets_o ELEMENT OPER RIGHT_SIDE round_brackets_f OPER RIGHT_SIDE
	     	| round_brackets_o ELEMENT OPER RIGHT_SIDE round_brackets_f
		    
		       
;


ELEMENT :idf 
		| case 
        |VALUE 
;


OPER : plus
	| minus
	| slash
	| multiply
;

case: idf square_brackets_o var square_brackets_f 
; 

var : idf 
    | entier 
    ;


COMPLEX_INSTRUCTIONS :
 mc_if round_brackets_o CONDITION round_brackets_f curly_brackets_o PARTIE_CODE curly_brackets_f ELSE
| mc_for round_brackets_o idf double_pnt INIT_FINISH double_pnt entier double_pnt INIT_FINISH round_brackets_f curly_brackets_o PARTIE_CODE curly_brackets_f 
| mc_while round_brackets_o CONDITION round_brackets_f curly_brackets_o PARTIE_CODE curly_brackets_f
| mc_read round_brackets_o idf round_brackets_f pnt_vir
| mc_write round_brackets_o INSTRUCTION_WRITE round_brackets_f pnt_vir					
;

INSTRUCTION_WRITE :
    write_arg
    | write_arg virgule INSTRUCTION_WRITE
    ;

write_arg :
    chaineC
    | idf
    ;

ELSE :   mc_else curly_brackets_o PARTIE_CODE curly_brackets_f 
		| 
;

CONDITION :   RIGHT_SIDE CMP RIGHT_SIDE 
			| RIGHT_SIDE CMP RIGHT_SIDE and CONDITION
			| RIGHT_SIDE CMP RIGHT_SIDE or CONDITION
			| round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f
            | negation round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f
			| round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f and CONDITION
            | negation round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f and CONDITION
		    | round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f or CONDITION
			| negation round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f or CONDITION

;


CMP : sup 
	| inf 
	| sup_eg 
	| inf_eg 
	| egal 
	| not_egal 
;

INIT_FINISH : entier 
		  | idf 
;



%%


int yyerror(char *msg){ printf("Line %d ,Col %d : Erreur Syntaxique  \n",line_number, Col);exit(0); }

main () 
{ 



 
initialisationMC();
yyparse();
afficherMS();
afficher();
/* afficherDecl(); */
/* afficher_qdr();
optimisation();
afficher_qdr();
createAssembler(qc,liste); */

}
yywrap()
{}