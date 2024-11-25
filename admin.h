#ifndef ADMIN_H
#define ADMIN_H
#include "utilidades.h"
#include "estudiante.h"
#include "docente.h"
#include "asignatura.h"
typedef struct {
    int id;             // ID del usuario
    char nombre[50];    // Nombre del usuario
    char contrasena[50]; // contrasena del usuario
} Admin;


extern int totalAdmins;
Admin admins[MAXADMINS]; 

//printf("Admin leído: Tipo=%s, ID=%d, Nombre=%s, contrasena=%s\n", admins[totalAdmins].tipo, admins[totalAdmins].id, admins[totalAdmins].nombre, admins[totalAdmins].contrasena); este print lee los datos del archivo y lo imprime en la consola.
void cargarAdmins();
void menuPrincipalAdmin();
void menuGestionAdmin();
void menuPrincipalEstudiante();
Admin crearAdmin();
void manejarAdmin();
void mostrarAdmin();
Admin actualizarAdmin(Admin *admins, int tamanoVector); 
void eliminarAdmin();
void guardarAdmins(Admin *admins, int tamanoVector);
void cerrarSesion();

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

// Función para cargar los datos de los administradores desde el archivo
void cargarAdmins() {
    FILE *archivoAdmins = fopen("data/admin.txt", "r");
    if (archivoAdmins == NULL) {
        printf("Error al abrir el archivo admin.txt\n");
        return;
    }

    totalAdmins = 0; // Reinicia el contador de administradores

    // Lee cada línea del archivo con el formato separado por comas
    while (fscanf(archivoAdmins, "%d,%49[^,],%49[^\n]\n", &admins[totalAdmins].id, admins[totalAdmins].nombre, admins[totalAdmins].contrasena) == 3) {
        totalAdmins++;

        // Verifica si se alcanzó el límite de administradores
        if (totalAdmins >= MAXADMINS) {
            printf("Límite de admins alcanzado. Aumenta el tamaño de MAXADMINS.\n");
            break;
        }
    }

    printf("Administradores cargados correctamente.\n");
    fclose(archivoAdmins);
}

void menuPrincipalAdmin() {
    int opcion;
    do {
        printf("\nMenú Administrador\n");
        printf("1. Gestionar administrador\n");
        printf("2. Gestionar docente\n");
        printf("3. Gestionar Estudiante\n");
        printf("4. Gestionar asignatura\n");
        printf("5. Gestionar calificación\n");
        printf("6. Volver al menú principal\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                menuGestionAdmin();
                break;
            case 3:
                menuPrincipalEstudiante();
                break;
            case 6:
                //cerrarSesion();
                break;
            case 0:
                salir();
                break;
            default:
                printf("opcion no válida\n");
        }
    } while(opcion != 0);
}
void menuGestionAdmin() {
    int opcion;
    do {
        printf("\nMenú De Gestión De Administradores\n");
        printf("1. Crear administrador\n");
        printf("2. Mostrar administrador\n");
        printf("3. Actualizar administrador\n");
        printf("4. Eliminar administrador\n");
        printf("0. volver al menú principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                if (totalAdmins < MAXADMINS) {
                    Admin admin = crearAdmin();
                    admins[totalAdmins] = admin;
                    totalAdmins++;
                    guardarAdmins(admins, totalAdmins);
                } else {
                    printf("El máximo número de estudiantes ha sido alcanzado.\n");
                }
                break;
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
                printf("opcion no válida\n");
                break;
        }
    } while(opcion != 0);
}

// Función para crear un nuevo administrador
Admin crearAdmin(){
    Admin admin;
    printf("Ingrese ID del administrador: ");
    scanf("%d", &admin.id);
    printf("Ingrese nombre del administrador: ");
    scanf("%s", admin.nombre);
    printf("Ingrese contrasena del administrador: ");
    scanf("%s", admin.contrasena);
    printf("Administrador creado exitosamente.\n");
    return admin;
}

/*void mostrarAdmin() {
    //cargarAdmins();
    Admin admin;
    while (scanf(Admin admins[], "%19[^,],%d,%49[^,],%49[^\n]\n", admins[totalAdmins].tipo, &admins[totalAdmins].id, admins[totalAdmins].nombre, admins[totalAdmins].contrasena) == 4) {
        printf("Admin leído: Tipo=%s, ID=%d, Nombre=%s, contrasena=%s\n", admins[totalAdmins].tipo, admins[totalAdmins].id, admins[totalAdmins].nombre, admins[totalAdmins].contrasena);
        totalAdmins++;
}*/

Admin actualizarAdmin(Admin *admins, int tamanoVector) {
    int opcion = 1;
    while (opcion != 0) {
        //menuActualizarAdmin();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("Ingrese el nuevo ID del administrador: ");
                scanf("%d", &admins[tamanoVector].id);
                printf("ID actualizado exitosamente.\n");
                break;  
            case 2:
                printf("Ingrese el nuevo nombre del administrador: ");
                scanf("%s", admins[tamanoVector].nombre);
                printf("Nombre actualizado exitosamente.\n");
                break;
            case 3:
                printf("Ingrese la nueva contrasena del administrador: ");
                scanf("%s", admins[tamanoVector].contrasena);
                printf("contrasena actualizada exitosamente.\n");
                break;
            case 0:
                printf("\nHas salido del menu de actualización\n");
                break;
            default:
                printf("opcion no válida\n");
                break;
        }
    }
    return admins[tamanoVector];
}


/*void mostrarAdmin(Admin admin){
    printf("\nID: %d\n", admin.id);
    printf("Nombre: %s\n", admin.nombre);
    printf("contrasena: %s\n", admin.contrasena);
}*/

void eliminarAdmin(Admin *admins, int tamanoVector){
    int opcion = 1;
    while (opcion != 0){
        //menuEliminarAdmin();
        scanf("%d", &opcion);
        switch (opcion){
        case 1:
            printf("Ingrese el ID del administrador a eliminar: ");
            scanf("%d", &admins[tamanoVector].id);
            printf("Administrador eliminado exitosamente.\n");
            break;
        case 2:
            printf("Ingrese el ID del administrador a eliminar: ");
            scanf("%d", &admins[tamanoVector].id);
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
        fprintf(punteroArchivo, "%d,%s,%s\n", admins[i].id, admins[i].nombre, admins[i].contrasena);
    }

    fclose(punteroArchivo);
}



#endif
