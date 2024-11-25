#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utilidades.h"
#include "admin.h"
#include "login.h"
#include "estudiante.h"



int totalAdmins = 0; // Variables globales

// Declaración de funciones fuera de main
void cargarAdmins();
void cargarDatos();

int main(){  
    cargarDatos();       // Cargar los datos desde los archivos
    menuPrincipal();     // Llamar a la función de menu principal
    return 0;
}

// void cargarDocentes() {
//     FILE *archivoDocentes = fopen("data/docente.txt", "r");
//     if (archivoDocentes == NULL) {
//         printf("Error al abrir el archivo docente.txt\n");
//         return;
//     }
//     totalDocentes = 0; // Reinicia el contador de docentes
//     // Lee cada línea del archivo con el formato separado por comas
//     while (fscanf(archivoDocentes, "%19[^,],%d,%49[^,],%49[^\n]\n", docentes[totalDocentes].tipo, &docentes[totalDocentes].id, docentes[totalDocentes].nombre, docentes[totalDocentes].contrasena) == 4) {
//         totalDocentes++;
//         // Verifica si se alcanzó el límite de docentes
//         if (totalDocentes >= MAX_DOCENTES) {
//             printf("Límite de docentes alcanzado. Aumenta el tamaño de MAX_DOCENTES.\n");
//             break;
//         }
//     }
//     printf("Docentes cargados correctamente.\n");
//     fclose(archivoDocentes);
// }

// void cargarEstudiantes() {
//     FILE *archivoEstudiantes = fopen("data/estudiante.txt", "r");
//     if (archivoEstudiantes == NULL) {
//         printf("Error al abrir el archivo estudiante.txt\n");
//         return;
//     }
//     totalEstudiantes = 0; // Reinicia el contador de estudiantes
//     // Lee cada línea del archivo con el formato separado por comas
//     while (fscanf(archivoEstudiantes, "%19[^,],%d,%49[^,],%49[^\n]\n", estudiantes[totalEstudiantes].tipo, &estudiantes[totalEstudiantes].id, estudiantes[totalEstudiantes].nombre, estudiantes[totalEstudiantes].contrasena) == 4) {
//         totalEstudiantes++;
//         // Verifica si se alcanzó el límite de estudiantes
//         if (totalEstudiantes >= MAX_ESTUDIANTES) {
//             printf("Límite de estudiantes alcanzado. Aumenta el tamaño de MAX_ESTUDIANTES.\n");
//             break;
//         }
//     }
//     printf("Estudiantes cargados correctamente.\n");
//     fclose(archivoEstudiantes);
// }

// Función login para comparar usuario y contrasena
int login(char *usuario, char *contrasena) {
    if (strcmp(usuario, "admin") == true && strcmp(contrasena, "admin") == true){
        return 666; // Si el usuario y la contrasena coinciden
    }else{
        for (int contador = 0; contador < totalAdmins; contador++){
            if (strcmp(admins[contador].nombre, usuario) == true && strcmp(admins[contador].contrasena, contrasena) == true){
                return 1; // Si el usuario y la contrasena coinciden
            }
        }
        // for (int contador = 0; contador < totalDocentes; contador++) {
        //     if (strcmp(docentes[contador].nombre, usuario) == 0 && strcmp(docentes[contador].contrasena, contrasena) == 0) {
        //         return 2; // Si el usuario y la contrasena coinciden
        //     }
        // }
        // for (int contador = 0; contador < tamanoVectorEstudiantes; contador++) {
        //     if (strcmp(estudiantes[contador].nombre, usuario) == 0 && strcmp(estudiantes[contador].contrasena, contrasena) == 0) {
        //         return 3; // Si el usuario y la contrasena coinciden
        //     }
        // }
        return 0; // Si el usuario y la contrasena no coinciden
    }
}

// Función para cargar todos los datos (admin, docente, estudiante, etc.)
void cargarDatos(){
    cargarAdmins();  // Cargar admins desde archivo
    printf("Datos cargados:\n");
    printf("Admins: %d\n", totalAdmins);
    for (int i = 0; i < totalAdmins; i++) {
        printf("%s\n", admins[i].nombre);
    }
}