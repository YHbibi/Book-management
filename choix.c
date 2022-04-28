#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestion.cpp"


void choix()
{
	noeud_v *tete_v;
	noeud_h *tete_h;
	element elem;
	bib b;
	int j, nbLivTot, choix, nbl;
	char categD[20];
	
	//initialisation du bibliothèque
	tete_v = NULL;

 	choix=1;
 	while(choix)
 	{
 		puts("\n\n\n=================================================================");
	 	puts("=====================GESTION DE BIBLIOTHEQUE=====================");
	 	puts("=================================================================\n");
	 	puts("1-Ajouter une categorie");
	   	puts("2-Ajouter un livre dans une categorie");
	 	puts("3-Afficher une categorie donnee");
	 	puts("4-Afficher les livres d'une categorie");
	 	puts("5-Afficher les categories dans la bibliotheque");
	 	puts("6-Afficher l'ensemble de la bibliotheque");
	 	puts("7-Calculer le nombre de livres de la bibliotheque");
	 	puts("8-Supprimer une categorie donnee");
	 	puts("0-Sortir de l'application");
		puts("_________________________________________________________________");
		
		
		do
		{
			printf("\n\nDonner votre choix :");
			scanf("%d",&choix);
		}while(choix<0 || choix>8);
		
		switch (choix)
		{
			case 1 :{
				printf("\n\nDonner le nom d'une categorie dont vous pouvez ajouter : ");
				scanf("%s",categD);
				printf("Donner le nombre de livres dans cette categorie : ");
				scanf("%d",&nbl);
				
				if( existe(tete_v,categD) ) // si la categorie est déja existe ,donc on ajoute seulement les nouveaux livres a cette derniere
				{
					printf("\n->Cette categorie est deja definie : ");
					for(j=0; j<nbl; j++) // liste horizontale
					{
					    printf("\n\t\t\t\t\t**)Pour le %d %s Livre%c :\n" ,j+1, (j==0) ? "er" : "eme", (j==0) ? ' ' : 's');
						AjouterLivreCategorie1(tete_v, categD); 
					}
				}
				else // on créé une categorie 
				{	
					//creerBib(&b); //cette procedure est remplacée par les deux lignes suivantes
					strcpy(b.categ , categD); // affecter le nom du categorie donnée au structure bib  
					b.nb_livre = nbl;
					printf("\n\n\t\t\t\t*)Pour la categorie %s : \n", b.categ);
					ajouterCategorie(&tete_v, b);
					for(j=0; j<b.nb_livre; j++) // liste horizontale
					{
					    printf("\n\t\t\t\t\t**)Pour le %d %s Livre%c :\n" ,j+1, (j==0) ? "er" : "eme", (j==0) ? ' ' : 's');
						AjouterLivreCategorie(tete_v, b.categ);
						
					}
				}
				
				break;
			}
			
			case 2 :{
				printf("\n\nDonner une categorie dont vous pouvez ajouter un livre : ");
				scanf("%s",categD);				
				AjouterLivreCategorie1(tete_v, categD);
				
				break;
			}
			
			case 3 :{	
				printf("\n\nDonner une categorie a chercher : ");
				scanf("%s",categD);				
				afficherCategorieDonnee(tete_v, categD);

				break;
			}
			
			case 4 :{
				printf("\n\nDonner une categorie pour afficher leur livres : ");
				scanf("%s",categD);	
				afficherLivre(tete_v, categD );
				
				break;
			}
			
			case 5 :{
				puts("\n\n=>Les categories dans cette bibliotheque : \n");
				affiche_seulement_categorie(tete_v);
				
				break;
			} 
			
			case 6 :{
			 	puts("\n\nL'ensemble du bibliotheque :\n");
				afficheBib(tete_v);
				
				break;
			}
			
			case 7 :{
				nbLivTot=nb_tot_livres(tete_v);
				printf("\n\n=>Dans cette bibliotheque il y'a %d livre%c \n ", nbLivTot, (nbLivTot<2) ? ' ' : 's');
			
				break;
			}
			
			case 8 :{
				printf("\nDonner une categorie a supprimer : ");
				scanf("%s",categD);
				supprimer_categ(&tete_v, categD);
				break;
			}
			
			case 0 :{
				puts("\n\nMerci pour votre visite,A BIENTOT!");
				break;
			}		
			
		}
				
	 }

}
