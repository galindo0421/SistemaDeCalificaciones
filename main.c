#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "login.h"

#define MAX_ADMINS 100
#define MAX_DOCENTES 100
#define MAX_ESTUDIANTES 100
#define MAX_ASIGNATURAS 100

Admin admins[MAX_ADMINS];

int totalAdmins = 0; // Variables globales

// Declaración de funciones fuera de main
void cargarAdmins();
void cargarDatos();

int main(){  
    cargarDatos();       // Cargar los datos desde los archivos
    menuPrincipal();      // Llamar a la función de menu principal
    return 0;
}

// Función para cargar los datos de los administradores desde el archivo
void cargarAdmins() {
    FILE *archivoAdmins = fopen("data/admin.txt", "r");
    if (archivoAdmins == NULL) {
        printf("Error al abrir el archivo admin.txt\n");
        return;
    }

    totalAdmins = 0; // Reinicia el contador de administradores

    // Lee cada línea del archivo con el formato separado por comas
    while (fscanf(archivoAdmins, "%19[^,],%d,%49[^,],%49[^\n]\n", admins[totalAdmins].tipo, &admins[totalAdmins].id, admins[totalAdmins].nombre, admins[totalAdmins].contraseña) == 4) {
        totalAdmins++;

        // Verifica si se alcanzó el límite de administradores
        if (totalAdmins >= MAX_ADMINS) {
            printf("Límite de admins alcanzado. Aumenta el tamaño de MAX_ADMINS.\n");
            break;
        }
    }

    printf("Administradores cargados correctamente.\n");
    fclose(archivoAdmins);
}



// Función para cargar todos los datos (admin, docente, estudiante, etc.)
void cargarDatos() {
    cargarAdmins();  // Cargar admins desde archivo
    printf("Datos cargados:\n");
    printf("Admins: %d\n", totalAdmins);
    for (int i = 0; i < totalAdmins; i++) {
        printf("%s\n", admins[i].nombre);
    }
}

// Función login para comparar usuario y contraseña
int login(char *usuario, char *contraseña) {
    for (int contador = 0; contador < totalAdmins; contador++) {
        if (strcmp(admins[contador].nombre, usuario) == 0 && strcmp(admins[contador].contraseña, contraseña) == 0) {
            return 1; // Si el usuario y la contraseña coinciden
        }
    }
    return 0; // Si no hay coincidencia
}

