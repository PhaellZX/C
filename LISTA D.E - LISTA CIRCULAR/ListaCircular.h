#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct lista  Lista;

struct lista
{
       int matricula;
	   char nome[20]; 
       struct lista * proximo; 
       };

//Criar Lista 
Lista * cria_lista(void)
{
 return(NULL);
}

//Cadastrar Matricula na lista
Lista * set_lista(Lista * l, int mat, char n[20])
{
 Lista * novo = (Lista *) malloc (sizeof(Lista));
 
   novo->matricula = mat;
   strcpy(novo->nome,n); 
   novo->proximo = l;
 
 return(novo);
 
 Lista * pl;
    for (pl = l; pl != l->proximo; pl = pl->proximo)
    l->proximo = novo;
}

//Mosta Lista
void view_lista(Lista * l)
{
Lista * pl;
      for (pl = l; pl != NULL; pl = pl->proximo)
      {
          printf("%d - %s\n", pl->matricula,pl->nome);
      }
}

//Verifica se a lista esta Vazia
int verifica_lista(Lista * l)
{
if (l == NULL)    
   printf("\nLista Vazia\n"); 
else
    printf("\nLista nao vazia\n"); 
}

//Procura a matricula na Lista
Lista * find_lista(Lista * l, int mat)
{
     Lista * pl;
      for (pl = l; pl != NULL; pl = pl->proximo)
      {
          if (pl->matricula == mat)
          		printf("Encontrado! %d - %s\n",pl->matricula,pl->nome);
             return (pl);
      }
      printf("Matricula nao encontrada!");
      return(NULL);
}


//Deletar matricula na lista
Lista * delete_elemento(Lista * pl, int mat)
{
      Lista * anterior = NULL;
      Lista * atual = pl;
      
      while (atual != NULL && atual->matricula != mat)
      {
            anterior = atual;
            atual = atual->proximo;
      }

      if (atual == NULL)
      {
         printf ("Elemento noo localizado!\n"); 
         return(pl);
      }
      
      if (anterior == NULL)
          pl = pl->proximo; 
      else
      {
          anterior->proximo = atual->proximo;
      }
      printf("Matricula deletada!\n");
      free(atual);
      return(pl);
}


//Liberar a lista
void free_lista(Lista ** pl)
{
      while (*pl != NULL)
      {
           Lista * t = (*pl)->proximo;
           *pl = NULL;
           free(*pl);
           *pl = t;
      }
 }

