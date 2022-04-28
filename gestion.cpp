#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.cpp"


//1-1
void creerBib(bib *b)
{
	
	printf("\t\t\tNom du categorie : ");
	scanf("%s", (*b).categ);
	fflush(stdin);
	printf("\t\t\tNombre du livre : ");
	scanf("%d", &(*b).nb_livre );		

}

//1-2
void ajouterCategorie(struct noeud_v **tete, struct bib nh) // nh:noeud horizontale
{
	noeud_v *c, *nv;
	
	nv=(noeud_v*)malloc(sizeof(noeud_v));
	(*nv).val =nh ;
	nv->tete_list_hori = NULL; // le pointeur vers la liste horizontale
	
	if( *tete==NULL )
	{	// inserer debut 
		(*nv).suiv=*tete;
		*tete=nv;	
	}
	else
	{ 
	   c=*tete;
	 	while( (*c).suiv  ) 
			{
				c=(*c).suiv;
			}
		// inserer fin
		(*c).suiv = nv;	
		(*nv).suiv = NULL;
	}
}
 
//1-3
void creerElement(element *elem)
{
  	
	printf("\t\t\t\t\tNom du l'auteur : ");
	scanf("%s", (*elem).auteur);
	fflush(stdin);
	printf("\t\t\t\t\tTitre du livre : ");
	scanf("%s", (*elem).titre_livre );		
	fflush(stdin);

}

//1-4
void insererLivre(struct noeud_h **tete, struct element ne) // ne: noeud element
{
	noeud_h *c,*nv;
	//	allocation
	nv=(noeud_h*)malloc(sizeof(noeud_h));
	(*nv).val =ne ;
	
	
	if( *tete==NULL )
	{	// inserer debut 
		(*nv).suiv=*tete;
		*tete=nv;	
	}
	else
	{ 
	   c=*tete;
	 	while( (*c).suiv )
			{
				c=(*c).suiv;
			}
		// inserer fin
		(*c).suiv = nv;	
		(*nv).suiv = NULL;
	}

}

////1-4
void AjouterLivreCategorie(noeud_v *tete_v, char *categD)
{
	struct element elem;
	
		
		while( tete_v!=NULL && strcmp( (*tete_v).val.categ , categD )!=0 ) // on parcourt la liste verticale jusqu' on trouve la categorie souhaitée (celle qui était dernièrement créée)
		{
		    tete_v=(*tete_v).suiv;			
		}
						
		if ( tete_v!=NULL)
		{
			creerElement(&elem);
		   	insererLivre(&(tete_v->tete_list_hori), elem);
			//(*tete_v).val.nb_livre+=1; // incrementer le nbre de livres dans cette categorie

		}

 
}

//2
void AjouterLivreCategorie1(noeud_v *tete_v, char *categD)
{
	struct element elem;
	
	if( tete_v==NULL) // pour le 2e choix de l'application : 2-Ajouter un livre dans une categorie
	{
		printf("=>Cete bibliotheque est vide");
	}
	else
	{
		
		while( tete_v!=NULL   &&  strcmp( (*tete_v).val.categ , categD )!=0 )
		{
		    tete_v=(*tete_v).suiv;			
		}
						
		if ( tete_v!=NULL) 
		{
			creerElement(&elem);
		   	insererLivre(&(tete_v->tete_list_hori), elem);
		   	(*tete_v).val.nb_livre+= 1; // incrementer le nbre de livres dans cette categorie
		}
		else
			printf("=>La categorie que vous saisissez n'exsite pas dans cette bibliotheque"); // pour le 2e choix de l'application : 2-Ajouter un livre dans une categorie
		
	}
 
} 
 
//3
void afficherCategorieDonnee(noeud_v *tete, char *categD)
{
	if( tete==NULL)
		puts("\n=>votre bibliotheque est vide");	
	
	else
		while(tete)
		{
			if(  strcmp( (*tete).val.categ , categD )==0  )
			{
				printf("\nNom du categorie : %s \n",(*tete).val.categ);
				printf("Nombre de livres dans cette categorie : %d \n",(*tete).val.nb_livre);
				break;
			}

		    tete=(*tete).suiv;			
		}
		
		if (tete==NULL)
			printf("=>La categorie que vous saisissez n'exsite pas dans cette bibliotheque");		

} 

