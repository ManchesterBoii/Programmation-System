#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestionNotes.h"    /* inclusion du fichier header du programme */
#include "Gestionfichier.h" /* inclusion du fichier de manipulation des fichiers */

extern int iGLOBALCodeErreur;

/***********************************************************************************/
/* int moyenne (int iNbElt, float * tab, float * fMoyenne)                         */
/***********************************************************************************/
/* Cette fonction effectue le calcul de la moyenne d'une serie de notes flottantes */
/* comprise entre 0 et 20.                                                         */
/* iNbelt est le nombre d'elements du tableau                                      */
/* tab est le tableau de notes entieres                                            */
/* fMoyenne est un pointeur sur une variable extérieure passée en paramètre et     */
/*         permettant de recuperer la valeur de la moyenne                         */
/***********************************************************************************/
/* Valeurs retournees :                                                            */
/*       0 si le calcul s est correctement deroule                                 */
/***********************************************************************************/
int moyenne (int iNbElt, int * tab, float * fMoyenne){
	int iCpt=0;	     /* variable de boucle */
	int iSomme = 0;  /* variable intermediaire de calcul de la somme des notes */
	
	/* Parcours du tableau pour le calcul de la moyenne */
	/* sortie sur erreur si un element du tableau est negatif */
	for (iCpt=0; iCpt< iNbElt; iCpt++) {
			iSomme += tab[iCpt];
	}
	
	/* calcul de la moyenne */
	*fMoyenne = (float) (iSomme / iNbElt);
	return 0;
}

/**************************************************************************/
/** void afficheListeNotes(Etudiant *classe, int iNbEtudiants)           **/
/**************************************************************************/
/* Cette fonction affiche la liste des notes                              */
/* Parametres                                                             */
/*   Classe : pointeur sur tableau d etudiants                            */
/*   iNbetudiants : nombre d etudiants dans le tableau                    */
/**************************************************************************/
void afficheListeNotes(Etudiant *classe, int iNbEtudiants){
	printf("\n*********************************************************\n");
	printf("**                  Gestion des notes                  **\n");
	printf("*********************************************************\n");
	afficherTableau(classe, iNbEtudiants);
	printf("*********************************************************\n");	
}

/**************************************************************************/
/** int MenuPrincipal()                                                  **/
/**************************************************************************/
/* Cette fonction affiche le menu principal de l application              */
/* Parametres                                                             */
/*   Classe : pointeur sur tableau d etudiants                            */
/*   iNbetudiants : nombre d etudiants dans le tableau                    */
/**************************************************************************/
int MenuPrincipal(Etudiant * classe, int iNbEtudiants)
{
	int iMenu;

	system ("clear");
	
	afficheListeNotes(classe, iNbEtudiants);
	
	printf("\t***********************************************\n");
	printf("\t**  Gestion des notes par matieres           **\n");
	printf("\t***********************************************\n");
	printf("\t** 1) Afficher la liste des notes            **\n");
	printf("\t** 2) Ajouter 1 note a 1 etudiant            **\n");
	printf("\t** 3) Ajouter toutes les notes d une matiere **\n");
	printf("\t** 4) Calculer la moyenne d une matire       **\n");
	printf("\t** 5) Calculer la moyenne d un eleve         **\n");	
	printf("\t** 7) Sauver les modifications               **\n");	
	printf("\t** 9) Quitter                                **\n");
	printf("\t***********************************************\n");
	printf("\tVotre choix : ");
	scanf ("%d", &iMenu);

	return (iMenu);
}

/**************************************************************************/
/** void afficheModeEmploi()                                             **/
/**************************************************************************/
/* Cette fonction affiche le menu principal de l application              */
/**************************************************************************/
void afficheModeEmploi(){
	system ("clear");
	printf ("\n--- %s ---\n\n", "Le programme doit être appele avec un nom de fichier valide");	
}

/**************************************************************************/
/** void TerminaisonProgramme(Etudiant * classe, int * iNbEtudiants)     **/
/**************************************************************************/
/* Cette fonction libere la memoire allouee dynamiquement                 */
/* Parametres                                                             */
/* Classe : pointeur sur tableau d etudiants                              */
/* iNbetudiants : nombre d etudiants dans le tableau                      */
/**************************************************************************/

