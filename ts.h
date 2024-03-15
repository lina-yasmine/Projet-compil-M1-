#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void afficheErreur(char* d , int a);

typedef struct quad quad;
struct quad
{
	char* opr;
	char* op1;
	char* op2;
	char* res;
};

//d�claration d'une structure de donn�e pour la table de symbole

typedef struct entite
{
  char nom[20];
  char code[20];
  char nature[20]; //variable ou cst
  char type[20];
  int taille;
  char valeur[20];
  //C'est un pointeur vers une autre structure "entite". 
  //Ce membre est utilis� pour cr�er une liste cha�n�e d'entit�s, o� chaque entit� pointe vers l'entit� suivante.
  struct entite * svt;
} entite;


typedef struct tableH
{
   entite * tete;
   entite * queue;
} tableH;

//un tableau de structures "tableH"
tableH  TableHachage[673];



int hachage(char * chaine)
{
//unsigned int is used to ensure that the variables used in the hachage function are non-negative 
//and to avoid potential issues related to negative values during the calculations.
// the sign bit that is typically used to represent the sign of a number is repurposed to increase the magnitude of the positive range.
  unsigned int i=0, n=strlen(chaine), u=0, j=0, k=1, h=0;
  for(i=0; i<n; i++)
  {
	//Calcule la diff�rence entre la longueur de la cha�ne et la position actuelle de la boucle. 
	//Cette valeur est utilis�e pour calculer la puissance de 26 dans le calcul du hachage.  
    u=n-i-1;
	
    for(j=0; j<u; j++) k*=26;
	// code ascii de chaque lettre par la puissance
    h+=((int)chaine[i])*k;
	//revernir au debut pour la prochaine lettre
    k=1;
  }
  //pour rester dand la taille du tableau
  h=h%673;
  return h;
}




   //pour les idfs declarea
	typedef struct idfTemp
	{
		char nom[20];
		int position;
		char * nature;
		struct idfTemp *svt;
	}idfTemp;



	idfTemp * idfDeclT = NULL; //la tete de la liste chain� contenant que les idf d�clar�
	idfTemp * idfDeclQ = NULL; //la queue de la liste chain� des idf d�clar�
   // tableau des idf declaree est une listes chainee pas une table de hachage
	void inserIdfDecl(char *nom,char * nature){
		idfTemp * ptr = (idfTemp*)malloc(sizeof(idfTemp));
		strcpy(ptr->nom,nom);
		ptr->position = hachage(nom);
		ptr->nature=nature;
        //The svt (next) field of ptr is set to NULL.
		ptr->svt=NULL;
        //The code checks if the idfDeclT pointer (the head of the linked list) is NULL. If it is, the idfDeclT is updated to point to ptr.
		if(idfDeclT==NULL)
			idfDeclT=ptr;
		else  
			//If idfDeclT is not NULL , In that case, the svt field of the previous node (idfDeclQ) is updated to point to ptr.
			(idfDeclQ->svt)=ptr;
        //Finally, the idfDeclQ pointer (pointing to the last node) is updated to point to ptr.
		idfDeclQ =ptr;
	}




int routinIdfDeclar(char *nom)
{
	int trouve=0;
	idfTemp *ptr = idfDeclT;
	while((ptr!=NULL)&&(trouve==0))
	{
		if(strcmp(ptr->nom,nom)==0)
		{
			trouve=1;
		}
		else
		{
				ptr=ptr->svt;
		}
	}
	return trouve;
}

// retourne la psition de la chaine 
int rechercher(char *chaine)
{
  int existe=0;
  int position=0;

  position=hachage(chaine);
  entite *ptr = TableHachage[position].tete;
  while((ptr!=NULL)&&(existe==0))
  {
    if(strcmp(ptr->nom,chaine)==0)
    {
      existe=1;
    }
    else  
		//hachage n est pas injective donc deux chanes peuvent avoir le meme resultat(probleme de collison) donc on continue la recherche apres la position generalement elle n est pas loin
		ptr=ptr->svt;
    }
  if(existe==1 ) return position;
  else return -1 ;
}

