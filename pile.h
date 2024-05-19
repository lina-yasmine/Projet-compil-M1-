

typedef struct pile
{
	char nom[20];
	struct pile *svt;
} pile;

pile *p = NULL;

void empiler(char nom[])
{
	pile *ptr = (pile *)malloc(sizeof(pile));
	strcpy(ptr->nom, nom);
	pile *sommet = p;
	p = ptr;
	ptr->svt = sommet;
	sommet = NULL;
	ptr = NULL;
}

char *depiler()
{
	char *ch;
	if (p != NULL)
	{
		ch = p->nom;
		p = p->svt;
		return ch;
	}
	else
	{
		return NULL;
	}
}