void TerminaisonProgramme(Etudiant * classe, int * iNbEtudiants){
	supprimerTableau(classe, iNbEtudiants);
}


/***********************************************************************************/
/* int RechercheEtudiant (Etudiant * classe, int iNbEtudiants, int * iRang)        */
/***********************************************************************************/
/* Cette fonction recherche un etudiant dont l utilisateur donne le code           */
/* classe est le tableau d etudiant                                                */
/* iNbEtudiant est le nombre d'elements du tableau                                 */
/* iRang est un pointeur vers le rang du tableau                                   */
/* Valeur retournees                                                               */
/* fMoyenne est un pointeur sur une variable extérieure passée en paramètre et     */
/*         permettant de recuperer la valeur de la moyenne                         */
/***********************************************************************************/
/* Valeurs retournees :                                                            */
/*       0 si le calcul s est correctement deroule                                 */
/***********************************************************************************/
int RechercheEtudiant (Etudiant * classe, int iNbEtudiants, int * iRang){
	int iCpt=0;	           /* variable de boucle */
	int iCode=0;           /* var recuperant le code de l etudiant recherche */
	
	printf ("Entrez le Code d'un etudiant : ");
	scanf ("%d%*c", &iCode);
	
	for (iCpt=0; iCpt < iNbEtudiants; iCpt++){
		if ((classe[iCpt]).iCode == iCode){
			/* code trouve */
			*iRang=iCpt;
			return (0);
		}
	}
	return (-1);
}

/***********************************************************************************/
/* AjouteNoteEtudiant (Etudiant * classe, int iNbEtudiants)                        */
/***********************************************************************************/
/* Cette fonction ajoute une ou plusieurs notes a un etudiant                      */
/* L etudiant est recherche par son code                                           */
/* classe est le tableau d etudiant                                                */
/* iNbEtudiant est le nombre d'elements du tableau                                 */
/***********************************************************************************/
void AjouteNoteEtudiant (Etudiant * classe, int iNbEtudiants){
	int iRang=0;
	int iMat=0;
	int iNote=0;
	char cRep;
	do{
		/* Affichage du tablea */
		afficherTableau(classe,iNbEtudiants);
		/* recherche de l etudiant grace a son code */
		if (RechercheEtudiant (classe, iNbEtudiants, &iRang) == 0){
			/* Etudiant trouve, on affiche ses infos */
			afficheLigneTableau(&classe[iRang], PARAM_AFFICH_NOTES);
			do{
				/* Demande de la matiere dans laquelle la note est ajoutee */
				printf("Entrez le numero de la matière que vous voulez saisir (de 0 à %d) : ", TAILLE_NOTE-1);
				scanf("%d%*c", &iMat);
				/* verification de l existance de la matiere */
				if ((iMat >=0)&&(iMat <TAILLE_NOTE)){
					/* matiere existe */
					do{
						/* saisie de la note a ajouter/modifier - la note doit etre comprise entre 0 et 20 */
						printf ("Entrez la note (entre 0 et 20) :");
						scanf ("%d%*c", &iNote);
					} while ((iNote<0)&&(iNote>20));
					/* Modification/ajout de la note */
					classe[iRang].tabNotes[iMat]=iNote;
				}
				/* evaluation sortie directe ou ajout une autre note */
				printf ("Voulez-vous entrer une autre note sur ce même étudiant (o/n)? :");
				scanf ("%c%*c", &cRep);			
			}while ((cRep != 'n')&&(cRep != 'N'));
		}else{
			/* Etudiant non trouve - affichage msg d erreur */
			printf ("Erreur etudiant non trouvé");
		}
		/* evaluation de la sortie directe ou ajout d autres notes */
		printf ("Voulez-vous rechercher un autre étudiant (o/n)? :");
		scanf ("%c%*c", &cRep);
	} while ((cRep != 'n')&&(cRep != 'N'));
}

