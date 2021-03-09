#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);

printf("ANNEE: "); //rajout
scanf("%d",&ptrL->annee);

}

void afficherLivre(const T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf("\n");

printf("ANNEE : %d",ptrL->annee);
printf("\n"); //rajout

afficherChaine("EMPRUNTEUR :", (ptrL->emprunteur ));
printf("\n");
}

