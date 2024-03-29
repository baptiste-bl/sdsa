#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H
#define Nbsec 604800 //nb de sec en 7 jours

#include "livre.h"

#define CAPACITE_BIBLIO 20 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int  afficherBibliotheque(const T_Bibliotheque  *ptrB);
int rechercherBiblio(const T_Bibliotheque *ptrB);
int rechercherAuteur(const T_Bibliotheque *ptrB);
int suppression(T_Bibliotheque *ptrB);
void sauvegarde(T_Bibliotheque *ptrB);
void chargement(T_Bibliotheque *ptrB);
int emprunter(T_Bibliotheque *ptrB);
int restituer(T_Bibliotheque *ptrB);
void trier_titre(T_Bibliotheque *ptrB);
void trier_auteur(T_Bibliotheque *ptrB);
void trier_annee(T_Bibliotheque *ptrB); //tri à bulles
void lireDateSysteme(T_Emp *E);
void livreDispo(T_Bibliotheque *ptrB);
void list_retard(T_Bibliotheque *ptrB);
#endif