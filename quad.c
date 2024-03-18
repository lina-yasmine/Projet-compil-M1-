#include "quad.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int changement = 1;
/*********************************** Creation of the Quad ************************************************/
void createQuad(char* a, char* b, char* c, char* d){
	liste[qc].opr=strdup(a);
	liste[qc].op1=strdup(b);
	liste[qc].op2=strdup(c);
	liste[qc].res=strdup(d);
	qc++;
}
/**********************************conversion d'un int en chaine de caractere******************************/
char* convert(int i){
	char s[15];
	sprintf(s,"%d",i);
	return strdup(s);
}
/***********************************Quads Expression logiques************************************************/
void createQuadL(int i, char*b, char* c, char* d){
	switch(i){
		case 1 :
			createQuad("BNZ",convert(qc+3),b,""); createQuad("=","1","",d); createQuad("BR",convert(qc+2),"",""); createQuad("=","","0",d);
		break;
		case 2 :
			createQuad("BNZ",convert(qc+4),b,""); createQuad("BNZ",convert(qc+3),c,"");createQuad("=","0","",d); createQuad("BR",convert(qc+2),"",""); createQuad("=","1","",d);
		break;
		case 3 :
		createQuad("BZ",convert(qc+4),b,""); createQuad("BZ",convert(qc+3),c,"");createQuad("=","1","",d); createQuad("BR",convert(qc+2),"",""); createQuad("=","0","",d);
		break;
	}
}

/***********************************Quads Expressions de comparaison************************************************/
void createQuadC(int i, char* b, char* c, char* d){
	switch(i){
		case 1 :
			createQuad("-",b,c,d); createQuad("BLE",convert(qc+3),d,"");createQuad("=","1","",d);createQuad("BR",convert(qc+2),"",""); createQuad("=","0","",d);
		break;
		case 2 :
			createQuad("-",b,c,d); createQuad("BGE",convert(qc+3),d,"");createQuad("=","1","",d);createQuad("BR",convert(qc+2),"",""); createQuad("=","0","",d);
		break;
		case 3 :
			createQuad("-",b,c,d); createQuad("BL",convert(qc+3),d,"");createQuad("=","1","",d);createQuad("BR",convert(qc+2),"",""); createQuad("=","0","",d);
		break;
		case 4 :
			createQuad("-",b,c,d); createQuad("BG",convert(qc+3),d,"");createQuad("=","1","",d);createQuad("BR",convert(qc+2),"",""); createQuad("=","0","",d);
		break;
		case 5 :
			createQuad("-",b,c,d); createQuad("BNZ",convert(qc+3),d,"");createQuad("=","1","",d);createQuad("BR",convert(qc+2),"",""); createQuad("=","0","",d);
		break;
		case 6 :
			createQuad("-",b,c,d); createQuad("BZ",convert(qc+3),d,"");createQuad("=","1","",d);createQuad("BR",convert(qc+2),"",""); createQuad("=","0","",d);
		break;
	}
}




