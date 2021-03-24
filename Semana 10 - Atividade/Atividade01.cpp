#include <stdio.h>
#include <stdlib.h>

int soma(int v){
	if(v == 1)
		return 1;
	else
		return (v + soma(v - 1));
}


int main(){
	
	int valor;
	
	printf("Digite uma valor: ");
	scanf("%d",&valor);
	
	printf("A soma dos valores eh : %d",soma(valor));
	
	return 0;
}
