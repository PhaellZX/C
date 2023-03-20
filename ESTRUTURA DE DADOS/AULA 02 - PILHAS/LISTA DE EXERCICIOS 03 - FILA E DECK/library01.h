#define N 4

// FILA

struct Fila {
	int n;
	int ini;
	int vet[N];
};

// CRIAR FILA

Fila * fila_cria(void){
		Fila * f = (Fila*) malloc(sizeof(Fila));
		f->n = 0;
		f->ini = 0;
		return f;
}

// VERIFICAR SE FILA EST? CHEIA

int full(Fila * f){
	return (f->n==N);	
}

// INSERIR VALOR NA FILA

void queue(Fila * f,int v){
	int fim;
	if(full(f)){
		printf("Capacidade da fila estourou.\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N;
	f->vet[fim] = v;
	f->n++;
	printf("Inserir %d\n",v);
}

// VERIFICAR SE A FILA EST? VAZIA

int empty(Fila * f){
	return (f->n == 0);
}

// RETIRAR O VALOR DA FILA

int dequeue(Fila * f){
	int v;
	if(empty(f)){
		printf("Fila vazia.\n");
		exit(1);
	}
	v= f->vet[f->ini];
	f->ini = (f->ini + 1) % N;
	f->n--;
	return v;
}
