 #include <stdio.h>
#include <stdlib.h>
#define N 100

// FILA

struct Fila {
	int n;
	int ini;
	float vet[N];
};

// CRIAR FILA

Fila * fila_cria(void){
	Fila * f = (Fila*) malloc(sizeof(Fila));
	f->n = 0;
	f->ini = 0;
	return f;
}

// VERIFICAR SE FILA ESTÁ CHEIA

int fila_cheia(Fila * f){
	return (f->n==N);	
}

// INSERIR VALOR NA FILA

void fila_insere(Fila * f,float v){
	int fim;
	if(fila_cheia(f)){
		printf("Capacidade da fila estourou.\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N;
	f->vet[fim] = v;
	f->n++;
	printf("Inserindo: %.2f\n",v);
}


// VERIFICAR SE A FILA ESTÁ VAZIA

int fila_vazia(Fila * f){
	return (f->n == 0);
}


// RETIRAR O VALOR DA FILA

float fila_retira(Fila * f){
	float v;
	if(fila_vazia(f)){
		printf("Fila vazia.\n");
		exit(1);
	}
	v= f->vet[f->ini];
	f->ini = (f->ini + 1) % N;
	f->n--;
	return v;
}
// LIBERAR FILA

void fila_libera(Fila * f){
	free(f);
}

int main(){
	
	Fila * fila;
	
	fila = fila_cria();
	
	if(fila_cria()){
		printf("Fila criada!!\n");
	}
	
	fila_insere(fila,10);
	fila_insere(fila,20);
	fila_insere(fila,30);	
	fila_insere(fila,40);
	fila_insere(fila,50);
	
	printf("Retirando: %.2f\n",fila_retira(fila));
	printf("Retirando: %.2f\n",fila_retira(fila));
	
	fila_libera(fila);
	
	return 0;
}
