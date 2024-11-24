#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void salir();

void salir() {
    printf("Saliendo...\n");
    Sleep(2000);  // Espera 2 segundos 
    exit(0); // esto cierra (detiene) en su totalidad el programa.
}

#endif