void inserer(char * nom_entite,char * code_entite,int position)
{
  entite *ptr=NULL;

  if(rechercher(nom_entite)== -1)
  {

    ptr=(entite*)malloc(sizeof(entite));
    strcpy(ptr->nom,nom_entite);
    strcpy(ptr->code,code_entite);
    strcpy(ptr->type," ");
    strcpy(ptr->nature," ");
    ptr->taille=0;
   	strcpy(ptr->valeur," ");
    ptr->svt=NULL;

    if(TableHachage[position].tete==NULL) //c'est le premier element � ins�rer
    {  
	    TableHachage[position].tete=ptr;  
		TableHachage[position].queue=ptr;  
	}
    else 
	{
		// si il n est pas le premier le dernier de la liste doit pointe sur ce nouveau 
        (TableHachage[position].queue->svt)=ptr;
		
         TableHachage[position].queue=ptr;
    }
}

}
// inserer valeur est utilisee seulement pour les const
void insererVal(char * nom_entite,char * valeur, char typ[] )
{
	int hach = hachage(nom_entite);
	entite *ptr = TableHachage[hach].tete;
	int b = 1;

	while((b==1) && (ptr!=NULL))
	{
		if(strcmp(ptr->nom,nom_entite)==0)
		{
			// si je troube idf b=0 pour ne pas pointer dans le prochain et rentrer dans la boucle while
			b=0;
			strcpy(ptr->valeur,valeur);  // set the valeur field to the value of the constant
			strcpy(ptr->type,typ);  // set the type field to the type of the constant
		}
		ptr = ptr->svt;
	}
}


//cette fonction est utilisee pour  routineDebordementTab
int getTaille(char nom[])
{
 entite *ptr = TableHachage[hachage(nom)].tete;
 int b = 1;
 int taille;

 while((ptr!=NULL)&& (b==1))
 {
    if(strcmp(ptr->nom,nom)==0)
    {   
       // si je troube idf b=0 pour ne pas pointer dans le prochain et rentrer dans la boucle while
       b=0;
       taille = ptr->taille;
        return taille;
    }
    ptr = ptr->svt;
 }
 return 0;
}


void routineDebordementTab(char* idf, int val)
{
	int taille=getTaille(idf);
	if(val>taille) 
	{    /* printf("il ya un d�passement de capacit� du tableau: %s \n",idf); */
        char d[128] = "il ya un depassement de capacite du tableau : " ;
        strcat(d,idf);
        afficheErreur(d,9);
	}
}

void typeDeIdf(char* out, char* idf)
{
  int p=rechercher(idf);
    if(p != -1)
	{
       entite *ptr = TableHachage[p].tete;

        while((ptr!=NULL))
        {
            if(strcmp(ptr->nom,idf)==0)
            {
              strcpy(out, ptr->type);
              return ;
            }
          else ptr=ptr->svt;
        }
}
   else strcpy(out, " ");
}



int routineModifCst(char * idf){
  int b=0 ;
  int p=rechercher(idf);
  if(p != -1) 
  {
    entite *ptr = TableHachage[p].tete;
    while((ptr!=NULL)&&(b==0))
    {
        if(strcmp(ptr->nom,idf)==0)
        {   
	        b=1;
            if(strcmp(ptr->nature,"Constante")==0) 
			{
                char d[128] = " la valeur de " ;
                strcat(d,idf);
                strcat(d, " ne peut pas etre modifie c'est une constante ");
                afficheErreur(d,8);
		        return -1;
            /* printf(" \n la valeur de %s : ne peut pas etre modifi� c'est une constante ",idf); */
        }
	}
     else ptr=ptr->svt;
	}
  }
   else return 0; // updated

}
//void remplaceVirgule(char *ch){
 // int i=0,existe = 0;
  //while((ch[i] != '\0') && (existe== 0)) {
   //if(ch[i]==','){
    //existe=1;
    //ch[i]='.';
   //}
   //i++;
  //}
 //}

int doubleDeclaration (char entites[])
{
    int posEntite=rechercher(entites); //posEntite contiendras -1 si elle ne figure pas dans la liste chain� de la position
    entite * ptr= NULL ;
	if (posEntite!=-1)
	{
		ptr = TableHachage[posEntite].tete;
		while(ptr!=NULL)
		{
		    if(strcmp(ptr->nom,entites)==0)
		    {  
		        if (strcmp(ptr->type," ")==0) return 0;  // j'ai pas trouv� le type associ� � l'entit� dans le table de symbole et donc elle est pas encore d�clar�e
				else return 1; // le type de l'entit� existe dej� dans la TS et donc c'est une double d�claration
		    }
		    else ptr=ptr->svt;
		}
    }
	return -1;

}

