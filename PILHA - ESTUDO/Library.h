

// estrutura da pilha
struct No {
    int dados;
    struct No * prox;
};

struct Pilha {
    struct No * top;
};

// função para inicializar a pilha
void criarPilha(Pilha * p) {
    p->top = NULL; // pilha vazia
}

// função para verificar se a pilha está vazia
int pilhaVazia(Pilha * p) {
    return p->top == NULL;
}

// função para adicionar um elemento à pilha
void push(Pilha * p, int x) {
    No * novo_no = (No*) malloc(sizeof(No));
    novo_no->dados = x;
    novo_no->prox = p->top;
    p->top = novo_no;
}

// função para remover um elemento da pilha
int pop(Pilha * p) {
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia!\n");
        return -1; // valor de erro
    }
    int x = p->top->dados;
    No * temp = p->top;
    p->top = p->top->prox;
    free(temp);
    return x;
}

void interface(){
	printf("---Biblioteca Stack---\nEscolha uma das opcoes:\n1 - Ler um Livro\n0 - Sair\n");
}

void leituraLivro(char titulo[50], int pags, int i){
		Pilha livro;
    	criarPilha(&livro);
		
		system("cls");
    	printf("Digite o titulo do livro: ");
    	getchar();
    	fgets(titulo, 50, stdin);
    	titulo[strcspn(titulo, "\n")] = '\0';
    	printf("Digite o numero de paginas que sera lido: ");
    	scanf("%d",&pags);
    		
    	printf("\n");
    		
		//Inserindo Paginas no livro
    	for(i = pags; i >= 1; i--){
    		push(&livro,i);
			}
		//Lendo o Livro
		for(i = 1; i <= pags; i++){
			printf("Lendo a pagina: %d\n",pop(&livro));
			}
			printf("\n");
}

