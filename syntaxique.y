%{
	#include "quad.c"
	#include <stddef.h>
	#include <stdio.h>
	#include <string.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <time.h>
	#include "pile.h"
	#include "mot.c"
	#include "ts.c"

	int line_number=1, Col=0;
	int ntemp=1;
	char temp [20];
	char temp2 [20];
	char temp3 [20];
	char suavT [20];
	char suavType [20];
	char* sauvidf; 
	char * out;
	char opr1 [20];
	int valTab;
	char sauv_list_obj [20][100];
	int indice_obj = 0;
	char sauv_list_obj2 [20][100];
	int indice_obj2 = 0;
	int qcT=0;
	int qcElse=0;
	int qct2=0;
    int global=1;
	int yylex();
	int yyerror(char* msg);
	void afficheErreur(char* d , int a);


%} 

%union {
int num;
float real;
char car;
char * str;
struct {
char * type;
char * val;
char *t;
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

S : mc_var curly_brackets_o {global=1;}GLOBAL_DECLARATIONS curly_brackets_f mc_dec curly_brackets_o  {global=0;} LOCAL_DECLARATIONS curly_brackets_f mc_inst curly_brackets_o PARTIE_CODE curly_brackets_f
{ printf ("\n\nProgramme syntaxiquement correcte\n\n"); YYACCEPT; }
;


GLOBAL_DECLARATIONS : DECLARATION_VARIABLE pnt_vir GLOBAL_DECLARATIONS
                     |
;

LOCAL_DECLARATIONS : DECLARATION_VARIABLE pnt_vir LOCAL_DECLARATIONS
                    |
;

DECLARATION_VARIABLE : TYPE LISTE_VAR  
					   
					| TYPE idf aff VALUE 
					   { 
						   if(doubleDeclaration($2)==0 ) 
							{  
									if(strcmp(suavType, $4.type) != 0) 
									{
										afficheErreur( $2 , 2);
									}
									else 
									{      

									    char* type = (global == 0) ? "Variable" : "Variable Global";
										inserIdfDecl($2, type);
										insererType($2, suavType, type, 1); // taille de ifd = 1
										insererVal($2,$4.val,$4.type); 
										createQuad("=",$4.t,"",$2);
									}
										 
							}
							else  
							{       
								afficheErreur($2 , 1); 
							}
						}
						
					| mc_const idf aff VALUE 
                   
				    { 
					    if(doubleDeclaration($2)==0 ) 
						{ 
							
						    char* type = (global == 0) ? "Constante" : "Constante Global";
							inserIdfDecl($2, type);
							insererType($2, suavType, type, 1);
							insererVal($2,$4.val,$4.type); 
						}
                        else  
						{   
                            afficheErreur($2 , 1); 
					    }   
					}
    
                    | TYPE idf square_brackets_o entier square_brackets_f 
                        { 
						    if(doubleDeclaration($2)==0 ) 
							{ 

							char* type = (global == 0) ? "Tableau" : "Tableau Global";
							inserIdfDecl($2, type);
							insererType($2, suavType, type, $4);

			                }
                            else 
							{       
                                afficheErreur($2 , 1);
			                }
                        }  
                    | TYPE idf square_brackets_o entier_sign square_brackets_f 
					    { 
						    if(doubleDeclaration($2)==0 ) 
							{ 			                    
								if ($4 > 0) {
									char* type = (global == 0) ? "Tableau" : "Tableau Global";
									inserIdfDecl($2, type);
									insererType($2, suavType, type, $4);
									}
							    else 
								{
                                    afficheErreur($2 , 3); 
								}
							}
							else 
							{      
                                afficheErreur($2 , 1);
				            }
                        }  
;

TYPE :    mc_int {strcpy(suavType,$1);}
		| mc_float {strcpy(suavType,$1);}
;


LISTE_VAR : idf {p = NULL;} virgule LISTE_VAR 
						    { 
							    if(doubleDeclaration($1)==0 )
								{ 
									
									char* type = (global == 0) ? "Variable" : "Variable Global";
									inserIdfDecl($1, type);
									empiler($1); 
									while(p != NULL)  { 
										insererType(depiler(),suavType,type,1); 
										}
								}
                                else  
								{      
                                    afficheErreur($1 , 1); 
							    }
							}
			|idf  
			{ 
			    if(doubleDeclaration($1)==0 )
				{ 

					 char* type = (global == 0) ? "Variable" : "Variable Global";
                     inserIdfDecl($1, type);
                     empiler($1); 
                     insererType(depiler(), suavType, type, 1);

				}
                else  
				{       
                    afficheErreur($1 , 1 ); 
			    }
			}
;



VALUE : entier { $<EXP.type>$=strdup("INTEGER"); char cstE[15];  sprintf(cstE,"%d",$1);    $$.val=strdup(cstE);  $$.t=strdup(cstE);  }
		|round_brackets_o entier_sign round_brackets_f{ $<EXP.type>$=strdup("INTEGER"); char cstE[15];  sprintf(cstE,"%d",$2);    $$.val=strdup(cstE);  $$.t=strdup(cstE);   }
		| reel  { $<EXP.type>$=strdup("FLOAT"); char cstReel[20]; 
			int C = $1;		
             sprintf(cstReel,"%d",C); 
               $$.val=strdup(cstReel);
			   $$.t=strdup(cstReel); }
		| reel_sign  { $<EXP.type>$=strdup("FLOAT"); char cstReel[20];  
		int C = $1;
             sprintf(cstReel,"%d",C);  
               $$.val=strdup(cstReel);  
			   $$.t=strdup(cstReel);}
;



PARTIE_CODE :     SIMPLE_INSTRUCTIONS PARTIE_CODE
				| COMPLEX_INSTRUCTIONS PARTIE_CODE
				|
;




SIMPLE_INSTRUCTIONS :  LEFT_SIDE aff RIGHT_SIDE pnt_vir	 
						{
                           if ( routineModifCst($1.val) != -1)
                            {  
								if(strcmp($1.type,$3.type) != 0 )
									{
										printf("\nErreur semantique %d:%d, incompatibilite des types: type %s:%s  type %s:%s \n", line_number, Col,$1.val,$1.type,$3.val,$3.type);
										_Exit(0);
									}
									else
									{
										
							            insererVal(sauvidf,$3.val,$3.type); 
										// $1.val = $3.val;
										createQuad("=",$3.t,"",$1.val);
									}
							}
						}			
;


LEFT_SIDE : idf 
				{  
					if(routinIdfDeclar($1) == 0)
					{
					   afficheErreur($1 , 5); 
					}
					sauvidf=$1;
					char t2[12];
					typeDeIdf(t2,$1);
					$<EXP.type>$=strdup(t2);
					$$.val=strdup($1) ;
					$$.t=strdup($1) ;
					
					   
				}
			| case
			    {   
				    $<EXP.type>$=strdup($1.type); 
					$$.val=strdup($1.val) ; 
					$$.t=strdup($1.val) ;
					
				}
			
;


RIGHT_SIDE : ELEMENT 
			{  
				$<EXP.type>$=strdup($1.type); $$.val=strdup($1.val) ; 
				$$.t = strdup($1.val);
			}
						
			| ELEMENT OPER RIGHT_SIDE  
			{
			    if(strcmp($1.type,$1.type) == 0)
				{ 
					$<EXP.type>$=strdup($1.type); 
				}
				else 
				{
					$<EXP.type>$=strdup("FLOAT");
				}
				
				strcpy(opr1,$1.val);
				sprintf(temp, "T%d", ntemp); 
				createQuad($2,opr1,$3.t,temp); 

				double result=operationMath(atoi($1.val),$2, atoi($3.val));
				char result_str[50];
				sprintf(result_str, "%.3f", result);
				$$.val = strdup(result_str);
				$$.t = strdup(temp);
			    ntemp++;
				
			}
			
			
			/******************************************************************************************/
			| round_brackets_o ELEMENT round_brackets_f OPER RIGHT_SIDE
			{  
				if(strcmp($2.type,$5.type) == 0)
				{ 
					$<EXP.type>$=strdup($2.type); 
				}
				else 
				{
					$<EXP.type>$=strdup("FLOAT");
				}
				sprintf(temp, "T%d", ntemp); 
				strcpy(opr1,$2.val);
				createQuad($4,opr1,$5.t,temp);
				
				double result=operationMath(atoi($2.val),$4, atoi($5.val));
				char result_str[50];
				sprintf(result_str, "%f", result);
				$$.val = strdup(result_str);
				$$.t = strdup(temp);
			    ntemp++;
				
			}
			
			
			/******************************************************************************************/
			| round_brackets_o ELEMENT round_brackets_f
			{  
				$<EXP.type>$=strdup($2.type); $$.val=strdup($2.val) ; $$.t = strdup($2.val);	
			}
			
			/******************************************************************************************/
			| round_brackets_o ELEMENT OPER RIGHT_SIDE round_brackets_f OPER RIGHT_SIDE
			{
				
				if(strcmp($2.type,$4.type) == 0 && strcmp($2.type,$7.type) == 0)
				{ 
					$<EXP.type>$=strdup($2.type); 
				}
				else 
				{
					$<EXP.type>$=strdup("FLOAT");
				}
				
           			if(strcmp($2.type,$4.type) == 0)
					{ 
						$<EXP.type>$=strdup($2.type); 
					}
					else 
					{
						$<EXP.type>$=strdup("FLOAT");
					}	
					
					sprintf(temp, "T%d", ntemp); 
					strcpy(opr1,$2.val);
					createQuad($3,opr1,$4.t,temp);
					ntemp++;

					sprintf(temp2, "T%d", ntemp); 
					strcpy(opr1,$2.val);
					createQuad($6,temp,$7.t,temp2);

					double result=operationMath(atoi($2.val),$6, atoi($7.val));
					char result_str[50];
				    sprintf(result_str, "%f", result);
				    $$.val = strdup(result_str);
				    $$.t = strdup(temp2);
			        ntemp++;
				
										
			}
			
			/******************************************************************************************/
			| round_brackets_o ELEMENT OPER RIGHT_SIDE round_brackets_f
			{
				    if(strcmp($2.type,$4.type) == 0)
					{ 
						$<EXP.type>$=strdup($2.type); 
					}
					else 
					{
						$<EXP.type>$=strdup("FLOAT");
					}	
					
					sprintf(temp, "T%d", ntemp); 
					strcpy(opr1,$2.val);
					createQuad($3,opr1,$4.t,temp);

					double result=operationMath(atoi($2.val),$3, atoi($4.val));
					char result_str[50];
				    sprintf(result_str, "%f", result);
				    $$.val = strdup(result_str);
				    $$.t = strdup(temp);
			        ntemp++;					
			}
            
		       
;


ELEMENT :idf 
            {  
                if(routinIdfDeclar($1) == 0)
				{
                    afficheErreur($1 , 5);
				}
                char t2[12];
                typeDeIdf(t2,$1);
                $<EXP.type>$=strdup(t2);
				$$.val=strdup($1) ;
				$$.t=strdup($1) ;
			}
			
		/******************************************************************************************/
		| case {   $<EXP.type>$=strdup($1.type); $$.val=strdup($1.val) ;$$.t=strdup($1.val) ;  }
		
		/******************************************************************************************/
        |VALUE  {   $<EXP.type>$=strdup($1.type); $$.val=strdup($1.val) ; $$.t=strdup($1.val) ; }
;


OPER : plus
	| minus
	| slash
	| multiply
;

case: idf square_brackets_o var square_brackets_f 
        {  
		    if(routinIdfDeclar($1) == 0) 
			{
                afficheErreur($1 , 5); 
			}
			sauvidf=$1;
           routineDebordementTab($1,valTab); 
            char idft[12];
            typeDeIdf(idft, $1);
            $<EXP.type>$=strdup(idft); 
			char Tmp[50]; strcpy(Tmp,$1); strcat(Tmp,"["); strcat(Tmp,$3); strcat(Tmp,"]"); 
			$$.val = strdup(Tmp);
			$$.t = strdup(Tmp);

        }
; 
var : idf 
        { 
		    if(routinIdfDeclar($1) == 0)
			{
                afficheErreur($1 , 7);
		    }                                    
            else   
			{ 
			    $$=strdup($1);
            }
        }
    | entier { valTab=$1 ; char cstNat[15];  sprintf(cstNat,"%d",$1); $$=strdup(cstNat); }
    ;




COMPLEX_INSTRUCTIONS : mc_if round_brackets_o CONDITION round_brackets_f 
						{
							qcT=qc;createQuad("BZ","",liste[qc-1].res,"");

						}
					   curly_brackets_o PARTIE_CODE curly_brackets_f ELSE
					   
					   /******************************************************************************************/
						| mc_for round_brackets_o idf double_pnt INIT_FINISH double_pnt entier double_pnt INIT_FINISH round_brackets_f 
						{
						
							if(routinIdfDeclar($3) == 0)
							{
                                afficheErreur($3 , 5); 
							}
							
							createQuad("=",$5,"",$3);
							qcT=qc;
							sprintf(temp, "T%d", ntemp); 
							createQuadC(3,$3,$5,temp);
							ntemp++;
							
							sprintf(temp2, "T%d", ntemp); 
							createQuadC(4,$3,$9,temp2);
							ntemp++;
							
							sprintf(temp3, "T%d", ntemp);
							createQuadL(3,temp,temp2,temp3);
							ntemp++;
							qct2=qc;
							createQuad("BZ","",temp3,"");
							
						}
						  curly_brackets_o PARTIE_CODE curly_brackets_f 
						    {
								sprintf(temp, "T%d", ntemp);
								createQuad("+",$3,convert($7),temp);
								createQuad("=",temp,"",$3);
								ntemp++;
						        createQuad("BR",convert(qcT),"","");
								liste[qct2].op1=convert(qc);
						    }
							
						/******************************************************************************************/
						| mc_while round_brackets_o 
						{
							qcT=qc;
						}
						  CONDITION round_brackets_f 
						{
							qct2=qc;
							createQuad("BZ","",liste[qc-1].res,"");
							
						}
						  curly_brackets_o PARTIE_CODE curly_brackets_f
						{
							createQuad("BR",convert(qcT),"","");
							liste[qct2].op1=convert(qc);
						}

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

ELSE : 	{
			liste[qcT].op1=convert(qc+1);
			qcElse=qc;
			createQuad("BR","","","");
		}
		mc_else curly_brackets_o PARTIE_CODE curly_brackets_f 
		{
			liste[qcElse].op1=convert(qc);
		}
		| {
			liste[qcT].op1=convert(qc);

		}
;

CONDITION : RIGHT_SIDE CMP RIGHT_SIDE 
			{


				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi($2.t),$1.val,$3.val,temp);
                int res = compare(atoi($1.val),$2.val,atoi($3.val));
				const char *res_str = (res == 0) ? "0" : "1"; 
				$$.val = strdup(res_str);
				$$.t = strdup(temp);
				ntemp++;


			}
			/******************************************************************************************/
			| RIGHT_SIDE CMP RIGHT_SIDE and CONDITION
			{
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi($2.t),$1.val,$3.val,temp);
                int res = compare(atoi($1.val),$2.val,atoi($3.val));
				ntemp++;
				
				sprintf(temp2, "T%d", ntemp);
				createQuadL(3,temp,$5.val,temp2);

				 if (res == 1 && strcmp($5.val, "1") == 0) {
					 $$.val = strdup("1");
					 } else {
						 $$.val = strdup("0");
						 }
				$$.t = strdup(temp2);
				ntemp++;
			}
			
			/******************************************************************************************/
			| RIGHT_SIDE CMP RIGHT_SIDE or CONDITION
			{
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi($2.t),$1.val,$3.val,temp);
                int res = compare(atoi($1.val),$2.val,atoi($3.val));
				ntemp++;
				
				sprintf(temp2, "T%d", ntemp);
				createQuadL(2,temp,$5.val,temp2);
				 if (res == 1 || strcmp($5.val, "1") == 0) {
					 $$.val = strdup("1");
					 } else {
						 $$.val = strdup("0");
						 }
				$$.t = strdup(temp2);
				ntemp++;
			}
			
			/******************************************************************************************/
			| round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f
			{
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi($3.t),$2.val,$4.val,temp);
				int res = compare(atoi($2.val),$3.val,atoi($4.val));
				const char *res_str = (res == 0) ? "0" : "1"; 
				$$.val = strdup(res_str);
				$$.t = strdup(temp);
				ntemp++;
			}
			
			/******************************************************************************************/
			| negation round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f
			{
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi($4.t),$3.val,$5.val,temp);
				ntemp++;
				int res = compare(atoi($3.val),$4.val,atoi($5.val));
				const char *res_str = (res == 0) ? "1" : "0"; 
				
				sprintf(temp2, "T%d", ntemp);
				createQuadL(1,temp,"",temp2);
				
				$$.val = strdup(res_str);
				$$.t = strdup(temp2);
				ntemp++;
			}
			/******************************************************************************************/
			| round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f and CONDITION
			{
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi($3.t),$2.val,$4.val,temp);
				int res = compare(atoi($2.val),$3.val,atoi($4.val));
				ntemp++;
				
				sprintf(temp2, "T%d", ntemp);
				createQuadL(3,temp,$7.val,temp2);

				 if (res == 1 && strcmp($7.val, "1") == 0) {
					 $$.val = strdup("1");
					 } else {
						 $$.val = strdup("0");
						 }
				$$.t = strdup(temp2);
				ntemp++;
			}
			/******************************************************************************************/
			| negation round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f and CONDITION
			{
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi($4.t),$3.val,$5.val,temp);
				int res = compare(atoi($3.val),$4.val,atoi($5.val));
				ntemp++;
			

				sprintf(temp2, "T%d", ntemp);
				createQuadL(1,temp,"",temp2);
				ntemp++;
			
				sprintf(temp3, "T%d", ntemp);
				createQuadL(3,temp,$8.val,temp3);

				 if (res == 1 || strcmp($8.val, "1") == 0) {
					 $$.val = strdup("0");
					 } else {
						 $$.val = strdup("1");
						 }	
				$$.t = strdup(temp3);
				ntemp++;
			}
			/******************************************************************************************/
			| round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f or CONDITION
			{
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi($3.t),$2.val,$4.val,temp);
                int res = compare(atoi($2.val),$3.val,atoi($4.val));
				ntemp++;
				
				sprintf(temp2, "T%d", ntemp);
				createQuadL(2,temp,$7.val,temp2);
				 if (res == 1 || strcmp($7.val, "1") == 0) {
					 $$.val = strdup("1");
					 } else {
						 $$.val = strdup("0");
						 }
				$$.t = strdup(temp2);
				ntemp++;
			}
			/******************************************************************************************/
			| negation round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f or CONDITION
			{
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi($4.t),$3.val,$5.val,temp);
                int res = compare(atoi($3.val),$4.val,atoi($5.val));

				ntemp++;
			

				sprintf(temp2, "T%d", ntemp);
				createQuadL(1,temp,"",temp2);
				ntemp++;
			
				sprintf(temp3, "T%d", ntemp);
				createQuadL(2,temp,$8.val,temp3);

				 if (res == 1 && strcmp($8.val, "1") == 0) {
					 $$.val = strdup("0");
					 } else {
						 $$.val = strdup("1");
						 }

				$$.t = strdup(temp3);
				ntemp++;
			}
