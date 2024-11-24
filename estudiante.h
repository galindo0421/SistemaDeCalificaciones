#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"
#include "asignatura.h"

typedef struct{
    int id;
    char nombre[50];
    char apellido[50];
    char contrasena[50];
    Asignatura asignaturas[6];
} Estudiante;

Estudiante crearEstudiante(){
    Estudiante estudiante;
    printf("\nIngrese el ID de estudiante: \n");
    scanf("%d", &estudiante.id);
    printf("Ingrese el nombre del estudiante: \n");
    scanf("%s", estudiante.nombre);
    printf("Ingrese el apellido del estudiante: \n");
    scanf("%s", estudiante.apellido);
    printf("Ingrese la contrasena del estudiante: \n");
    scanf("%s", estudiante.contrasena);
    printf("\nEstudiante creado exitosamente.\n");
    return estudiante;  
}

void menuActualizarEstudiante(){
    printf("\nMenu para actualizar datos de un estudiante\n");
    printf("1. Cambiar ID\n");
    printf("2. Cambiar nombre\n");
    printf("3. Cambiar apellido\n");
    printf("4. Cambiar contrasena\n");
    printf("0. Salir\n");
    printf("Seleccione una opcion: ");
}

Estudiante actualizarEstudiante(Estudiante *estudiantes, int tamanoVector){
    int opcion = 1;    
    while (opcion != 0){
        menuActualizarEstudiante();
        scanf("%d", &opcion);
        switch (opcion){
        case 1:
            printf("Ingrese el nuevo ID de estudiante:");
            scanf("%d", &estudiantes[tamanoVector].id);
            printf("ID actualizado exitosamente.\n");
            break;  
        case 2:
            printf("Ingrese el nuevo nombre del estudiante:");
            scanf("%s", estudiantes[tamanoVector].nombre);
            printf("Nombre actualizado exitosamente.\n");
            break;
        case 3:
            printf("Ingrese el nuevo apellido del estudiante:");
            scanf("%s", estudiantes[tamanoVector].apellido);
            printf("Apellido actualizado exitosamente.\n");
            break;
        case 4:
            printf("Ingrese la nueva contraseña del estudiante:");
            scanf("%s", estudiantes[tamanoVector].contrasena);
            printf("Contraseña actualizada exitosamente.\n");
            break;
        //case 5:
            /*printf("Ingrese el nuevo nombre de asignatura: \n");
            scanf("%d", &estudiante.asignaturas[0].nombre);
            printf("Nombre de asignatura actualizado exitosamente.\n");
            break;*/
        //case 6:
            /*printf("Ingrese la nueva calificacion de asignatura: \n");
            scanf("%f", &estudiante.asignaturas[0].calificaciones[0]);
            printf("Calificacion actualizada correctamente\n");*/
        case 0:
            printf("\nHas salido del menu de crear estudiante\n");
            break;
        default:
            break;
        }
    }
    return estudiantes[tamanoVector];
}

void mostrarEstudiante(Estudiante estudiante){
    printf("\nID: %d\n", estudiante.id);
    printf("Nombre: %s\n", estudiante.nombre);
    printf("Apellido: %s\n", estudiante.apellido);
    printf("Contrasena: %s\n", estudiante.contrasena);
}

void guardararchivoEstudiantes(Estudiante *estudiantes, int tamanoVectorEstudiantes){
    FILE *archivoEstudiantesEstudiantes = fopen("data/estudiantes.bat", "wb"); //Modifica todo el archivoEstudiantes en binario, cargando y actualizando todo el vector
    if(archivoEstudiantesEstudiantes == NULL){
        perror("Error al abrir el archivoEstudiantes");
        exit(EXIT_FAILURE);
    }
    fwrite(estudiantes, sizeof(Estudiante), tamanoVectorEstudiantes, archivoEstudiantesEstudiantes);
    fclose(archivoEstudiantesEstudiantes);
}

