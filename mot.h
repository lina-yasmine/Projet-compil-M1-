#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


element tab[1000];
elt tabs[40], tabm[40];

char chaine [] = "";


void initialisationMC()
{
    int i;
    for (i=0; i<100; i++){
        tab[i].state= 0;
        strcpy(tab[i].type, chaine);
    }
    for (i=0; i<40; i++){
        tabs[i].state= 0;
        tabm[i].state= 0;
    }
}


void insererMC (char entite[], char code[], char type[], float val, int i, int y)
{
    switch (y)
    {
        case 1:
            tabm[i].state=1;
            strcpy(tabm[i].name, entite);
            strcpy(tabm[i].type, code);
            break;

        case 2:
            tabs[i].state= 1;
            strcpy(tabs[i].name, entite);
            strcpy(tabs[i].type, code);
            break;
    }
}


void rechercherMC (char entite[], char code[], char type[], float val,int y)
{
    int i;
    switch(y)
    {
        case 1:
            for (i=0;((i<40)&&(tabm[i].state==1)) && (strcmp(entite,tabm[i].name)!=0);i++);
            if(i<40 && (strcmp(entite,tabm[i].name)!=0))
            insererMC(entite,code,type,val,i,1);
            break;
        case 2:
            for (i=0;((i<40)&&(tabs[i].state==1)) && (strcmp(entite,tabs[i].name)!=0);i++);
            if(i<40 && (strcmp(entite,tabs[i].name)!=0))
            insererMC(entite,code,type,val,i,2);
            break;
    }
}



void afficherMS(){
    int i=0;
    
    printf("\n     /***************Table des mots cles*************/\n");
    printf("        _____________________________________\n");
    printf("\t|                     Nom        \n");
    printf("        _____________________________________\n");

    for(i=0; i<40; i++)
        if(tabm[i].state==1)
        {
            printf("\t|   %30s \n",tabm[i].name);
        }


    printf("\n      /***************Table des separateurs*************/\n");
    printf("         _____________________________________________\n\n");
    printf("\t|           NomEntite |          CodeEntite | \n");
    printf("         _____________________________________________ \n");

    for(i=0; i<40; i++)
    if(tabs[i].state==1)
        {
            printf("\t|%20s |%20s | \n",tabs[i].name,tabs[i].type );
        }
}







