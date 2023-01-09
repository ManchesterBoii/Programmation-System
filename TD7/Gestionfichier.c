#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "GestionFichier.h"

extern int iGLOBALCodeErreur;

/**************************************************************************/
/**                          saisirTableau()                             **/
/**************************************************************************/
/**************************************************************************/

int saisirTableau(Etudiant tab[], int * pNb)
{
	int iRang, iBool, i;
	char sBuffer[TAILLE_MAX];

	char cContinuer;
	
	iRang = 0;

	system ("clear");
	printf("\tSAISIE DU TABLEAU :\n");
	printf("\t*******************\n");
	do
	{
		/* Saisie du mot dans un buffer temporaire */
		printf("\tEntrez un code etudiant :");
		scanf("%d%*c", &(tab[iRang].iCode));
		printf("\tEntrez un Nom:");
		scanf("%s%*c", sBuffer);

		/* Allocation memoire de la zone pointee par une case du tableau */
		tab[iRang].sNom = malloc ((strlen(sBuffer)+1)*sizeof(char));
		if (tab[iRang].sNom==NULL)
		{
			perror ("Allocation memoire dans SaisirTableau");
			return(-1);
		}
		printf("\tEntrez un Prenom:");
		scanf("%s%*c", sBuffer);
		/* Allocation memoire de la zone pointee par une case du tableau */
		tab[iRang].sNom = malloc ((strlen(sBuffer)+1)*sizeof(char));
		if (tab[iRang].sPrenom==NULL)
		{
			perror ("Allocation memoire dans SaisirTableau");
			return(-1);
		}

		/* Recopie du buffer dans une zone pointee par une case du tableau */
		strcpy(tab[iRang].sNom, sBuffer);
		for (i=0; i<TAILLE_NOTE; i++)
		{
			printf("\tEntrez une note:");
			scanf("%d%*c", &(tab[iRang].tabNotes[i]));
		
		}

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
/**                          afficherTableau()                             **/
/**************************************************************************/
/**************************************************************************/

void afficherTableau(Etudiant * tab, int iNb)
{
	int i,j;

	for (i=0; i < iNb; i++)
	{
		printf("\t%d\t%s\t%s", tab[i].iCode, tab[i].sNom, tab[i].sPrenom);
		for (j=0; j < TAILLE_NOTE; j++)
		{
			printf("\t%d", tab[i].tabNotes[j]);
		}
		printf("\n");
	}
}

/**************************************************************************/
/**                          supprimerTableau()                          **/
/**************************************************************************/
/**************************************************************************/

void supprimerTableau(Etudiant * tab, int * pNb)
{
	int i;

	for (i=0; i < *pNb; i++)
	{
		free(tab[i].sNom);
		free(tab[i].sPrenom);
	}
	*pNb=0;
}

/**************************************************************************/
/**                  sauverTableauFichierTexte()                         **/
/**************************************************************************/
/**************************************************************************/

int sauverTableauFichierTexte(Etudiant *tab, int iNb)
{
	char sNom[TAILLE_MAX];
	FILE * fd;
	int iRang, iReturn,i ;

	/* Saisie du nom du fichier*/
	printf ("Entrez le nom du fichier dans lequel vous voulez sauvegarder le tableau?\n");
	scanf ("%s%*c", sNom);

	/* Ouverture du fichier en ecriture/ecrasement */
	fd = fopen(sNom, "wt");
	if (fd == NULL)
	{
		perror ("Sauvegarde Fichier Texte - OUVERTURE");
		scanf("%*c");
		return(-1);
	}

	for (iRang=0; iRang < iNb; iRang++)
	{
		/* ecriture du mot */
		fprintf(fd, "%d ", tab[iRang].iCode);
		fprintf(fd, "%s ", tab[iRang].sNom);
		fprintf(fd, "%s ", tab[iRang].sPrenom);
		for (i=0; i<TAILLE_NOTE; i++)
		{
			fprintf(fd, "%d ", tab[iRang].tabNotes[i]);
		}
		/* Retour à la ligne dans le fichier */
		fprintf(fd, "%s", "\n");
	}

	fclose(fd);
	return (0);
}
/**************************************************************************/
/** int chargerTableauFichierTexte(char * sNomFic, Etudiant * tab, int * pNb)*/
/**************************************************************************/
/* Cette fonction charge dans une structure memoire le fichier            */
/* d etudiants. Elle prend en parametres :                                */
/*     - sNomFic : nom du fichier contenant les infos                     */
/*     - tab : tableau de structure dans lequel sont chargees les infos   */
/*     - pNb : variable recuperant le nombre d etudiants                  */
/**************************************************************************/
/* Valeur retournee : 0 si tt se passe bien ou -1 en cas d erreur         */                                           
/**************************************************************************/

int chargerTableauFichierTexte(char * sNomFic, Etudiant * tab, int * pNb)
{
	char sBuffer[TAILLE_MAX];
	FILE * fd;
	int iRang=0,i;

	/* Verification nom de fichier non null */
	if (sNomFic==NULL){
		printf ("Nom de fichier incorrect");
		return (-1);
	}

	/* Ouverture du fichier en lecture */
	fd = fopen(sNomFic, "r");
	if (fd == NULL) {
		if (errno == ENOENT){
			/* le fichier n existe pas alors on le crée */
			fd = fopen(sNomFic, "a");
			if (fd == NULL) {
				/* autre cas d erreur */
				perror ("Chargement Fichier Texte - OUVERTURE");
				return(-1);
			}
			fclose(fd);
			return 0;
		}
		else {
			/* autre cas d erreur */
			perror ("Chargement Fichier Texte - OUVERTURE");
			return(-1);
		}
	}


	do
	{
		fscanf(fd, "%d ", &(tab[iRang].iCode)); /*lecture du code etudiants */
		/* cette lecture est placee avant le !feof car il faut au moins une lecture*/
		/* pour positionner le feof a vrai */
		if (!feof(fd))
		{			
			fscanf(fd, "%s ", sBuffer);
			tab[iRang].sNom = malloc ((strlen(sBuffer)+1)*sizeof(char));
			if (tab[iRang].sNom == NULL)
			{
				perror ("Chargement Fichier Texte - ECRITURE");
				fclose(fd);
				return(-1);
			}
			strcpy(tab[iRang].sNom,sBuffer);
			fscanf(fd, "%s ", sBuffer);
			tab[iRang].sPrenom = malloc ((strlen(sBuffer)+1)*sizeof(char));
			if (tab[iRang].sPrenom == NULL)
			{
				perror ("Chargement Fichier Texte - ECRITURE");
				fclose(fd);
				return(-1);
			}
			strcpy(tab[iRang].sPrenom,sBuffer);

			for (i=0; i< TAILLE_NOTE; i++)
			{
				fscanf(fd, "%d ", &(tab[iRang].tabNotes[i]));
			}
			iRang++;
			(*pNb)++;
		}
	}while (!feof(fd));

	/* Fermeture du fichier */
	fclose(fd);
	return (0);
}




/**************************************************************************/
/**                          initTableau()                               **/
/**************************************************************************/
/* Initialise le tableau manipulant le ficher                             */
/* Par convention :                                                       */
/*        - le code est initialise a -1                                   */
/*        - le nom et le prenom le sont a NULL (var allouees dynamiquement*/
/*        - chaque note l est a 0                                         */
/**************************************************************************/

void initTableau(Etudiant * tab, int *pNb)
{
	int i,j;

	*pNb = 0;
	for (i=0; i < TAILLE_TAB; i++)
	{
		tab[i].iCode=-1;
		tab[i].sNom=NULL;
		tab[i].sPrenom=NULL;
		for (j=0;j<TAILLE_NOTE ; j++)
		{
			tab[i].tabNotes[j]=-1;
		}
		
	}
}
/***********************************************************************************/
/* void afficheLigneTableau (Etudiant * etud, int iNote)                           */
/***********************************************************************************/
/* Fct affichant une ligne du tableau d etudiants                                  */
/* Le parametre est un element de type Etudiant                                    */
/* si iNote est egal a PARAM_AFFICH_NOTES, alors les notes sont aussi affichees    */
/***********************************************************************************/
void afficheLigneTableau (Etudiant * etud, int iNote){
	int iCpt;
	printf ("\t%d \t%s \t%s", etud->iCode, etud->sNom, etud->sPrenom);
	if (iNote==PARAM_AFFICH_NOTES){
		for (iCpt=0; iCpt < TAILLE_NOTE; iCpt++){
			printf ("\t%d", etud->tabNotes[iCpt]);	
		}
	}
	printf ("\n");
}
