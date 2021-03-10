#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("CODE :", (ptrL->code ), MAX_CODE);
printf("ANNEE: "); //rajout
scanf("%d",&ptrL->annee);

}

void afficherLivre(T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf("\n");

printf("ANNEE : %d",ptrL->annee);
printf("\n"); //rajout

afficherChaine("CODE :", (ptrL->code ));
printf("\n");


if(strcmp(ptrL->emprunteur.nomemp,"") != 0)
{

char jour[13],mois[13];


printf("\n emprunteur du livre : %s",ptrL->emprunteur.nomemp);

printf("\n  emprunt realise le : ");
switch(ptrL->emprunteur.lejour)
{
case 0 :  strcpy(jour,"lundi");break;
case 1 :  strcpy(jour,"mardi");break;
case 2 :  strcpy(jour,"mercredi");break;
case 3 :  strcpy(jour,"jeudi");break;
case 4 :  strcpy(jour,"vendredi");break;
case 5 :  strcpy(jour,"samedi");break;
case 6 :  strcpy(jour,"dimanche");break;

default : strcpy(jour,"jour inconnu");break;
}
printf("%s ",jour);

printf("%d ",ptrL->emprunteur.ledate);


switch(ptrL->emprunteur.lemois)
{
case 0 :  strcpy(mois,"janvier");break;
case 1 :  strcpy(mois,"fevrier");break;
case 2 :  strcpy(mois,"mars");break;
case 3 :  strcpy(mois,"avril");break;
case 4 :  strcpy(mois,"mai");break;
case 5 :  strcpy(mois,"juin");break;
case 6 :  strcpy(mois,"juillet");break;
case 7 :  strcpy(mois,"aout");break;
case 8 :  strcpy(mois,"septembre");break;
case 9 :  strcpy(mois,"octobre");break;
case 10:  strcpy(mois,"novembre");break;
case 11:  strcpy(mois,"decembre");break;

default : strcpy(jour,"mois inconnu");break;
}
printf("%s ",mois);

printf("%d ",ptrL->emprunteur.lannee);
}


}

