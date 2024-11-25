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
int login(char *usuario, char *contrasena);
void manejarLogin();
void cerrarSesion();
void salir();

// Definición de las funciones
void saludoBienvenida() {
    printf("\n-----Bienvenido a CalifiC-----\n");
}

void menuPrincipal() {
    saludoBienvenida();
    printf("1. Iniciar Sesión\n");
    printf("0. Salir\n");
    printf("Seleccione una opcion: ");
    int opcion;
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
        manejarLogin();
        break;
        case 0:
        salir();
        break;
        default:
        printf("opcion no válida\n");
        break;
    }
}

// Similar para docentes y estudiantes

void manejarLogin() { 
    char usuario[50]; 
    char contrasena[50]; 
    int tipoUsuario; 

    printf("\nIngrese su usuario:\n"); 
    scanf("%s", usuario); 
    printf("Ingrese su contrasena:\n"); 
    scanf("%s", contrasena); 

    tipoUsuario = login(usuario, contrasena);

    // En la función manejarLogin
printf("Usuario ingresado: %s\n", usuario); // Verifica el nombre ingresado
printf("contrasena ingresada: %s\n", contrasena); // Verifica la contrasena ingresada


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

void cerrarSesion() {
    printf("Cerrando sesión...\n");
    Sleep(2000);
    menuPrincipal();
    // Aquí puedes agregar cualquier limpieza adicional si es necesario
}

#endif // LOGIN_H