/****************************************************************************************************/
void ajour_liste(int num_quad, int colon_quad, char val[])
{
    if (colon_quad == 0)
        strcpy(liste[num_quad].opr, val);
    else if (colon_quad == 1)
        strcpy(liste[num_quad].op1, val);
    else if (colon_quad == 2)
        strcpy(liste[num_quad].op2, val);
    else if (colon_quad == 3)
        strcpy(liste[num_quad].res, val);
}
void suppQuad(int begin){
    int i=begin;
    char buffer[20];
	int num;
    while(i<= qc){
        liste[i]=liste[i+1];
        i++;
    }
    qc--;
    for ( i = 0; i < qc; i++)
    {
        // if its a jump and after our delete reduce the jump pos 
        if((!strcmp(liste[i].opr,"BNZ") || !strcmp(liste[i].opr,"BZ") ||!strcmp(liste[i].opr,"BR"))&&begin<atoi(liste[i].op1)){
           
          num = atoi(liste[i].op1) - 1;
          sprintf(buffer, "%d", num);
          ajour_liste(i, 1, buffer);

        }
    }
    
}
/*******************************************************************************************************/
/*********************************************************************************************************/
void CodeInutile() {
    int i, j, k;
	char t = 'T';
	int test  = 0;
    char myString[20];
    
	//if res is not used in all the rest of quads as operand then delete it
    for (i = 0; i < qc; i++) {
		           
		strcpy(myString, liste[i].res);
        char firstLetter = myString[0];
        if (strcmp(liste[i].opr, "=") == 0 && firstLetter ==t)
    	{   
            for (j = i + 1; j < qc; j++) 
			{  
               if (strcmp(liste[i].res, liste[j].op1) == 0 || strcmp(liste[i].res, liste[j].op2) == 0 ) 
			   {  
                   test = 1;
				   break;
               }
            }
			if(test == 0) {suppQuad(i); i--; changement = 1;}
        } 
		test =0;
    }
}
/***********************************************************************************************************/
/*******************************************************************************************************/
void ExpAlgbrique(){
	int i, j;
	
    for (i = 0; i < qc; i++) // go through all the quads
	{
		// See if one of the op is equal to 2
        if (strcmp(liste[i].opr, "*") == 0 && (strcmp(liste[i].op1, "2") == 0 || strcmp(liste[i].op2, "2") == 0) )
    	{   
	        changement = 1;
			// which one of them is equal to 2
            if  (strcmp(liste[i].op1, "2") == 0)
			{
				liste[i].op1 = liste[i].op2;
			}
			else 
			{
				liste[i].op2 = liste[i].op1;
			}
            liste[i].opr= "+";			
        } 
		// Test if the two op of an substruction are equal
		if (strcmp(liste[i].opr, "-") == 0 && (strcmp(liste[i].op1,liste[i].op2)  == 0 ))
    	{   changement = 1;
	        j=i+1;
			// premier cas si on utilise le temporaire dans une autre operation
			if(strcmp(liste[j].op2, "") == 0 )
			{
				liste[j].op1 = "0";
				liste[j].op2 = " ";
				liste[j].opr = "=";
				suppQuad(i); i--;
			}
			else  // si c est une affectation donc il sera inutil
			{
				liste[i].op1 = "0";
			    liste[i].op2 = " ";
			    liste[i].opr = "=";
			}
		} 
    }
}
/***************************************************************************************************/
void PropagationDeCopie() {
    int i, j, k;
	int nbQc=0; // calculer le nb des quads jusqu a trouver le meme res (changer la valeur du var)
	int trouve;
	int nbOcc=0; // res doit etre presant dasn au mois deux quad comme operand
    for (i = 0; i < qc-1; i++) 
	{    
		if (strcmp(liste[i].opr, "=") == 0 )
		{      
				nbQc=i+1; trouve =0;
				for (j = i+1; j < qc; j++)
				{
					if (strcmp(liste[i].res, liste[j].res) != 0 )
					{
					    nbQc++; trouve=1; //trouve est utilise pour la condition if 
						if (strcmp(liste[i].op1,liste[j].op2) == 0 || strcmp(liste[i].op1,liste[j].op1) == 0)
						{
							nbOcc++;
						}
					}
					else
					{
						break;
					}
				}
				if(trouve == 1 && nbOcc>1){
					for (j = i + 1; j < nbQc; j++) 
					{    
						if ( (strcmp(liste[i].op1,liste[j].op2) == 0 || strcmp(liste[i].op1,liste[j].op1) == 0) && strcmp(liste[i].op2,"") == 0 )
						{     changement = 1;
					        if (strcmp(liste[i].op1, liste[j].op1) == 0) 
							 {
								 strcpy(liste[j].op1, liste[i].res);
							 } 
							 else 
							 {
								  strcpy(liste[j].op2, liste[i].res);
							 }
						}
					}
				}
		}
       
    }
}
/*********************************************************************************************************/

