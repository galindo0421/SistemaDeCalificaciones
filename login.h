#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <windows.h>
#include <stdlib.h>
#include "admin.h"
#include "docente.h"
#include "estudiante.h"
#include "utilidades.h"

#define MAX_ADMINS 100 // Definir tamaño de los arreglos

extern int totalAdmins;

// Declaración de funciones
void cargarAdmins();
void saludoBienvenida();
void menuPrincipal();
void menuPrincipalAdmin();
int login(char *usuario, char *contraseña);
void manejarLogin();
void cerrarSesión();
void salir();

// Definición de las funciones
void saludoBienvenida() {
    printf("\n-----Bienvenido a CalifiC-----\n");
}

void menuPrincipal() {
    saludoBienvenida();
    printf("1. Iniciar Sesión\n");
    printf("0. Salir\n");
    printf("Seleccione una opción: ");
    int opción;
    scanf("%d", &opción);

    switch (opción) {
        case 1:
        manejarLogin();
        break;
        case 0:
        salir();
        break;
        default:
        printf("Opción no válida\n");
        break;
    }
}

// Similar para docentes y estudiantes

void manejarLogin() { 
    char usuario[50]; 
    char contraseña[50]; 
    int tipoUsuario; 

    printf("\nIngrese su usuario:\n"); 
    scanf("%s", usuario); 
    printf("Ingrese su contraseña:\n"); 
    scanf("%s", contraseña); 

    tipoUsuario = login(usuario, contraseña);

    // En la función manejarLogin
printf("Usuario ingresado: %s\n", usuario); // Verifica el nombre ingresado
printf("Contraseña ingresada: %s\n", contraseña); // Verifica la contraseña ingresada


    switch (tipoUsuario) {
        case 1:
            printf("Bienvenido Admin!\n");
            menuPrincipalAdmin();
            break;
        case 666:
            printf("Welcome Master!\n");
            menuPrincipalAdmin();
            break;
        default:
            printf("Credenciales incorrectas. Intente nuevamente.\n");
            break;
    }
}

void cerrarSesión() {
    printf("Cerrando sesión...\n");
    Sleep(2000);
    menuPrincipal();
    // Aquí puedes agregar cualquier limpieza adicional si es necesario
}

#endif // LOGIN_H
