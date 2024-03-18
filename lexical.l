%option yylineno
%{
	#include <stdio.h>
	#include <string.h>
	#include "syntaxique.tab.h"
	#include "ts.h"
	#include "mot.h"
	extern int Col;
	extern int line_number;
	extern YYSTYPE yylval;
	
%}

%option noyywrap

Maj [A-Z]
Min [a-z]
chiffre [0-9]
IDF ({Maj}|{Min})({Min}|{chiffre})*
reel {chiffre}+"."{chiffre}+
reel_sign [+-]{reel}
entier {chiffre}+
entier_sign [+-]{entier}
CMT "%%".*
saut  \r\n|\n 
space ("\t"|" ")+
chaineC \"[^\"]*\"
%%



VAR_GLOBAL  {Col+=yyleng;    rechercherMC (yytext,"Mot cle "," ",0, 1);   return mc_var;}
DECLARATION {Col+=yyleng;    rechercherMC (yytext,"Mot cle "," ",0, 1);   return mc_dec; }
INSTRUCTION {Col+=yyleng;    rechercherMC (yytext,"Mot cle "," ",0, 1);   return mc_inst; }
READ        {Col+=yyleng;    rechercherMC (yytext,"Mot cle "," ",0, 1);   return mc_read; }
WRITE       {Col+=yyleng;    rechercherMC (yytext,"Mot cle "," ",0, 1);   return mc_write; }
INTEGER     {Col+=yyleng;    rechercherMC (yytext,"Mot cle "," ",0, 1);  yylval.str=strdup(yytext); return mc_int;}
FLOAT       {Col+=yyleng;    rechercherMC (yytext,"Mot cle "," ",0, 1);  yylval.str=strdup(yytext); return mc_float;}
CONST       {Col+=yyleng;    rechercherMC (yytext,"Mot cle "," ",0, 1);  yylval.str=strdup(yytext); return mc_const;}
IF          {Col+=yyleng;    rechercherMC (yytext,"Mot cle "," ",0, 1);   return mc_if;}
ELSE        {Col+=yyleng;    rechercherMC (yytext,"Mot cle "," ",0, 1);   return mc_else;}
FOR         {Col+=yyleng;    rechercherMC (yytext,"Mot cle "," ",0, 1);   return mc_for;}
WHILE       {Col+=yyleng;    rechercherMC (yytext,"Mot cle "," ",0, 1);   return mc_while;}


{IDF} {
         Col+=yyleng;
         if (yyleng<8) { 
		           yylval.str=strdup(yytext);
			     inserer(yytext,"IDF",hachage(yytext)); return idf;
                       }
                else printf ("Erreur lexicale: IDF trop long %s a la ligne %d et a la colonne %d \n", yytext, line_number, Col);
	}

{chaineC} {
            Col+=yyleng;
            return chaineC;
         }

{entier} { 
           Col+=yyleng; 
           char* endptr;
           long val = strtol(yytext, &endptr, 10);
           if (endptr != yytext && (val < -32768 || val > 32767)) {
           printf("erreur lexicale a la ligne %d et la colonne %d : Taille entier insupportable %s \n", line_number, Col, yytext);
          }
          else  {
		  yylval.num=atoi(yytext);
		  return entier;
                } 
         }

{entier_sign} {
                Col+=yyleng; 
                char* endptr;
                long val = strtol(yytext, &endptr, 10);
            if (endptr != yytext && (val < -32768 || val > 32767))
             { printf("erreur lexicale a la ligne %d et la colonne %d : Taille entier sign insupportable %s \n", line_number, Col, yytext); }
            else { 
		     yylval.num=atoi(yytext);
                 return entier_sign;
                 }
             }

{reel} {
         Col+=yyleng;    
         char realVal[20];  
         strcpy(realVal,yytext);  
         yylval.real=atof(realVal);
         return reel;
      }

{reel_sign} {
              Col+=yyleng; 
              char realVal[20];
              strcpy(realVal,yytext);
              yylval.real=atof(realVal);
              return reel_sign;  
             }

{CMT}   {Col= Col+ strlen (yytext); line_number = yylineno;}
{space} {Col=+yyleng;}
{saut}  {Col=1; line_number+=yyleng;}



"&&" {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return and;}
"||" {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return or;}
"!"  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return negation;}
">"  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return sup;}
"<"  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return inf;}
">=" {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return sup_eg;}
"<=" {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return inf_eg;}
"==" {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return egal;}
"!=" {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return not_egal;}
"/"  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); yylval.str=strdup(yytext); return slash;}
"+"  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); yylval.str=strdup(yytext); return plus;}
"-"  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); yylval.str=strdup(yytext); return minus;}
"*"  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); yylval.str=strdup(yytext); return multiply;}
"."  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return pnt;}
";"  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return pnt_vir;}
":"  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return double_pnt;}
","  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return virgule;}
"="  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return aff;}
"["  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return square_brackets_o;}
"]"  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return square_brackets_f;}
"{"  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return curly_brackets_o;}
"}"  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return curly_brackets_f;}
"("  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return round_brackets_o;}
")"  {Col+=yyleng; rechercherMC (yytext,"Separateur",0,0, 2); return round_brackets_f;}




. {printf ("erreur lexicale entite %s ligne %d colonne %d \n",yytext,line_number,Col);return 0;}
%%


