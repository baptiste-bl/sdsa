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
    else if(test>1){
        printf("il y a plusieurs livres!!!!!,il y a %d livres",test);
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
    //lireChaine("AUTEUR :",livre.auteur, K_MaxAut );
    int i=0;
    int test = 0;

    for(i=0;i<ptrB->nbLivres;i++)
    {
        if(strcmp((livre.auteur),ptrB->etagere[i].auteur)==0 && strcmp(livre.titre,ptrB->etagere[i].titre)==0)
        {
            test=1;
        }
        if(test == 1)
        {
            ptrB->etagere[i] = ptrB->etagere[i+1];
        }
        //strcpy(ptrB->etagere[i].auteur,ptrB->etagere[i+1].auteur);
        //strcpy(ptrB->etagere[i].titre,ptrB->etagere[i+1].titre);
    }
    if (test==1){
        (ptrB->nbLivres)--;
    }
    return test;

}
void sauvegarde(T_Bibliotheque *ptrB)
{
    FILE *fic=NULL; //le type FILE
    int i;
    fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
    if (fic!=NULL)
    {
        for(i=0;i<ptrB->nbLivres;i++)
        {
//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
            fwrite(  &(ptrB->etagere[i])        ,sizeof(T_livre),1,fic);

        }
        fclose(fic);
        puts("SAUVEGARDE REUSSIE ..............");



    }
    else puts("ECHEC DE SAUVEGARDE  !!!!!  ");




}



void chargement(T_Bibliotheque *ptrB)
{
    FILE *fic=NULL; //le type FILE
    int i=0;
    fic=fopen("baseLivres","r"); // r = le mode read
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
    if (fic!=NULL)
    {
        do
        {

            fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
            i++;
        }
        while(!feof(fic));
        fclose(fic);
        ptrB->nbLivres=i-1;
        puts("CHARGEMENT  REUSSI ..............");
    }
    else puts("ECHEC DE CHARGEMENT  !!!!!  ");

}
int emprunter(T_Bibliotheque *ptrB){

    char nom_emp[50];
    T_livre livre;
    int test = 0;
    saisirLivre(&livre);
    lireChaine("EMPRUNTEUR : ",nom_emp,50);
    for(int i=0;i<ptrB->nbLivres;i++)
    {
        if((strcmp(ptrB->etagere[i].titre,livre.titre)==0)&&(strcmp(ptrB->etagere[i].auteur,livre.auteur)==0))
        {
            strcpy(ptrB->etagere[i].emprunteur,nom_emp);
            test = 1;
        }
    }
    return test;

}
int restituer(T_Bibliotheque *ptrB){
    T_livre livre;
    char nom[50];
    int test = 0;
    lireChaine("EMPRUNTEUR :",nom, 50 );
    saisirLivre(&livre);
    for(int i=0;i<ptrB->nbLivres;i++)
    {
        if(strcmp(nom,ptrB->etagere[i].emprunteur)==0 && strcmp(livre.titre,ptrB->etagere[i].titre) && strcmp(livre.auteur,ptrB->etagere[i].auteur))
        {
            strcpy(ptrB->etagere[i].emprunteur,NULL);
            test = 1;
            break;
        }
    }
    return test;

}