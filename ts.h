#pragma once
#include<stdio.h>
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

   //pour les idfs declarea
typedef struct idfTemp
	{
		char nom[20];
		int position;
		char * nature;
		struct idfTemp *svt;
	}idfTemp;


static idfTemp * idfDeclT = NULL; //la tete de la liste chain� contenant que les idf d�clar�
static idfTemp * idfDeclQ = NULL; //la queue de la liste chain� des idf d�clar�

int hachage(char * chaine);
void inserIdfDecl(char *nom,char * nature);
int routinIdfDeclar(char *nom);
int rechercher(char *chaine);
void inserer(char * nom_entite,char * code_entite,int position);
void insererVal(char * nom_entite,char * valeur, char typ[] );
int getTaille(char nom[]);
void routineDebordementTab(char* idf, int val);
void typeDeIdf(char* out, char* idf);
int routineModifCst(char * idf);
int doubleDeclaration (char entites[]);
void insererType(char entites[], char typ[], char nature[],int taille);
void afficher();
void createAssembler(int qc, struct quad liste[2000]);
void afficherDecl();
double operationMath(double a, const char* op, double b);
int compare(double left, const char* cmp, double right);