/***********************************************************************************/
/* void AjouteNoteMatiere (Etudiant * classe, int iNbEtudiants)                    */
/***********************************************************************************/
/* Cette fonction ajoute une serie de notes dans une matiere donnee                */
/* La matière est recherchee par son numero                                        */
/* classe est le tableau d etudiant                                                */
/* iNbEtudiant est le nombre d'elements du tableau                                 */
/***********************************************************************************/
void AjouteNoteMatiere (Etudiant * classe, int iNbEtudiants){
	int iRang=0;
	int iMat=0;
	int iNote=0;
	int iCpt=0;
	char cRep;

	do{
		/* Demande de la matiere dans laquelle la note est ajoutee */
		printf("Entrez le numero de la matière que vous voulez saisir (de 0 à %d) : ", TAILLE_NOTE-1);
		scanf("%d%*c", &iMat);
		/* verification de l existance de la matiere */
		if ((iMat >=0)&&(iMat <TAILLE_NOTE)){
			/* matiere existe */
			/* On parcourt tous les etudiants */
			for (iCpt=0;iCpt<iNbEtudiants; iCpt++){
				printf ("Entrez la note de l etudiant : ");
				afficheLigneTableau(&classe[iCpt], PARAM_AFFICH_PAS_NOTES);
				do{
					/* saisie de la note a ajouter/modifier - la note doit etre comprise entre 0 et 20 */
					printf ("Entrez la note (entre 0 et 20) :");
					scanf ("%d%*c", &iNote);
				} while ( (iNote<0) || (iNote>20) );
				/* Modification/ajout de la note */
				classe[iCpt].tabNotes[iMat]=iNote;
			}
		}
		else{
			printf ("ERREUR - la mantière n'existe pas");
		}
		/* evaluation sortie directe ou ajout une autre note */
		printf ("Voulez-vous entrer recommencer (o/n)? :");
		scanf ("%c%*c", &cRep);			
	}while ((cRep != 'n')&&(cRep != 'N'));

}

/***********************************************************************************/
/* void CopierColonneDansTableau(Etudiant * classe, int iNbEtudiants, int *tab, int iCol)*/
/***********************************************************************************/
/* Cette fonction construit un tableau a 1 dimension a partir de la structure de   */
/* données contenant le fichier etudiant                                           */
/* classe est le tableau d etudiant                                                */
/* iNbEtudiant est le nombre d'elements du tableau                                 */
/* tab est le tableau cible resultant                                              */
/* icol est la colonne de notes qu on cherche a recuperer                          */
/***********************************************************************************/
void CopierColonneDansTableau(Etudiant * classe, int iNbEtudiants, int *tab, int iCol){
	int iCpt=0;
	
	for(iCpt=0; iCpt<iNbEtudiants; iCpt++){
		tab[iCpt]=classe[iCpt].tabNotes[iCol];
	}
}

/***********************************************************************************/
/* void CalculeMoyenneParMatiere (Etudiant * classe, int iNbEtudiants)             */
/***********************************************************************************/
/* Cette fonction calcule la moyenne des notes d une matiere donnee.               */
/* classe est le tableau d etudiant                                                */
/* iNbEtudiant est le nombre d'elements du tableau                                 */
/***********************************************************************************/
void CalculeMoyenneParMatiere (Etudiant * classe, int iNbEtudiants){
	int iRetour=0;
	int iRang=0;
	int iMat=0;
	int iNote=0;
	int iCpt=0;
	char cRep;
	int * tabNotes=NULL;
	float fMoyenne=0.0;

	do{
		/* Demande de la matiere dans laquelle la note est ajoutee */
		printf("Entrez le numero de la matière que vous voulez saisir (de 0 à %d) : ", TAILLE_NOTE-1);
		scanf("%d%*c", &iMat);
		/* verification de l existance de la matiere */
		if ((iMat >=0)&&(iMat <TAILLE_NOTE)){
			/* matiere existe */
			/* on alloue un tableau pour recuperer les notes */
			tabNotes = malloc (sizeof(int)*iNbEtudiants);
			if (tabNotes == NULL){
				perror ("Allocation memoire sur creation tableau");
			}else{
				CopierColonneDansTableau(classe, iNbEtudiants, tabNotes, iMat);
				if ((iRetour = moyenne (iNbEtudiants, tabNotes, &fMoyenne))!=0){
					printf("Erreur\n");
				}
				printf ("La moyenne de la matière %d est : %.2f\n", iMat, fMoyenne);
				/* liberation de la memoire */
				free(tabNotes);
				tabNotes = NULL;
			}
		}
		else{
			printf ("ERREUR - la mantière n'existe pas");
		}
		/* evaluation sortie directe ou ajout une autre note */
		printf ("Voulez-vous entrer recommencer (o/n)? :");
		scanf ("%c%*c", &cRep);			
	}while ((cRep != 'n')&&(cRep != 'N'));

}

