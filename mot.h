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

static char chaine [] = "";


void initialisationMC();
void insererMC (char entite[], char code[], char type[], float val, int i, int y);
void rechercherMC (char entite[], char code[], char type[], float val,int y);
void afficherMS();






