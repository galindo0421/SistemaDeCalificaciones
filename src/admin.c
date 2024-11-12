#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "login.h"

void menuAdmin() {
    int opcion;
    do {
        printf("\nMenú Administrador\n");
        printf("1. Crear nuevo administrador\n");
        printf("2. Leer administradores\n");
        printf("3. Actualizar administrador\n");
        printf("4. Eliminar administrador\n");
        printf("5. Cerrar sesion");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                crearAdmin();
                break;
            case 2:
                leerAdmin();
                break;
            case 3:
                actualizarAdmin();
                break;
            case 4:
                eliminarAdmin();
                break;
            case 5:
                cerrarSesion();
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while(opcion != 0);
}

// Función para crear un nuevo administrador
void crearAdmin() {
    FILE *fp = fopen("data/admin.txt", "a");
    if (fp == NULL) {
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

    fprintf(fp, "Tipo:Admin;ID:%d;Nombre:%s;Password:%s\n", admin.id, admin.nombre, admin.contrasena);
    fclose(fp);

    printf("Administrador creado exitosamente.\n");
}

// Funcion para leer 
void leerAdmin() {
    FILE *fp = fopen("data/admin.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir la base de datos\n");
        return;
    }

    Admin admin;
    printf("Lista de administradores:\n");
    while (fscanf(fp, "Tipo:Admin;ID:%d;Nombre:%[^;];Password:%[^;\n]\n", &admin.id, admin.nombre, admin.contrasena) == 3) {
        printf("ID: %d, Nombre: %s, Contraseña: %s\n", admin.id, admin.nombre, admin.contrasena);
    }

    fclose(fp);
}

void actualizarAdmin() {
    FILE *fp = fopen("data/admin.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir la base de datos\n");
        return;
    }
    // Leer todos los administradores en memoria
    #define MAX_ADMINS 100 // Define un tamaño máximo para el arreglo
    Admin admins[MAX_ADMINS];
    int count = 0;

    while (fscanf(fp, "Tipo:Admin;ID:%d;Nombre:%[^;];Password:%[^;\n]\n", &admins[count].id, admins[count].nombre, admins[count].contrasena) == 3) {
        count++;
    }
    fclose(fp);

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
    fp = fopen("data/admin.txt", "w");
    if (fp == NULL) {
        printf("Error al abrir la base de datos para escribir\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "Tipo:Admin;ID:%d;Nombre:%s;Password:%s\n", admins[i].id, admins[i].nombre, admins[i].contrasena);
    }

    fclose(fp);
    printf("Administrador actualizado exitosamente.\n");

    // Mostrar el menú nuevamente
    menuAdmin(); // Llama a la función del menú para que el usuario pueda continuar
}

void eliminarAdmin() {
    FILE *fp = fopen("data/admin.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir la base de datos\n");
        return;
    }

    FILE *temp = fopen("data/temp.txt", "w");
    if (temp == NULL) {
        printf("Error al crear el archivo temporal\n");
        fclose(fp);
        return;
    }

    int idBuscado;
    printf("Ingrese el ID del administrador a eliminar: ");
    scanf("%d", &idBuscado);

    Admin admin;
    int encontrado = 0;

    while (fscanf(fp, "Tipo:Admin;ID:%d;Nombre:%[^;];Password:%[^;\n]\n", &admin.id, admin.nombre, admin.contrasena) == 3) {
        if (admin.id == idBuscado) {
            encontrado = 1; // Se encontró el administrador
            printf("Administrador con ID %d eliminado.\n", admin.id);
        } else {
            // Escribir en el archivo temporal si no es el administrador a eliminar
            fprintf(temp, "Tipo:Admin;ID:%d;Nombre:%s;Password:%s\n", admin.id, admin.nombre, admin.contrasena);
        }
    }

    fclose(fp); 
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