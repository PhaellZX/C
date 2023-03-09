/* Replace "dll.h" with the name of your header */
#include "stack.h"
#include <windows.h>

int topo = -1;

DLLIMPORT int IsEmpty(int * array){  // Verificar se est? vazio
	if (topo == -1) {
        return 1;
    } else {
        return 0;
    } 
}

DLLIMPORT void push(int * array, int valor) { // Inserir no topo da pilha
    if (topo == 10 - 1) {
        printf("Erro: pilha cheia!\n");
    } else {
        topo++;
        array[topo] = valor;
    }
}

DLLIMPORT int pop(int * array) { // Retirar do topo da pilha
    if (topo == -1) { // verificar se topo ? menor que 0
        printf("Erro: pilha vazia!\n");
        return -1;
    } else {
        int valor = array[topo];
        topo--;
        return valor;
    }
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}
