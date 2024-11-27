#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "admin.h"


#define MAXADMINS 10
#define MAXESTUDIANTES 10
#define MAXDOCENTES 10
#define MAXASIGNATURAS 10
#define MAXCALIFICACIONES 10

//macros
#define FILE_ERROR(mensaje) fprintf(stderr, "Error: %s\n", mensaje); exit(EXIT_FAILURE)

// Uso:
// if (fopen("archivo.txt", "r") == NULL) {
//     ERROR("No se pudo abrir el archivo");
// }

void salir();

void salir() {
    printf("Saliendo...\n");
    Sleep(2000);  // Espera 2 segundos 
    exit(0); // esto cierra (detiene) en su totalidad el programa.
}

#endif