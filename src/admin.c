#include <stdio.h>
#include "admin.h"
#include "login.h"

void menuAdmin() {
    int opcion;
    do {
        printf("\nMenú Administrador\n");
        printf("1. Crear nuevo administrador\n");
        printf("2. Opción 2\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                crearAdmin();
                break;
            case 2:
                printf("Opción 2 seleccionada\n");
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while(opcion != 3);
}

// Función para crear un nuevo administrador
void crearAdmin() {
    FILE *fp = fopen("db.txt", "a");
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

    fprintf(fp, "Admin,%d,%s,%s\n", admin.id, admin.nombre, admin.contrasena);
    fclose(fp);

    printf("Administrador creado exitosamente.\n");
}