;

// les valeurs 1..6 sont utilisé comme entrée dans la fonction createQuadC
CMP : sup {$$.val = strdup(">"); $$.t = strdup("1"); }
	| inf {$$.val = strdup("<"); $$.t = strdup("2");}
	| sup_eg {$$.val = strdup(">="); $$.t = strdup("3");}
	| inf_eg {$$.val = strdup("<="); $$.t = strdup("4");}
	| egal {$$.val = strdup("=="); $$.t = strdup("5");}
	| not_egal {$$.val = strdup("!="); $$.t = strdup("6");} 
;

INIT_FINISH : entier {char cstNat[15];  sprintf(cstNat,"%d",$1); $$=strdup(cstNat);}
		  | idf { 
					if(routinIdfDeclar($1) == 0)
					{
						afficheErreur($1 , 5); 
					}
					
				}
;




%%


int yyerror(char *msg){ printf("Line %d ,Col %d : Erreur Syntaxique  \n",line_number, Col);exit(0); }

void afficheErreur(char* d , int a)
    {   
		switch(a)
		{    
		    case 1 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i : Double declaration de la variable %s \n", line_number, Col, d);
			break;
			case 2 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i : incompatibilité des types %s \n", line_number, Col, d);
			break;
		    case 3 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i : la taille du tableau %s est négative ! \n", line_number, Col, d);
			break;
			case 4 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i :  Utilisation d'une Variable %s non initialisé  \n", line_number, Col, d);
				// still did'nt do this one
			break;
			case 5 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i :  Variable Non déclarée %s \n", line_number, Col, d);
			break;
			case 6 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i :  Variable %s non déclarée  \n", line_number, Col, d);
			break;
			case 7 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i :  Indice du tableau non déclarée %s \n", line_number, Col, d);
			break;
			case 8 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i : Modification d'une constante: %s \n", line_number, Col, d);
			break;
			case 9 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i : Dépassement de capacité %s \n", line_number, Col, d);
			break;
			
		}
		exit(0);
    }



int main () 
{ 

initialisationMC();
yyparse();
afficherMS();
afficher();
afficherDecl();

// quadruplets avant optimisation
afficher_qdr();

 /* optimisation();
// quadruplets après l'optimisation
afficher_qdr();
createAssembler(qc,liste);   */
return 0;
}
int yywrap()
{return 0;}