// fonction qui change le type d'une etit� une fois il va �tre reconu dans la syntaxe

void insererType(char entites[], char typ[], char nature[],int taille)
{  
    entite * ptr=NULL ;
    int b=0 ;
    int posEntite=hachage(entites);
    ptr= TableHachage[posEntite].tete;

    while((ptr!=NULL) && (b==0))
    {
        if(strcmp(ptr->nom,entites)==0)
        { 
	        strcpy(ptr->type,typ);
			strcpy(ptr->nature,nature) ; 
			ptr->taille=taille ; 
			b=1 ;
        }
        else ptr=ptr->svt;
    }
}


void afficher()
{
  printf("  \n");
  printf("  \n");
  printf("\t ********************************** Table des symboles **************************************** /\n");
  printf("\t _________________________________________________________________________________________________ \n");
  printf("\t|      NomEntite      |   CodeEntite        |      NatureEntite     |     TypeEntite   | taille  | \n");
  printf("\t _________________________________________________________________________________________________\n");
    int i=0;
    for(i=0;i<673;i++)
	{
      entite * ptr=TableHachage[i].tete;
      while(ptr!=NULL)
        { printf("\t| %20s | %20s | %20s | %15s | %5d   |  \n",ptr->nom,ptr->code,ptr->nature,ptr->type,ptr->taille);

            ptr=ptr->svt;
		}

	}
		
}

