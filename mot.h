#ifndef MOT_H
#define MOT_H

typedef struct
{
    int state;
    char name[100];
    char code[20];
    char type[20];
    char val[100];
} element;

typedef struct
{
    int state;
    char name[100];
    char type[20];
} elt;



void initialisationMC();
void insererMC(char entite[], char code[], char type[], float val, int i, int y);
void rechercherMC(char entite[], char code[], char type[], float val, int y);
void afficherMS();

#endif