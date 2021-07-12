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
 return (NULL);      
}

//Cadastrar nova matricula na listas
Lista * set_lista(Lista * l, int a, char n[20])
{
 Lista * novo = (Lista *) malloc (sizeof(Lista));
 novo->matricula = a;
 strcpy(novo->nome,n); 
 novo->proximo = l;
 return(novo);
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

//Verifica se a lista esta vazia
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
          	 printf("\nencontrado!\n%d - %s",pl->matricula,pl->nome);
             return (pl);
      }
      printf("\nNao encontrado...\n");
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
         printf ("Elemento nao localizado!\n"); 
         return(pl);
      }
      
      if (anterior == NULL)
          pl = pl->proximo; 
      else
      {
          anterior->proximo = atual->proximo;
      }
      printf("\nCadastro deletado!\n");
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

