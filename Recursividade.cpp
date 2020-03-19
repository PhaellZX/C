#include<stdio.h>
#include<stdlib.h>

int binario(int val){
	if(val <= 0){
		return 0;
	}else{
		printf("%d",val%2);
		return binario(val/2);
	}
}

int hexadecimal(int val){
	if(val <= 0){
		return 0;
	}else{
		switch(val%16){
			case 1:
				printf("1");
				return hexadecimal(val/16);
			break;
			case 2:
				printf("2");
				return hexadecimal(val/16);
			break;
			case 3:
				printf("3");
				return hexadecimal(val/16);
			break;
			case 4:
				printf("4");
				return hexadecimal(val/16);
			break;
			case 5:
				printf("5");
				return hexadecimal(val/16);
			break;
			case 6:
				printf("6");
				return hexadecimal(val/16);
			break;
			case 7:
				printf("7");
				return hexadecimal(val/16);
			break;
			case 8:
				printf("8");
				return hexadecimal(val/16);
			break;
			case 9:
				printf("9");
				return hexadecimal(val/16);
			break;
			case 10:
				printf("A");
				return hexadecimal(val/16);
			break;
			case 11:
				printf("B");
				return hexadecimal(val/16);
			break;
			case 12:
				printf("C");
				return hexadecimal(val/16);
			break;
			case 13:
				printf("D");
				return hexadecimal(val/16);
			break;
			case 14:
				printf("E");
				return hexadecimal(val/16);
			break;
			case 15:
				printf("F");
				return hexadecimal(val/16);
			break;
		}
	}
}

int octal(int val){
	if(val <= 0){
		return 0;
	}else{
		printf("%d",val%8);
		return octal(val/8);
	}
}

int contador(int val){
	if(val <= 0){
		return 0;
	}else{
		printf("%d\n",val);
		return contador(val - 1);
	}
}
int main(){
	
	int valor;
	scanf("%d",&valor);
	
	/*printf("%d\n",binario(valor)); // está imprimindo da direita pra esquerda 
	printf("%d\n",hexadecimal(valor)); // está imprimindo da esquerda pra direita ¯\_(ºº)_/¯ 
	printf("%d",octal(valor));*/
	
	contador(valor);
	return 0;
}
