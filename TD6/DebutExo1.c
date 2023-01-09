#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define CREER_TABLEAU 1
#define AFFICHER_TABLEAU 2
#define SUPPRIMER_TABLEAU 3
#define SAUVER_TABLEAU_TEXTE 4
#define CHARGER_TABLEAU_TEXTE 5
#define SAUVER_TABLEAU_BINAIRE 6
#define CHARGER_TABLEAU_BINAIRE 7
#define SORTIR 9

#define TAILLE_TAB 50
#define TAILLE_MAX 256

/**************************************************************************/
/**                          MenuPrincipal()                             **/
/**************************************************************************/
/**************************************************************************/
int MenuPrincipal()
{
	int iMenu;

	system ("cls");
	printf("\t***********************************\n");
	printf("\t**  Gestion d'un tableau de mots **\n");
	printf("\t***********************************\n");
	printf("\t** 1) Creer un tableau           **\n");
	printf("\t** 2) Afficher un tableau        **\n");
	printf("\t** 3) Supprimer un tableau       **\n");
	printf("\t** 4) Sauver en fichier texte    **\n");
	printf("\t** 5) Charger en fichier texte   **\n");
	printf("\t** 6) Sauver en fichier binaire  **\n");
	printf("\t** 7) Charger en fichier bianire **\n");
	printf("\t** 9) Quitter                    **\n");
	printf("\t***********************************\n");
	printf("\tVotre choix : ");
	scanf ("%d%*c", &iMenu);

	return (iMenu);
}

/**************************************************************************/
/**                          saisirTableau()                             **/
/**************************************************************************/
/**************************************************************************/

int saisirTableau(char * tab[], int * pNb)
{
	int iRang, iBool;
	char sBuffer[TAILLE_MAX];
	char cContinuer;
	
	iRang = 0;

	system ("cls");
	printf("\tSAISIE DU TABLEAU :\n");
	printf("\t*******************\n");
	do
	{
		/* Saisie du mot dans un buffer temporaire */
		printf("\tEntrez un mot :");
		scanf("%s%*c", sBuffer);

		/* Allocation memoire de la zone pointee par une case du tableau */
		tab[iRang] = malloc ((strlen(sBuffer)+1)*sizeof(char));
		if (tab[iRang]==NULL)
		{
			perror ("Allocation memoire dans SaisirTableau");
			return(-1);
		}

		/* Recopie du buffer dans une zone pointee par une case du tableau */
		strcpy(tab[iRang], sBuffer);

		iRang++;
		(*pNb)++;

		printf("Voulez vous entrer un autre mot (o/n)? \n");
		scanf("%c%*c", &cContinuer);

		if ((cContinuer == 'n')||(cContinuer == 'N'))
			iBool = 0;
		else
			iBool = 1;

	} while (iBool);
}

/**************************************************************************/
/**                          saisirTableau()                             **/
/**************************************************************************/
/**************************************************************************/

void afficherTableau(char * tab[], int iNb)
{
	int i;

	for (i=0; i < iNb; i++)
	{
		printf("\t%s\n", tab[i]);
	}
}

/**************************************************************************/
/**                          supprimerTableau()                          **/
/**************************************************************************/
/**************************************************************************/

void supprimerTableau(char * tab[], int * pNb)
{
	int i;

	for (i=0; i < *pNb; i++)
	{
		free(tab[i]);
	}
	*pNb=0;
}

/**************************************************************************/
/**                  sauverTableauFichierTexte()                         **/
/**************************************************************************/
/**************************************************************************/

int sauverTableauFichierTexte(char * tab[], int iNb)
{
    FILE * fichier;
    int i;

    fichier = fopen("tableau.txt", "w");
    if (fichier == NULL)
    {
        perror("Erreur d'ouverture du fichier");
        return(-1);
    }

    for (i=0; i < iNb; i++)
    {
        fprintf(fichier, "%s\n", tab[i]);
    }

    fclose(fichier);
    return(0);
}
/**************************************************************************/
/**                  chargerTableauFichierTexte()                        **/
/**************************************************************************/
/**************************************************************************/
int chargerTableauFichierTexte_fscaf(char * tab[], int * pNb){
    FILE * fichier;
    int i;
    char sBuffer[TAILLE_MAX];

    fichier = fopen("tableau.txt", "r");
    if (fichier == NULL)
    {
        perror("Erreur d'ouverture du fichier");
        return(-1);
    }

    i=0;
    while(fscanf(fichier, "%s", sBuffer) != EOF)
    {
        tab[i] = malloc ((strlen(sBuffer)+1)*sizeof(char));
        if (tab[i]==NULL)
        {
            perror ("Allocation memoire dans chargerTableauFichierTexte");
            return(-1);
        }
        strcpy(tab[i], sBuffer);
        i++;
    }
    *pNb=i;
    fclose(fichier);
    return(0);
}