void leerArchvivosEstudiantes(Estudiante *estudiantes, int *tamanoVectorEstudiantes) {
    FILE *archivoEstudiantes = fopen("data/estudiantes.bat", "rb"); // Lee el archivo en binario
    if (archivoEstudiantes == NULL) {
        perror("Error al abrir el archivo de estudiantes");
        exit(EXIT_FAILURE);
    }

    *tamanoVectorEstudiantes = 0; // Inicializa el contador
    while (*tamanoVectorEstudiantes < MAXESTUDIANTES && fread(&estudiantes[*tamanoVectorEstudiantes], sizeof(Estudiante), 1, archivoEstudiantes)) {
        (*tamanoVectorEstudiantes)++;
    }
}

void eliminarEstudiante(Estudiante *estudiantes, int *tamanoVectorEstudiantes, int idEstudiante) {
    int poscionEstudianteEliminar = -1;

    for (int contador = 0; contador < *tamanoVectorEstudiantes; contador++) {
        if (estudiantes[contador].id == idEstudiante) {
            poscionEstudianteEliminar = contador; 
            break;
        }
    }

    if (poscionEstudianteEliminar != -1) {
        for (int contador = poscionEstudianteEliminar; contador < *tamanoVectorEstudiantes - 1; contador++) {
            estudiantes[contador] = estudiantes[contador + 1];
        }
        (*tamanoVectorEstudiantes)--;
        printf("Estudiante con ID %d eliminado exitosamente.\n", idEstudiante);
    } else {
        printf("Estudiante con ID %d no encontrado.\n", idEstudiante);
    }
}

void mostrarCalificacion();

void generarBoletin();


void menuPrincipalEstudiante(){
    Estudiante estudiantes[MAXESTUDIANTES];
    int tamanoVectorEstudiantes = 0;
    int opcion = 1;
    int validarId;

    leerArchvivosEstudiantes(estudiantes, &tamanoVectorEstudiantes);

    while(opcion != 0){
        printf("\nMenu Principal Estudiante\n");
        printf("1. Crear Estudiante\n");
        printf("2. Mostrar Estudiantes\n");
        printf("3. Modificar Estudiante\n");
        printf("4. Eliminar Estudiante\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                if (tamanoVectorEstudiantes < MAXESTUDIANTES) {
                    Estudiante estudiante = crearEstudiante();
                    estudiantes[tamanoVectorEstudiantes] = estudiante;
                    tamanoVectorEstudiantes++;
                    guardararchivoEstudiantes(estudiantes, tamanoVectorEstudiantes);
                } else {
                    printf("El máximo número de estudiantes ha sido alcanzado.\n");
                }
                break;
            case 2:
                for (int contador = 0; contador < tamanoVectorEstudiantes; contador++){
                    printf("\nEstudiante %d:\n", contador);
                    mostrarEstudiante(estudiantes[contador]);
                }
                break;
            case 3:
                printf("\nIngrese el ID del estudiante a modificar: ");
                scanf("%d", &validarId);
                for(int contador = 0; contador < tamanoVectorEstudiantes; contador++){
                    if(validarId != estudiantes[contador].id){
                        printf("\nEl ID ingresado no corresponde a ningun estudiante!\n");
                        break;
                    }else if(validarId == estudiantes[contador].id){
                        printf("\nEstudiante encontrado!\n");
                        estudiantes[contador] = actualizarEstudiante(estudiantes, contador);
                    }
                }
                break;
            case 4:
                printf("\nIngrese el ID del estudiante a eliminar: ");
                scanf("%d", &validarId);
                for(int contador = 0; contador < tamanoVectorEstudiantes; contador++){
                    if(validarId != estudiantes[contador].id){
                        printf("\nEl ID ingresado no corresponde a ningun estudiante!\n");
                        break;
                    }else if(validarId == estudiantes[contador].id){
                        printf("\nEstudiante encontrado!\n");
                        eliminarEstudiante(estudiantes, &tamanoVectorEstudiantes, validarId);
                        break;
                    }
                }
                break;
            case 0:
                printf("\nHas salido del menu de estudiante\n");
                break;
            default:
                break;
        }
    }
}

#endif