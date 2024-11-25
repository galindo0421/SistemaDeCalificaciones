#ifndef INICIO_H
#define INICIO_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <windows.h>
#include <stdlib.h>
#include "admin.h"
#include "docente.h"
#include "estudiante.h"
#include "utilidades.h"

typedef enum {
    MenuPrincipalAdmin = 1,
    MenuPrincipalDocente,
    MenuPrincipalEstudiante 
} Menu;

// Implementación del menú principal
Menu mostrarMenuPrincipal() {
    Menu opcion;

    printf("\n-----Bienvenido a CalifiC-----\n");
    printf("Tipo de usuario: \n");
    printf("1. Administrador\n");
    printf("2. Docente\n");
    printf("3. Estudiante\n");
    printf("Selecciona una opción:\n");
    scanf("%d", (int*)&opcion); // Lee la opción y la convierte a tipo Menu

    switch (opcion) {
        case MenuPrincipalAdmin:
            menuPrincipalAdmin();
            break;
        case MenuPrincipalDocente:
            printf("Función para Docente no implementada.\n");
            break;
        case MenuPrincipalEstudiante:
            menuPrincipalEstudiante();
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

    return opcion; // Retorna la opción seleccionada
}

#endif // INICIO_H