void createAssembler(int qc, struct quad liste[2000]){
	
	FILE *filePointer;
	filePointer = fopen("assembly.asm", "w");
	char quad_op [20];
	int i;
	if(filePointer == NULL) {
      printf("Error creating file\n");
	}
	
	fprintf(filePointer,"TITLE prg.asm : \n");
	fprintf(filePointer,"Pile segment stack ; \n");
	fprintf(filePointer,"dw 100 dup(?) \n");
	fprintf(filePointer,"Pile ends \n");
	fprintf(filePointer,"DATA segment \n");
	
	
	for(i=0;i<673;i++)
	{
      entite * ptr=TableHachage[i].tete;
      while(ptr!=NULL)
        {
			if(strcmp(ptr->nature,"Variable")==0 || strcmp(ptr->nature,"variable Cords")==0){
				if(strcmp(ptr->type,"INTEGER")==0){fprintf(filePointer,"%s DD ?\n",ptr->nom);}
				if(strcmp(ptr->type,"FLOAT")==0){fprintf(filePointer,"%s DW ?\n",ptr->nom);}
			}else{
				if(strcmp(ptr->nature,"Tableau")==0){
					if(strcmp(ptr->type,"INTEGER")==0){fprintf(filePointer,"%s DD %d DUP ?\n",ptr->nom, ptr->taille);}
					if(strcmp(ptr->type,"FLOAT")==0){fprintf(filePointer,"%s DW %d DUP ?\n",ptr->nom, ptr->taille);}
				}
				if(strcmp(ptr->nature,"Constante")==0){
					fprintf(filePointer,"%s equ %s\n",ptr->nom,ptr->valeur);
				}
			}
			
            ptr=ptr->svt;
		}

	}
	

	fprintf(filePointer,"temp DD 2000 ?\n");
	fprintf(filePointer,"DATA ends\n");
	

	fprintf(filePointer,"CODE segment\n");
	fprintf(filePointer,"ASSUME CS:CODE, DS:DATA\n");
	fprintf(filePointer,"MAIN :\n");
	fprintf(filePointer,"MOV AX,DATA\n");
	fprintf(filePointer,"MOV DS,AX\n");
	for(i=0;i<qc;i++){
		fprintf(filePointer,"etiquette%d: \n",i);
		switch(liste[i].opr[0]) {
		  case '+':
				strcpy(quad_op,"ADD");
			break;
		  case '-':
				strcpy(quad_op,"SUB");
			break;
		  case '*':
				strcpy(quad_op,"MUL");
			break;
		  case '/':
				strcpy(quad_op,"DIV");
			break;
		  default:
			strcpy(quad_op,"NONE");
		}
		
		
		if(strcmp(quad_op,"ADD")==0 || strcmp(quad_op,"SUB")==0){
			fprintf(filePointer,"MOV AX, 0000\n");
			fprintf(filePointer,"MOV BX, 0000\n");
			if((liste[i].op1[0]=='T')&&(liste[i].op2[0]=='T')){
				fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].op2, liste[i].op2+1, strlen(liste[i].op2)))*2);
				fprintf(filePointer,"MOV BX,temp[SI]\n");
				fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].op1, liste[i].op1+1, strlen(liste[i].op1)))*2);
				fprintf(filePointer,"MOV AX,temp[SI]\n");
				fprintf(filePointer,"%s AX,BX\n",quad_op);
				fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].res, liste[i].res+1, strlen(liste[i].res)))*2);
			}
			else{
				if(liste[i].op1[0]=='T'){
					fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].op1, liste[i].op1+1, strlen(liste[i].op1)))*2);
					fprintf(filePointer,"MOV AX,temp[SI]\n");
					fprintf(filePointer,"MOV BX, %s\n",liste[i].op2);
					fprintf(filePointer,"%s AX,BX\n",quad_op);
					fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].res, liste[i].res+1, strlen(liste[i].res)))*2);
				}else{
					if(liste[i].op2[0]=='T'){
						fprintf(filePointer,"MOV AX, %s\n",liste[i].op1);
						fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].op2, liste[i].op2+1, strlen(liste[i].op2)))*2);
						fprintf(filePointer,"MOV BX,temp[SI]\n");
						fprintf(filePointer,"%s AX,BX\n",quad_op);
						fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].res, liste[i].res+1, strlen(liste[i].res)))*2);
					}
					else{
						fprintf(filePointer,"MOV AX, %s\n",liste[i].op1);
						fprintf(filePointer,"MOV BX, %s\n",liste[i].op2);
						fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].res, liste[i].res+1, strlen(liste[i].res)))*2);
						fprintf(filePointer,"%s AX, BX \n",quad_op);
					}
				}
			}
			fprintf(filePointer,"MOV temp[SI], AX\n");

	}
	
	if(strcmp(quad_op,"MUL")==0 || strcmp(quad_op,"DIV")==0){
		
			fprintf(filePointer,"MOV AX, 0000\n");
			fprintf(filePointer,"MOV BX, 0000\n");
		
			if((liste[i].op1[0]=='T')&&(liste[i].op2[0]=='T')){
				fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].op1, liste[i].op1+1, strlen(liste[i].op1)))*2);
				fprintf(filePointer,"MOV BX,temp[SI]\n");
				fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].op2, liste[i].op2+1, strlen(liste[i].op2)))*2);
				fprintf(filePointer,"MOV AX,temp[SI]\n");
				fprintf(filePointer,"%s BX\n",quad_op);
				fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].res, liste[i].res+1, strlen(liste[i].res)))*2);
			}
			else{
				if(liste[i].op1[0]=='T'){
					fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].op1, liste[i].op1+1, strlen(liste[i].op1)))*2);
					fprintf(filePointer,"MOV AX,temp[SI]\n");
					fprintf(filePointer,"MOV BX, %s\n",liste[i].op2);
					fprintf(filePointer,"%s BX\n",quad_op);
					fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].res, liste[i].res+1, strlen(liste[i].res)))*2);
				}else{
					if(liste[i].op2[0]=='T'){
						fprintf(filePointer,"MOV AX, %s\n",liste[i].op1);
						fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].op2, liste[i].op2+1, strlen(liste[i].op2)))*2);
						fprintf(filePointer,"MOV BX,temp[SI]\n");
						fprintf(filePointer,"%s BX\n",quad_op);
						fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].res, liste[i].res+1, strlen(liste[i].res)))*2);
					}
					else{
						fprintf(filePointer,"MOV BX, %s\n",liste[i].op1);
						fprintf(filePointer,"MOV AX, %s\n",liste[i].op2);
						fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].res, liste[i].res+1, strlen(liste[i].res)))*2);
						fprintf(filePointer,"%s BX \n",quad_op);
						
					}
				}
			}
			fprintf(filePointer,"MOV temp[SI], AX\n");

	}
		
	if(strcmp(liste[i].opr,"BR")==0){
		if(atoi(liste[i].op1) <= (qc-1)){
			fprintf(filePointer,"JMP etiquette%s\n",liste[i].op1);
		}else{
			fprintf(filePointer,"JMP FIN \n");
		}
	}
	if(strcmp(liste[i].opr,"BG")==0 || strcmp(liste[i].opr,"BGE")==0 || strcmp(liste[i].opr,"BL")==0 || strcmp(liste[i].opr,"BLE")==0 || strcmp(liste[i].opr,"BZ")==0 || strcmp(liste[i].opr,"BNZ")==0){
		
		fprintf(filePointer,"MOV SI, %d\n",atoi(memmove(liste[i].op2, liste[i].op2+1, strlen(liste[i].op2)))*2);
		fprintf(filePointer,"MOV CX,temp[SI]\n");
		fprintf(filePointer,"CMP CX, 0\n");
		
		if(strcmp(liste[i].opr,"BG")==0){
			if(atoi(liste[i].op1) <= (qc-1)){
				fprintf(filePointer,"JG etiquette%s\n",liste[i].op1);
			}else{
				fprintf(filePointer,"JG FIN\n");
			}			
		}
	if(strcmp(liste[i].opr,"BGE")==0){
		if(atoi(liste[i].op1) <= (qc-1)){
			fprintf(filePointer,"JGE etiquette%s\n",liste[i].op1);
		}else{
			fprintf(filePointer,"JGE FIN \n");
		}
	}
	if(strcmp(liste[i].opr,"BL")==0){
		if(atoi(liste[i].op1) <= (qc-1)){
			fprintf(filePointer,"JL etiquette%s\n",liste[i].op1);
		}else{
			fprintf(filePointer,"JL FIN \n");
		}

	}
	if(strcmp(liste[i].opr,"BLE")==0){
		if(atoi(liste[i].op1) <= (qc-1)){
			fprintf(filePointer,"JLE etiquette%s\n",liste[i].op1);
		}else{
			fprintf(filePointer,"JLE FIN \n");
		}
	}
	if(strcmp(liste[i].opr,"BZ")==0){
		if(atoi(liste[i].op1) <= (qc-1)){
			fprintf(filePointer,"JE etiquette%s\n",liste[i].op1);
		}else{
			fprintf(filePointer,"JE FIN \n");
		}
	}
	if(strcmp(liste[i].opr,"BNZ")==0){
		if(atoi(liste[i].op1) <= (qc-1)){
			fprintf(filePointer,"JNE etiquette%s\n",liste[i].op1);
		}else{
			fprintf(filePointer,"JNE FIN \n");
		}
	}
	}
	if(strcmp(liste[i].opr,"=")==0){
		fprintf(filePointer,"MOV BX, 0000\n");
		if(liste[i].res[0]=='T'){
			if(liste[i].op1[0]=='T'){
				fprintf(filePointer,"MOV SI, %d \n",atoi(memmove(liste[i].op1, liste[i].op1+1, strlen(liste[i].op1)))*2);
				fprintf(filePointer,"MOV BX, temp[SI]\n");
			}
			else{
				fprintf(filePointer,"MOV BX, %s \n",liste[i].op1);
			}
			fprintf(filePointer,"MOV SI, %d \n",atoi(memmove(liste[i].res, liste[i].res+1, strlen(liste[i].res)))*2);
			fprintf(filePointer,"MOV temp[SI], BX\n");			
		}else{
			if(liste[i].op1[0]=='T'){
				fprintf(filePointer,"MOV SI, %d \n",atoi(memmove(liste[i].op1, liste[i].op1+1, strlen(liste[i].op1)))*2);
				fprintf(filePointer,"MOV BX, temp[SI]\n");
				fprintf(filePointer,"MOV %s, BX\n",liste[i].res);
			}
			else{
				fprintf(filePointer,"MOV BX, %s \n",liste[i].op1);
				fprintf(filePointer,"MOV %s, BX\n",liste[i].res);
			}
		}
	}
}
	fprintf(filePointer,"FIN:\n");
	fprintf(filePointer,"MOV AH,4CH\n");
	fprintf(filePointer,"INT 21h\n");
	fprintf(filePointer,"CODE ends\n");
	fprintf(filePointer,"END MAIN\n");
	fclose(filePointer);
}

void afficherDecl()
{
    printf("\n \n ");
  printf("\t ****************** list idf deja declarees *****************/\n");
   printf("\t __________________________________\n");
   printf("\t|  NomEntite  |  Position | Nature\n");
   printf("\t __________________________________\n");

      idfTemp * ptr=idfDeclT;

	  while(ptr!=NULL)
        {
			printf("\t| %10s | %10d |%12s |\n",ptr->nom,ptr->position,ptr->nature);

            ptr=ptr->svt;
		}
}