int chargerTableauFichierTexte(char * tab[], int * pNb){
    FILE * fichier;
    char sBuffer[TAILLE_MAX];
    int i;

    fichier = fopen("tableau.txt", "r");
    if (fichier == NULL)
    {
        perror("Erreur d'ouverture du fichier");
        return(-1);
    }

    i = 0;
    while (fgets(sBuffer, TAILLE_MAX, fichier) != NULL)
    {
        tab[i] = malloc ((strlen(sBuffer)+1)*sizeof(char));
        if (tab[i]==NULL)
        {
            perror ("Allocation memoire dans ChargerTableauFichierTexte");
            return(-1);
        }
        sBuffer[strlen(sBuffer)-1] = '\0';
        strcpy(tab[i], sBuffer);
        i++;
    }
    *pNb = i;
    fclose(fichier);
    return(0);
}
/**************************************************************************/
/**                  sauverTableauFichierBinaire()                       **/
/**************************************************************************/
/**************************************************************************/

int sauverTableauFichierBinaire(char * tab[], int iNb){
    FILE * fichier;
    int i, isize;

    fichier = fopen("tableau.bin", "wb");
    if (fichier == NULL)
    {
        perror("Erreur d'ouverture du fichier");
        return(-1);
    }

    for (i=0; i < iNb; i++)
    {
		isize = strlen(tab[i]);
        fwrite(&isize, sizeof(int), 1, fichier);
		fwrite(tab[i], (isize+1)*sizeof(char),1, fichier);
        
    }

    fclose(fichier);
    return(0);
}
/**************************************************************************/
/**                  chargerTableauFichierBinaire()                      **/
/**************************************************************************/
/**************************************************************************/

int chargerTableauFichierBinaire(char * tab[], int *pNb){
    FILE * fichier;
    char sBuffer[TAILLE_MAX];
	int size;
    int i;

    fichier = fopen("tableau.bin", "rb");
    if (fichier == NULL)
    {
        perror("Erreur d'ouverture du fichier");
        return(-1);
    }

    i = *pNb;

    while (fread(&size, sizeof(int), 1, fichier) != 0)
    {
        
		if( fread(sBuffer, (size+1)*sizeof(char), 1, fichier)!=0){
			tab[i] = malloc ((strlen(sBuffer)+1)*sizeof(char));
			if (tab[i]==NULL){
				perror ("Allocation memoire dans ChargerTableauFichierBinaire");
				return(-1);
			}
			strcpy(tab[i], sBuffer);
			i++;
		}	
	}
	*pNb = i;
	fclose(fichier);
	return(0);
}


/**************************************************************************/
/**                          initTableau()                               **/
/**************************************************************************/
/**************************************************************************/

void initTableau(char * tab[], int *pNb)
{
	int i;

	*pNb = 0;
	for (i=0; i < TAILLE_TAB; i++)
	{
		tab[i]=NULL;
	}
}

/**************************************************************************/
/**                              Main()                                  **/
/**************************************************************************/
/**************************************************************************/

int main (int argc, char * argv[])
{
	/* Declaration */
	int iMenu = 0;
	int iReturn = 0;
	char * tab[TAILLE_TAB];
	int iNb;
	
	initTableau(tab,&iNb);

	/* Choix du type d'acces au programme */
	while (iMenu != SORTIR)
	{
		iMenu = MenuPrincipal();
		switch(iMenu)
		{
			case CREER_TABLEAU :
				iReturn = saisirTableau(tab, &iNb);
				if (iReturn <0)
				{
					fprintf(stderr, "ERREUR - Saisie du tableau");
					exit(EXIT_FAILURE);
				}
				printf("APPUYER SUR ENTREE POUR CONTINUER\n");
				scanf("%*c");
				break;
			case AFFICHER_TABLEAU :
				printf("AFFICHAGE TABLEAU\n");
				printf("*****************\n");
				afficherTableau(tab,iNb);
				printf("APPUYER SUR ENTREE POUR CONTINUER\n");
				scanf("%*c");
				break;
			case SUPPRIMER_TABLEAU :
				printf("SUPPRESSION TABLEAU\n");
				printf("*******************\n");
				supprimerTableau(tab, &iNb);
				printf("APPUYER SUR ENTREE POUR CONTINUER\n");
				scanf("%*c");
				break;
			case SAUVER_TABLEAU_TEXTE :
				printf("SAUVER LE TABLEAU DANS UN FICHIER TEXTE\n");
				printf("***************************************\n");
				sauverTableauFichierTexte(tab, iNb);
				printf("APPUYER SUR ENTREE POUR CONTINUER\n");
				scanf("%*c");
				break;
			case CHARGER_TABLEAU_TEXTE :
				printf("CHARGER LE TABLEAU DEPUIS UN FICHIER TEXTE\n");
				printf("******************************************\n");
				chargerTableauFichierTexte_fscaf(tab, &iNb);
				printf("APPUYER SUR ENTREE POUR CONTINUER\n");
				scanf("%*c");
				break;
			case SAUVER_TABLEAU_BINAIRE :
				printf("SAUVER LE TABLEAU DANS UN FICHIER BINAIRE\n");
				printf("*****************************************\n");
				sauverTableauFichierBinaire(tab, iNb);
				printf("APPUYER SUR ENTREE POUR CONTINUER\n");
				scanf("%*c");
				break;
			case CHARGER_TABLEAU_BINAIRE :
				printf("CHARGER LE TABLEAU DEPUIS UN FICHIER BINAIRE\n");
				printf("********************************************\n");
				chargerTableauFichierBinaire(tab, &iNb);
				printf("APPUYER SUR ENTREE POUR CONTINUER\n");
				scanf("%*c");
				break;
			case SORTIR :
				/* Sortie du Programme */
				exit(EXIT_SUCCESS);
				break;
		}
	}
}