/***********************************************************************************************************/
/***********************************************************************************************************/
void PropagationDeExp(){
	int i, j, k;
	int w;
    int nbOcc =0;
	
    for (i = 0; i < qc-2; i++) { // go through all the quads
        if (strcmp(liste[i].opr, "=") != 0 ) // si c'est une affectation, marquer la variable comme variable utilis�e
    	{   
			j=i+1;
            for (k = j + 1; k < qc-1; k++) 
			{    
				// We see if the res is used as op in the next quads
			   
			
               if (((strcmp(liste[j].res, liste[k].op1) == 0 || strcmp(liste[j].res, liste[k].op2) == 0)) && strcmp(liste[i].op2,"") != 0) 
			   {
				   
                   nbOcc++; // we count how many times we use that res
				   w=k; // save the quad that contains the res as op
				   
               }
				
			
            }
			// we see if we used the res once or never
			//if(nbOcc == 1 || nbOcc==0) 
			if(nbOcc == 1) 
			{     
		         changement = 1;
          		// we see if the res is on op1
				j = i+1;
			    if (strcmp(liste[j].res, liste[w].op1) == 0)
			    {   
			        liste[w].op1=liste[i].res; // in liste[i], op1 is a temporaire 
				}
				else
				{
					liste[w].op2=liste[i].res; // in liste[i], op1 is a temporaire 

				}
				//suppQuad(i); i--; 

			}
			nbOcc =0;
        } 
    }
}
/*******************************************************************************************************/

/*******************************************************************************************************/
void ExpRedondantes(){
	int i, j , k;
	int nbQc=0;
	int trouve;
	char suav [20];
    for (i = 0; i < qc-1; i++) // go through all the quads
	{
			nbQc=i+1; trouve =0;
				for (j = i+1; j < qc; j++)
				{
					if ((strcmp(liste[j].res, liste[i].op1) != 0) && (strcmp(liste[j].res, liste[i].op2) != 0) )
					{
					    nbQc++; trouve=1;
						
					}
					else
					{
						break;
					}
				}
			if(trouve == 1)
			{  
				for (j = i + 1; j < nbQc; j++)  // go through the next quads
				{   if(strcmp(liste[i].res, liste[j].op1) == 0){ strcpy(suav,liste[j].res);}
				   if ((strcmp(liste[i].opr, liste[j].opr) == 0) && (strcmp(liste[i].opr, "=") != 0)) // test if they have the same operation
					{     // tester si tout les operands sont egaux 
					   if ((strcmp(liste[i].op1, liste[j].op1) == 0 || strcmp(liste[i].op1, liste[j].op2) == 0) && (strcmp(liste[i].op2, liste[j].op1) == 0 || strcmp(liste[i].op2, liste[j].op2) == 0)  ) 
					   {   
						   changement = 1;
						   k = j+1;
						   //liste[k].op1=suav; 
						   strcpy(liste[k].op1,suav);
						   liste[k].op2=" ";
						   liste[k].opr = "=";
						   suppQuad(j);j--;
					   }
					}
				}	
            }			
    }
}
/***************************************************************************************************/
void optimisation(){
	   
	while (changement == 1)
	{
	    changement = 0;
	//    1     �limination d�expressions redondantes
				ExpRedondantes();
	//    1     Propagation d�expression
	            PropagationDeExp();
	//    3     propagation de copie   
				PropagationDeCopie();
    //    4 	Simplification alg�brique 
				ExpAlgbrique();    
	//    5 	Elimination du code inutile   
				CodeInutile();
				
	}
	
}

/***********************************Fonction d'affichage des quadruplets************************************************/
void afficher_qdr()
{
printf("*********************Affichage des Quadruplets***********************\n");

int i;

for(i=0;i<qc;i++)
		{

 printf("\n Quad N %d - ( %s  ,  %s  ,  %s  ,  %s )",i,liste[i].opr,liste[i].op1,liste[i].op2,liste[i].res);
 printf("\n---------------------------------------------------\n");

}
}
