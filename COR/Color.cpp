#include <stdio.h>
#include <windows.h>

int main()
{
HANDLE hConsole; 

hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// DEFINIR COR

// MUDAR A COR DA FONTE											

int azulExcuro = 1; 
int verdeEscuro = 2;
int azulClaro = 3; 
int vermelhoEscuro = 4; 
int roxo = 5; 
int amarelo = 6; 
int prata = 7; 
int cinza = 8; 
int azulMarinho = 9; 
int verdeClaro = 10; 
int azulCeleste = 11; 
int vermelhoClaro = 12; 
int rosa = 13; 
int amareloClaro = 14; 
int branco = 15; 

// Mudar Cor

SetConsoleTextAttribute(hConsole, 12);
printf("TESTANDO CORES-----------------> TOP^\n");

return 0;
}
