#ifndef ADMIN_H
#define ADMIN_H
#include "login.h"
#include "estudiante.h"
#include "docente.h"
#include "asignatura.h"
typedef struct {
    char tipo[10];      // Tipo: Admin, Docente, Estudiante
    int id;             // ID del usuario
    char nombre[50];    // Nombre del usuario
    char contraseña[50]; // Contraseña del usuario
} Admin;

//printf("Admin leído: Tipo=%s, ID=%d, Nombre=%s, Contraseña=%s\n", admins[totalAdmins].tipo, admins[totalAdmins].id, admins[totalAdmins].nombre, admins[totalAdmins].contraseña); este print lee los datos del archivo y lo imprime en la consola.

void menuPrincipalAdmin();
void menuGestiónAdmin();
Admin crearAdmin();
void manejarAdmin();
void mostrarAdmin();
Admin actualizarAdmin(Admin *admins, int tamañoVector); 
void eliminarAdmin();
void guardarAdmins(Admin *admins, int tamañoVector);
void cerrarSesión();

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "login.h"

void menuPrincipalAdmin() {
    int opción;
    do {
        printf("\nMenú Administrador\n");
        printf("1. Gestionar administrador\n");
        printf("2. Gestionar docente\n");
        printf("3. Gestionar Estudiante\n");
        printf("4. Gestionar curso\n");
        printf("5. Gestionar asignatura\n");
        printf("6. Gestionar calificación\n");
        printf("7. Cerrar sesión\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opción);

        switch(opción) {
            case 1:
                menuGestiónAdmin();
                break;
            case 7:
                cerrarSesión();
                break;
            case 0:
                printf("Saliendo...\n");
                Sleep(2000);  // Espera 2 segundos 
                exit(0); // esto cierra (detiene) en su totalidad el programa.
            default:
                printf("Opción no válida\n");
        }
    } while(opción != 0);
}
void menuGestiónAdmin() {
    int opción;
    do {
        printf("\nMenú De Gestión De Administradores\n");
        printf("1. Crear administrador\n");
        printf("2. Mostrar administrador\n");
        printf("3. Actualizar administrador\n");
        printf("4. Eliminar administrador\n");
        printf("0. volver al menú principal\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opción);

        switch(opción) {
            case 1:
                //crearAdmin();
                break;
            case 2:
                //mostrarAdmin();
                break;
            case 3:
                //actualizarAdmin();
                break;
            case 4:
                //eliminarAdmin();
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
    } while(opción != 0);
}

// Función para crear un nuevo administrador
/*Admin crearAdmin(){
    manejarAgregarPersona(admins, &totalAdmins);
    Admin admin;
    char tipo[10] = "Admin";
    printf("Ingrese ID del administrador: ");
    scanf("%d", &admin.id);
    printf("Ingrese nombre del administrador: ");
    scanf("%s", admin.nombre);
    printf("Ingrese contraseña del administrador: ");
    scanf("%s", admin.contraseña);
    printf("Administrador creado exitosamente.\n");
    return admin;
}*/

/*void manejarAdmins(Admin admins[], int *totalAdmins) {
    if (*totalAdmins >= MAX_ADMINS) {
        printf("No se pueden añadir más registros. Límite alcanzado.\n");
        return;
    }
    admins[*totalAdmins] = agregarAdmin(); // Llama a la función para obtener una nueva persona
    (*totalAdmins)++;
}*/


/*void mostrarAdmin() {
    //cargarAdmins();
    Admin admin;
    while (scanf(Admin admins[], "%19[^,],%d,%49[^,],%49[^\n]\n", admins[totalAdmins].tipo, &admins[totalAdmins].id, admins[totalAdmins].nombre, admins[totalAdmins].contraseña) == 4) {
        printf("Admin leído: Tipo=%s, ID=%d, Nombre=%s, Contraseña=%s\n", admins[totalAdmins].tipo, admins[totalAdmins].id, admins[totalAdmins].nombre, admins[totalAdmins].contraseña);
        totalAdmins++;
}*/

Admin actualizarAdmin(Admin *admins, int tamañoVector) {
    int opción = 1;
    while (opción != 0) {
        //menuActualizarAdmin();
        scanf("%d", &opción);
        switch (opción) {
            case 1:
                printf("Ingrese el nuevo ID del administrador: ");
                scanf("%d", &admins[tamañoVector].id);
                printf("ID actualizado exitosamente.\n");
                break;  
            case 2:
                printf("Ingrese el nuevo nombre del administrador: ");
                scanf("%s", admins[tamañoVector].nombre);
                printf("Nombre actualizado exitosamente.\n");
                break;
            case 3:
                printf("Ingrese la nueva contraseña del administrador: ");
                scanf("%s", admins[tamañoVector].contraseña);
                printf("Contraseña actualizada exitosamente.\n");
                break;
            case 0:
                printf("\nHas salido del menu de actualización\n");
                break;
            default:
                printf("Opción no válida\n");
                break;
        }
    }
    return admins[tamañoVector];
}


/*void mostrarAdmin(Admin admin){
    printf("\nID: %d\n", admin.id);
    printf("Nombre: %s\n", admin.nombre);
    printf("Contraseña: %s\n", admin.contraseña);
}*/

void eliminarAdmin(Admin *admins, int tamañoVector){
    int opción = 1;
    while (opción != 0){
        //menuEliminarAdmin();
        scanf("%d", &opción);
        switch (opción){
        case 1:
            printf("Ingrese el ID del administrador a eliminar: ");
            scanf("%d", &admins[tamañoVector].id);
            printf("Administrador eliminado exitosamente.\n");
            break;
        case 2:
            printf("Ingrese el ID del administrador a eliminar: ");
            scanf("%d", &admins[tamañoVector].id);
            printf("Administrador eliminado exitosamente.\n");
            break;
        case 0:
            printf("\nHas salido del menu de eliminar administrador\n");
            break;
        default:
            break;
        }
    }
}

void guardarAdmins(Admin *admins, int totalAdmins) {
    FILE *punteroArchivo = fopen("data/admin.txt", "w");
    if (punteroArchivo == NULL) {
        printf("Error al abrir el archivo de administradores para guardar\n");
        return;
    }

    for (int i = 0; i < totalAdmins; i++) {
        fprintf(punteroArchivo, "Admin,%d,%s,%s\n", admins[i].id, admins[i].nombre, admins[i].contraseña);
    }

    fclose(punteroArchivo);
}



#endif
