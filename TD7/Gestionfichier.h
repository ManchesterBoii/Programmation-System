#ifndef GESTION_FICHIER_H
#define GESTION_FICHIER_H

/**********************************************************************/
/* Le fichier est suppose contenir une liste d'etudiants et leur note */
/* Le fichier est textuel et les champs sont organisés comme :        */
/*     1er champ : Nom                                                */
/*     2ieme champ : Prenom                                           */
/*     1ieme champ : Note                                             */
/* La premiere ligne du fichier contient les intitules des matieres   */
/**********************************************************************/

/**********************************************************************/
/* Constantes nommées                                                 */
/**********************************************************************/
/**********************************************************************/
/* Constantes de tailles                                              */
/**********************************************************************/
/* Par convention, le nombre max d etudiants est de 10                */
/* Par convention, la taille des noms et prenoms est au maximum de 10 */
/*      caracteres                                                    */
/* Par convention, le nombre max de matieres est de 3                 */
/**********************************************************************/
#define TAILLE_TAB 50
#define TAILLE_MAX 256
#define TAILLE_NOTE 3

#define PARAM_AFFICH_NOTES 1
#define PARAM_AFFICH_PAS_NOTES 0
/**********************************************************************/
/* La structure permettant de manipuler le fichier est la suivante    */
/* iCode est un entier contenant le code etudiant                     */
/* sNom est un pointeur sur caractere                                 */
/* sPrenom est un pointeur sur caractere                              */
/* tabNote est un tableau contenant les notes par matiere             */
/**********************************************************************/

typedef struct{
	int iCode;
	char * sNom;
	char * sPrenom;
	int tabNotes[TAILLE_NOTE];
} Etudiant;

void afficheLigneTableau (Etudiant *, int);

#endif
