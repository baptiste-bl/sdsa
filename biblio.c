# include "biblio.h"

void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
	ptrB->nbLivres++;
	return 1;
	}
	
	
return 0;
	
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
			afficherLivre( &(ptrB->etagere[i])  );
			
			}


		
		return 1;
		}
}
int rechercherBiblio(const T_Bibliotheque *ptrB){
	char titre[MAX_TITRE];
	int i=0;
	int test = 0;
	int ret;
	lireChaine("TITRE :",titre, MAX_TITRE );
	for(i=0;i<ptrB->nbLivres;i++)
	{
		if(strcmp((*ptrB).etagere[i].titre,titre)==0)
		{
			ret = i;
			test++;
		}
	}
	if(test == 1){
		afficherLivre(&(ptrB->etagere[ret]));
	}
	else{
		printf("il y a plusieurs livres!!!!!");
	}
	return test;

}
int rechercherAuteur(const T_Bibliotheque *ptrB){
	char auteur[K_MaxAut];
	int i=0;
	int test = 0;
	lireChaine("AUTEUR :",auteur, K_MaxAut );
	for(i=0;i<ptrB->nbLivres;i++)
	{
		if(strcmp((*ptrB).etagere[i].auteur,auteur)==0)
		{
			printf("Found auteur, livre n° %d:\n",i+1);
			afficherLivre(&(ptrB->etagere[i]));
			test = 1;
		}
	}

	return test;

}
int suppression(T_Bibliotheque *ptrB){
	T_livre livre;
	saisirLivre(&livre);
	int i=0;
	int test = 0;
	while(strcmp((*ptrB).etagere[i].titre,livre.titre)!=0 && strcmp((*ptrB).etagere[i].auteur,livre.auteur)!=0 && i<ptrB->nbLivres)
	{
		i++;
	}
	if(strcmp((*ptrB).etagere[i].titre,livre.titre)==0 && strcmp((*ptrB).etagere[i].auteur,livre.auteur)==0)
	{
	
	for(i;i<ptrB->nbLivres;i++)
	{
		ptrB->etagere[i] = ptrB->etagere[i+1];
		//strcpy(ptrB->etagere[i].auteur,ptrB->etagere[i+1].auteur);
		//strcpy(ptrB->etagere[i].titre,ptrB->etagere[i+1].titre);
	}
	(ptrB->nbLivres)--;
	test = 1;
	}
	return test;

}