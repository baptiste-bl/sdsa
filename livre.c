#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("CODE :", (ptrL->code ), MAX_CODE);
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

afficherChaine("CODE :", (ptrL->code ));
printf("\n");

afficherChaine("EMPRUNTEUR :", (ptrL->emprunteur ));
printf("\n");
}

