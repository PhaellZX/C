struct No {
	int dados;
	struct No * prox;
};

struct Pilha {
	struct No * top;
};

void criarPilha(Pilha * p){
	p->top = NULL;
}

int pilhaVazia(Pilha * p){
	return p->top == NULL;
}

void push(Pilha * p, int n){
	No * novo_no = (No*) malloc(sizeof(No));
	novo_no->dados = n;
	novo_no->prox = p->top;
	p->top = novo_no;
}

int pop(Pilha * p){
	if(pilhaVazia(p)){
		return 0;
	}
	int x = p->top->dados;
	No * temp = p->top;
	p->top = p->top->prox;
	free(temp);
	return x;
}
