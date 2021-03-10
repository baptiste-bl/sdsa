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
    char titre[MAX_TITRE]="";
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
    //lireChaine("TITRE :",livre.auteur, K_MaxAut );
    int i=0;
    int test = 0;

    for(i=0;i<ptrB->nbLivres;i++)
    {
        if(strcmp((livre.auteur),ptrB->etagere[i].auteur)==0 && strcmp(livre.titre,ptrB->etagere[i].titre)==0 )
        {
            if(livre.annee == ptrB->etagere[i].annee && strcmp((livre.code),ptrB->etagere[i].code)==0 ) //rajout 
            {

            test=1;
            }
        }
        if(test == 1)
        {
            ptrB->etagere[i] = ptrB->etagere[i+1];
        }
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

    char nom_emp[50]="";
    char auteur[50]="";
    char titre[50]="";
    //T_livre livre;
    int test = 0;
    //saisirLivre(&livre);
    lireChaine("AUTEUR :",auteur, 50 );
    lireChaine("TITRE :",titre, 50 );
    lireChaine("EMPRUNTEUR : ",nom_emp,50);
    for(int i=0;i<ptrB->nbLivres;i++)
    {
        if((strcmp(ptrB->etagere[i].titre,titre)==0)&&(strcmp(ptrB->etagere[i].auteur,auteur)==0))
        {
            strcpy(ptrB->etagere[i].emprunteur.nomemp,nom_emp);
            lireDateSysteme(&ptrB->etagere[i].emprunteur);
            test = 1;//success
        }
    }
    return test;

}
int restituer(T_Bibliotheque *ptrB){
    T_livre livre;
    char nom[50]="";
    int test = 0;
    lireChaine("EMPRUNTEUR :",nom, 50 );
    saisirLivre(&livre);
    for(int i=0;i<ptrB->nbLivres;i++)
    {
        if(strcmp(nom,ptrB->etagere[i].emprunteur.nomemp)==0 && strcmp(livre.titre,ptrB->etagere[i].titre) ==0 && strcmp(livre.auteur,ptrB->etagere[i].auteur)==0)
        {
            strcpy(ptrB->etagere[i].emprunteur.nomemp,"");
            test = 1;
        }
    }
    return test;

}

void trier_titre(T_Bibliotheque *ptrB) //tri à bulles
{
    int compteur = 1;
    int i; // initialisation
    char temoin = 1;
    T_livre echangeur;
    while(temoin == 1)
    {
        temoin = 0;
        for(i=0;i < ptrB->nbLivres - compteur;i++)
        {
            if(strcmp(ptrB->etagere[i].titre,ptrB->etagere[i+1].titre) > 0)
            {
                temoin = 1;
                echangeur = ptrB->etagere[i];
                ptrB->etagere[i] = ptrB->etagere[i+1];
                ptrB->etagere[i+1] = echangeur;
            }
        }
        compteur++;
    }
}
void trier_auteur(T_Bibliotheque *ptrB) //tri à bulles
{
    int compteur = 1;
    int i; // initialisation
    char temoin = 1;
    T_livre echangeur;
    while(temoin == 1)
    {
        temoin = 0;
        for(i=0;i < ptrB->nbLivres - compteur;i++)
        {
            if(strcmp(ptrB->etagere[i].auteur,ptrB->etagere[i+1].auteur) > 0)
            {
                temoin = 1;
                echangeur = ptrB->etagere[i];
                ptrB->etagere[i] = ptrB->etagere[i+1];
                ptrB->etagere[i+1] = echangeur;
            }
        }
        compteur++;
    }
}
void trier_annee(T_Bibliotheque *ptrB) //tri à bulles
{
    int compteur = 1;
    int i; // initialisation
    char temoin = 1;
    T_livre echangeur;
    while(temoin == 1)
    {
        temoin = 0;
        for(i=0;i < ptrB->nbLivres - compteur;i++)
        {
            if(ptrB->etagere[i].annee < ptrB->etagere[i+1].annee)
            {
                temoin = 1;
                echangeur = ptrB->etagere[i];
                ptrB->etagere[i] = ptrB->etagere[i+1];
                ptrB->etagere[i+1] = echangeur;
            }
        }
        compteur++;
    }
}


void lireDateSysteme(T_Emp *E)
{
char j[9],m[10],h[9],mer[11],vir[2];
int d,a;
system("date > ladate"	);
FILE * fic=NULL;  // pointeur de fichier
fic=fopen("ladate","r"); //fileOpen en mode 'r'EAD

//ici , si fic vaut NULL, alors le fopen a indiqué
//que le fichier ladate n'est pas accessible
if (fic!=NULL)
	{
	while(!feof(fic))	
		{
		fscanf(fic,"%s %d %s %d %s %s %s",j,&d,m,&a,vir,h,mer);		
		if (!feof(fic)) 
			printf("\n-->LU : %s- %d- %s- %d- %s- %s",j,d,m,a,h,mer);		

		}
	fclose(fic);
	
if (strcmp(j,"lundi")==0) E->lejour=lu;
if (strcmp(j,"mardi")==0) E->lejour=ma;
if (strcmp(j,"mercredi")==0) E->lejour=me;
if (strcmp(j,"jeudi")==0) E->lejour=je;
if (strcmp(j,"vendredi")==0) E->lejour=ve;
if (strcmp(j,"samedi")==0) E->lejour=sa;
if (strcmp(j,"dimanche")==0) E->lejour=di;

E->ledate=d;

if (strcmp(m,"janvier")==0) E->lemois=janv;
if (strcmp(m,"fevrier")==0) E->lemois=fevr;
if (strcmp(m,"mars")==0) E->lemois=mars;
if (strcmp(m,"avril")==0) E->lemois=avri;
if (strcmp(m,"mai")==0) E->lemois=mai;
if (strcmp(m,"juin")==0) E->lemois=juin;
if (strcmp(m,"juillet")==0) E->lemois=juil;
if (strcmp(m,"aout")==0) E->lemois=aout;
if (strcmp(m,"septembre")==0) E->lemois=sept;
if (strcmp(m,"octobre")==0) E->lemois=octo;
if (strcmp(m,"novembre")==0) E->lemois=nove;
if (strcmp(m,"decembre")==0) E->lemois=dece;


E->lannee=a;
	}
	else
	{
		printf("n souci avec la date systeme !!");
		
		//on range une date irréelle 
		E->lejour=di;
		E->ledate=99;
		E->lemois=dece;
		E->lannee=-999;


	}

}
