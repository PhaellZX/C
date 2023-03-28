 // Lista Encadeada
 
 struct lista {
 	int info;
 	struct lista * prox;
 };
 
 typedef struct lista Lista;
 
 // Criar Lista
 Lista * lst_cria(void){
 	return NULL;
 }
 
 //Inserir na lista 
 Lista * lst_insere(Lista * l, int i){
 	Lista * novo = (Lista*) malloc(sizeof(Lista));
 	novo->info = i;
 	novo->prox = l;
 	return novo;
 } 
 
 //Inseri e atualiza a lista
 void lst_insere_Atualizar(Lista ** l, int i){
 	Lista * novo = (Lista*) malloc(sizeof(Lista));
 	novo->info = i;
 	novo->prox = *l;
 	*l = novo;
 }
 
 //Imprimir a lista
 void lst_imprime(Lista * l){
 	Lista * p;
 	int i = 0;
 	for(p = l; p != NULL; p = p->prox){
 		printf("[%d] -> %d\n",i,p->info);
 		i++;
	 }
 }
 
 // Verificar se a Lista está vazia
 int lst_vazia(Lista * l){
 	return (l == NULL);	
 }

//Localizar na lista com ordenação
Lista* Localiza(Lista* L, int valor) {
	Lista* atual = L;
	Lista * anterior = NULL;
	while (atual != NULL && atual->info < valor) {
		anterior = atual;
		atual = atual->prox;
	}
	return anterior;
}
 
// Inserir na Lista e ordenar
void inserir_ordenar(Lista ** l, int v) {
   Lista * NovoNo = (Lista*) malloc(sizeof(Lista));
   NovoNo->info = v;
   NovoNo->prox = NULL;

   // se a lista estiver vazia, o novo nó é o primeiro nó da lista
   if (*l == NULL) {
      *l = NovoNo;
      return;
   }
	// encontra o nó anterior ao ponto de inserção
   Lista * prev = NULL;
   Lista * curr = *l;
   while (curr != NULL && curr->info < v) {
      prev = curr;
      curr = curr->prox;
   }
	// insere o novo nó na lista
   if (prev == NULL) { // o novo nó é o primeiro nó da lista
      NovoNo->prox = *l;
      *l = NovoNo;
   } else { // o novo nó é inserido após o nó anterior
      NovoNo->prox = prev->prox;
      prev->prox = NovoNo;
   }
}

// Remover valor da Lista
Lista * Remover(Lista * L, int valor) {
	Lista* atual = L; // atual deve conter No com o valor;
	Lista* anterior = NULL; // anterior deve conter No anterior ao No com o valor;
	while (atual != NULL && atual->info != valor){
		anterior = atual;
		atual = atual->prox;
	}
	if (atual == NULL) return L; // não encontrou
	if (anterior == NULL){ // valor no primeiro No
		L = atual->prox;
		free(atual);
	} else { // valor no meio da lista
		anterior->prox = atual->prox;
		free(atual);
	}
	return L;
}

// Apagar Lista 
Lista * ApagarLista(Lista *L){
	Lista * atual = L;
	while (atual != NULL){
		Lista* t = atual->prox;
		free(atual);
		atual = t;
	}
	return NULL;
}