//4
void afficherLivre(noeud_v *tete_v, char *categD )
{
	int i;
	noeud_h *tete_h;

		while( tete_v!=NULL &&  strcmp((*tete_v).val.categ , categD)!=0  ) 
		{
			tete_v=tete_v->suiv;
		}
		
		if ( tete_v!=NULL)
		{
			printf("\n\n\t\tDans cette categorie il y a %d livre%c:\n ",(*tete_v).val.nb_livre, ( ((*tete_v).val.nb_livre)==1 ) ? ' ':'s' );
			tete_h=((*tete_v).tete_list_hori);
			i=0;
			while(tete_h)
			{	
				printf("\n\t\t\t%d %s Livre%c :",i+1, (i==0) ? "er" : "eme", (i==0) ? ' ' : 's');
				printf("\n\t\t\t\tNom du l'auteur : %s \n", tete_h->val.auteur); 	
				printf("\t\t\t\tNom du livre: %s \n", tete_h->val.titre_livre );  
		        
				// incrementation dans la liste horizontale
				tete_h=tete_h->suiv;
				i++;
				
			}					
			
		}
		else
			printf("=>La categorie que vous saisissez n'exsite pas dans cette bibliotheque");
		
}

//5
void affiche_seulement_categorie(noeud_v *tete)
{
	if( tete==NULL)
		puts("\n=>votre bibliotheque est vide");	
	
	else
		while(tete)
		{
			printf("Nom du categorie : %s \n",(*tete).val.categ);
			printf("Nombre de livres dans cette categorie : %d \n",(*tete).val.nb_livre);

		    tete=(*tete).suiv;			
		}

} 

//6
void afficheBib(noeud_v *tete_v)
{
		if( tete_v==NULL)
			puts("\n=>votre bibliotheque est vide");
		else
		{
			while(tete_v)
			{
				printf("\n\tNom du categorie : %s ",(*tete_v).val.categ);
				afficherLivre(tete_v, tete_v->val.categ );
				tete_v=tete_v->suiv;
			}
		
		}
	
}

//7
int nb_tot_livres(noeud_v *tete)
{
	int nb_livs=0;
	
	while(tete)
	{
		nb_livs+=(*tete).val.nb_livre;
		tete=(*tete).suiv;
	}
	
	return (nb_livs);
}

//8
void supprimer_categ(noeud_v **tete, char *categD)
{
	noeud_v *c,*p;
	
	if( *tete==NULL)
	{	 
		puts("\nvotre bibliotheque est deja vide");	
	}
	else
	{ 
		if(  strcmp( (**tete).val.categ , categD )==0  ) // pour que la premeire categorie = categorie à supprimer
	   	 {
		   		if((**tete).suiv==NULL) // s'il existe une seule categorie
		   		{
			   		free((**tete).suiv);
			   		*tete=NULL;
				}			
				else // il existe plus qu'une categorie // relier la tete avec 2 éme categorie
				{
					c=*tete;
					*tete=(*c).suiv;
					free(c);
					
				}
		   		
	   	    }  
	   	else
		{
	   		c=*tete;
	   		
		 	while( c  &&  strcmp( (*c).val.categ , categD )!=0 )
				{
					p=c;
					c=(*c).suiv;
					
				}
				
			// chainage et supp
				if(c!=NULL)
				{
					(*p).suiv = (*c).suiv;
					free(c);
				}
				else
					printf("=>La categorie que vous saisissez n'exsite pas dans cette bibliotheque");
	    
		}
	}
	
}

int existe(noeud_v * tete_v, char *categD)
{
			
		 	while( tete_v  &&  strcmp( (*tete_v).val.categ , categD )!=0 )
			{
				tete_v=(*tete_v).suiv;				
			}
			
			return (tete_v != NULL);
	
}