/***********************************************************************************/
/* int main (int argc, char ** argv)                                               */
/***********************************************************************************/
/* Programme principal.                                                            */ 
/* Retourne 0 si le programme se termine sans erreur. -1 sinon                     */
/* Il y a 1 argument possible : le nom de fichier                                  */    
/***********************************************************************************/
int main (int argc, char * argv[]){

	/* Declaration */
	int iMenu = 0;				/* recupere le choix du menu */
	int iRetour = 0;			/* Var de retour standard des fct */
	Etudiant classe[TAILLE_TAB];	/* tableau contenant les infos du fichier */
	int iNbEtudiants = 0;
	
	char * sNomFic = NULL;	

/***********************************************************************************/
/* Phase d initialisation                                                          */
/***********************************************************************************/
	initTableau(classe,&iNbEtudiants);
	

/***********************************************************************************/
/* Phase de fonctionnement nominal                                                 */
/***********************************************************************************/

	sNomFic = malloc ((strlen(argv[1])+1)*sizeof(char));
	if (sNomFic == NULL)
	{
		perror ("Allocation memoire sur recuperation nom Fichier");
		return(EXIT_FAILURE);
	}
	strcpy(sNomFic, argv[1]);
	
	/* Fonctionnement nominal du programme une fois le fichier charge */
	/*----------------------------------------------------------------*/
	system("clear");


	/* Choix du type d'acces au programme */
	while (iMenu != SORTIR)
	{
		iMenu = MenuPrincipal(classe, iNbEtudiants);
		switch(iMenu)
		{
			case AFFICHER_TABLEAU :
				printf("AFFICHAGE LISTE DES NOTES\n");
				printf("*************************\n");
				afficherTableau(classe,iNbEtudiants);
				printf("APPUYER SUR ENTREE POUR CONTINUER\n");
				scanf("%*c");
				break;
			case AJOUTER_NOTE_ETUDIANT :
				printf("AJOUTER NOTE ETUDIANT\n");
				printf("*********************\n");
				AjouteNoteEtudiant(classe,iNbEtudiants);
				printf("APPUYER SUR ENTREE POUR CONTINUER\n");
				scanf("%*c");
				break;
			case AJOUTER_NOTE_MATIERE :
				printf("AJOUTER NOTE MATIERE\n");
				printf("********************\n");
 				AjouteNoteMatiere (classe,iNbEtudiants);
				printf("APPUYER SUR ENTREE POUR CONTINUER\n");
				scanf("%*c");
				break;
			case CALCULER_MOYENNE_MATIERE :
				printf("CALCUL MOYENNE PAR MATIERE\n");
				printf("**************************\n");
				CalculeMoyenneParMatiere (classe, iNbEtudiants);
				printf("APPUYER SUR ENTREE POUR CONTINUER\n");
				scanf("%*c");
				break;
			case CALCULER_MOYENNE_ELEVE :
				printf("CALCUL MOYENNE PAR ELEVE\n");
				printf("*****************\n");
				printf("XXX TODO XXX\n");
				printf("APPUYER SUR ENTREE POUR CONTINUER\n");
				scanf("%*c");
				break;
			case SAUVER_TABLEAU_TEXTE :
				printf("SAUVER LE TABLEAU DANS UN FICHIER TEXTE\n");
				printf("***************************************\n");
				iRetour = sauverTableauFichierTexte(classe, iNbEtudiants);
				if (iRetour <0)
					fprintf(stderr, "ERREUR - Sauvegarde du tableau en fichier texte\n");
				else
					fprintf(stdout, "Sauvegarde terminee\n");
				printf("APPUYER SUR ENTREE POUR CONTINUER\n");
				scanf("%*c");
				break;
			case SORTIR :
				/* Sortie du Programme */
				return(EXIT_SUCCESS);
				break;
		}
	}


	/* Termniaison du programme */
	TerminaisonProgramme(classe, &iNbEtudiants);
	return (EXIT_SUCCESS);
}

