#ifndef ADMIN_H
#define ADMIN_H

typedef struct {
    int id;
    char nombre[50];
    char contrasena[50];
} Admin;

void menuCrud();
void menuPrincipalAdmin();
void menuGestionAdmin();
void crearAdmin();
void mostrarAdmin();
void actualizarAdmin();
void eliminarAdmin();
void cerrarSesion();

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "login.h"

void menuCrud(){
    printf("1. Crear\n");
    printf("2. Leer\n");
    printf("3. Actualizar\n");
    printf("4. Eliminar\n");
}
void menuPrincipalAdmin() {
    int opcion;
    do {
        printf("\nMenú Administrador\n");
        printf("1. Gestionar administrador\n");
        printf("2. Gestionar docente\n");
        printf("3. Gestionar Estudiante\n");
        printf("4. Gestionar curso\n");
        printf("5. Gestionar asignatura\n");
        printf("6. Gestionar calificacion\n");
        printf("7. Cerrar sesion\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                menuGestionAdmin();
                break;
            case 7:
                cerrarSesion();
                break;
            case 0:
                printf("Saliendo...\n");
                Sleep(2000);  // Espera 2 segundos (2000 milisegundos) antes de salir y evitar que el usuario se quede con el programa abierto en el sistema, ademas si queremos implementar esto en (linux/mac) el valor se escribe en segundos y no en milisegundos.
                exit(0); // esto cierra (detiene) en su totalidad el programa.
            default:
                printf("Opción no válida\n");
        }
    } while(opcion != 0);
}
void menuGestionAdmin() {
    int opcion;
    do {
        printf("\nMenú De Gestion De Administradores\n");
        menuCrud();
        printf("0. volver al menú principal\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                crearAdmin();
                break;
            case 2:
                mostrarAdmin();
                break;
            case 3:
                actualizarAdmin();
                break;
            case 4:
                eliminarAdmin();
                break;
            case 0:
                printf("Volviendo al menú principal...\n");
                Sleep(2000);
                menuPrincipalAdmin();
                break;
            default:
                printf("Opción no válida\n");
                break;
        }
    } while(opcion != 0);
}

// Función para crear un nuevo administrador
void crearAdmin() {
    FILE *punteroArchivo = fopen("data/admin.txt", "a");
    if (punteroArchivo == NULL) {
        printf("Error al abrir la base de datos\n");
        return;
    }

    Admin admin;
    printf("Ingrese ID del administrador: ");
    scanf("%d", &admin.id);
    printf("Ingrese nombre del administrador: ");
    scanf("%s", admin.nombre);
    printf("Ingrese contraseña del administrador: ");
    scanf("%s", admin.contrasena);

    fprintf(punteroArchivo, "Tipo:Admin;ID:%d;Nombre:%s;Password:%s\n", admin.id, admin.nombre, admin.contrasena);
    fclose(punteroArchivo);

    printf("Administrador creado exitosamente.\n");
}

// Funcion para leer 
void mostrarAdmin() {
    FILE *punteroArchivo = fopen("data/admin.txt", "r");
    if (punteroArchivo == NULL) {
        printf("Error al abrir la base de datos\n");
        return;
    }

    Admin admin;
    printf("\nLista de administradores:\n");
    while (fscanf(punteroArchivo, "Tipo:Admin;ID:%d;Nombre:%[^;];Password:%[^;\n]\n", &admin.id, admin.nombre, admin.contrasena) == 3) {
        printf("ID: %d, Nombre: %s, Contraseña: %s\n", admin.id, admin.nombre, admin.contrasena);
    }

    fclose(punteroArchivo);
}

void actualizarAdmin() {
    FILE *punteroArchivo = fopen("data/admin.txt", "r");
    if (punteroArchivo == NULL) {
        printf("Error al abrir la base de datos\n");
        return;
    }
    // Leer todos los administradores en memoria
    #define MAX_ADMINS 100 // Define un tamaño máximo para el arreglo
    Admin admins[MAX_ADMINS];
    int count = 0;

    while (fscanf(punteroArchivo, "Tipo:Admin;ID:%d;Nombre:%[^;];Password:%[^;\n]\n", &admins[count].id, admins[count].nombre, admins[count].contrasena) == 3) {
        count++;
    }
    fclose(punteroArchivo);

    int idBuscado;
    printf("Ingrese el ID del administrador a actualizar: ");
    scanf("%d", &idBuscado);

    int encontrado = 0;

    // Actualizar el administrador en memoria
    for (int i = 0; i < count; i++) {
        if (admins[i].id == idBuscado) {
            encontrado = 1;
            printf("Ingrese nuevo nombre del administrador: ");
            scanf("%s", admins[i].nombre);
            printf("Ingrese nueva contraseña del administrador: ");
            scanf("%s", admins[i].contrasena);
            break;
        }
    }

    if (!encontrado) {
        printf("Administrador no encontrado.\n");
        return;
    }

    // Escribir todos los administradores de nuevo en el archivo
    punteroArchivo = fopen("data/admin.txt", "w");
    if (punteroArchivo == NULL) {
        printf("Error al abrir la base de datos para escribir\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(punteroArchivo, "Tipo:Admin;ID:%d;Nombre:%s;Password:%s\n", admins[i].id, admins[i].nombre, admins[i].contrasena);
    }

    fclose(punteroArchivo);
    printf("Administrador actualizado exitosamente.\n");

    // Mostrar el menú nuevamente
    menuGestionAdmin(); // Llama a la función del menú para que el usuario pueda continuar
}

void eliminarAdmin() {
    FILE *punteroArchivo = fopen("data/admin.txt", "r");
    if (punteroArchivo == NULL) {
        printf("Error al abrir la base de datos\n");
        return;
    }

    FILE *temp = fopen("data/temp.txt", "w");
    if (temp == NULL) {
        printf("Error al crear el archivo temporal\n");
        fclose(punteroArchivo);
        return;
    }

    int idBuscado;
    printf("Ingrese el ID del administrador a eliminar: ");
    scanf("%d", &idBuscado);

    Admin admin;
    int encontrado = 0;

    while (fscanf(punteroArchivo, "Tipo:Admin;ID:%d;Nombre:%[^;];Password:%[^;\n]\n", &admin.id, admin.nombre, admin.contrasena) == 3) {
        if (admin.id == idBuscado) {
            encontrado = 1; // Se encontró el administrador
            printf("Administrador con ID %d eliminado.\n", admin.id);
        } else {
            // Escribir en el archivo temporal si no es el administrador a eliminar
            fprintf(temp, "Tipo:Admin;ID:%d;Nombre:%s;Password:%s\n", admin.id, admin.nombre, admin.contrasena); // Cambiar fprintf por fprintf
        }
    }

    fclose(punteroArchivo); 
    fclose(temp); 

    if (!encontrado) { 
        printf("Administrador no encontrado.\n"); 
        remove("data/temp.txt"); // Eliminar el archivo temporal si no se encontró el administrador 
    } else { 
        if (remove("data/admin.txt") != 0) { 
            perror("Error al eliminar el archivo original"); 
        } else if (rename("data/temp.txt", "data/admin.txt") != 0) { 
            perror("Error al renombrar el archivo temporal"); 
        } else { 
            printf("Archivo actualizado exitosamente.\n"); 
        }   
    }
}

#endif
