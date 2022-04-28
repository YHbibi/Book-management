// Structures


struct element
{
	char titre_livre[20];
	char auteur[20];
};

struct bib // les champs du noeud (val) verticale
{
	char categ[20];
	int nb_livre;
};

struct noeud_v // verticale
{
  struct noeud_h *tete_list_hori;	// pointeur vers le premier noeud horizontal
  struct bib val;
  noeud_v *suiv;
};

struct noeud_h // horizontale
{
	struct element val; 
	noeud_h *suiv;
	
};

