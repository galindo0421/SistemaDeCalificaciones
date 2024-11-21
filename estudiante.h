#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
/*
#include "asignatura.h"
#include <stdio.h>
#include "utilidades.h"
#include <stdlib.h>

typedef struct{
    char tipo[10];
    int id;
    char nombre[50];
    char apellido[50];
    char contraseña[50];
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
    printf("Ingrese la contraseña del estudiante: \n");
    scanf("%s", estudiante.contraseña);
    printf("\nEstudiante creado exitosamente.\n");
    return estudiante;  
}

void menuActualizarEstudiante(){
    printf("\nMenu para actualizar datos de un estudiante\n");
    printf("1. Cambiar ID\n");
    printf("2. Cambiar nombre\n");
    printf("3. Cambiar apellido\n");
    printf("4. Cambiar contraseña\n");
    printf("0. Salir\n");
    printf("Seleccione una opción: ");
}

Estudiante actualizarEstudiante(Estudiante *estudiantes, int tamañoVector){
    int opción = 1;    
    while (opción != 0){
        menuActualizarEstudiante();
        scanf("%d", &opción);
        switch (opción){
        case 1:
            printf("Ingrese el nuevo ID de estudiante:");
            scanf("%d", &estudiantes[tamañoVector].id);
            printf("ID actualizado exitosamente.\n");
            break;  
        case 2:
            printf("Ingrese el nuevo nombre del estudiante:");
            scanf("%s", estudiantes[tamañoVector].nombre);
            printf("Nombre actualizado exitosamente.\n");
            break;
        case 3:
            printf("Ingrese el nuevo apellido del estudiante:");
            scanf("%s", estudiantes[tamañoVector].apellido);
            printf("Apellido actualizado exitosamente.\n");
            break;
        case 4:
            printf("Ingrese la nueva contraseña del estudiante:");
            scanf("%s", estudiantes[tamañoVector].contraseña);
            printf("Contraseña actualizada exitosamente.\n");
        case 5:
            printf("Ingrese el nuevo nombre de asignatura: \n");
            scanf("%d", &estudiante.asignaturas[0].nombre);
            printf("Nombre de asignatura actualizado exitosamente.\n");
            break;
        case 6:
            printf("Ingrese la nueva calificación de asignatura: \n");
            scanf("%f", &estudiante.asignaturas[0].calificaciones[0]);
            printf("Calificación actualizada correctamente\n");
        case 0:
            printf("\nHas salido del menu de crear estudiante\n");
            break;
        default:
            break;
        }
    }
    return estudiantes[tamañoVector];
}

void mostrarEstudiante(Estudiante estudiante){
    printf("\nID: %d\n", estudiante.id);
    printf("Nombre: %s\n", estudiante.nombre);
    printf("Apellido: %s\n", estudiante.apellido);
    printf("Contraseña: %s\n", estudiante.contraseña);
}

void eliminarEstudiante();

void mostrarCalificación();

void generarBoletín();

void menuEstudiante(Estudiante *estudiantes){
    int tamañoVector = sizeof(estudiantes)/sizeof(estudiantes[0]);
    int posiciónVector = 0;
    int opción = 1;
    int validarId;
    
    while(opción != 0){
        printf("\nMenu Estudiante\n");
        printf("1. Crear estudiante\n");
        printf("2. Actualizar estudiante\n");
        printf("3. Mostrar estudiante\n");
        printf("4. Eliminar estudiante\n");
        printf("5. Mostrar calificación\n");
        printf("6. Generar boletín\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opción);
        switch (opción){
            case 1:
                if(sizeof(estudiantes)/sizeof(estudiantes[0]) == tamañoVector){
                    estudiantes = malloc((tamañoVector+1) * sizeof(estudiantes));
                }
                Estudiante estudiante;
                estudiante = crearEstudiante();
                estudiantes[posiciónVector] = estudiante;
                posiciónVector++;
                tamañoVector++;
                break;
            case 2:
                printf("\nIngrese el ID del estudiante a modificar: ");
                scanf("%d", &validarId);
                for(int contador = 0; contador < tamañoVector; contador++){
                    if(validarId != estudiantes[contador].id){
                        printf("\nEl ID ingresado no corresponde a ningún estudiante!\n");
                        return;
                    }else if(validarId == estudiantes[contador].id){
                        printf("\nEstudiante encontrado!\n");
                        printf("%d", contador);
                        estudiantes[contador] = actualizarEstudiante(estudiantes, contador);
                    }
                }
                break;
            case 3:
            for (int contador = 0; contador < posiciónVector; contador++){
                printf("\nEstudiante %d:\n", contador);
                mostrarEstudiante(estudiantes[contador]);
            }
                break;
            case 4:
                //eliminarEstudiante();
                break;
            case 5:
                //mostrarCalificación();
                break;
            case 6:
                //generarBoletín();
                break;
            case 0:
                printf("\nHas salido del menu de estudiante\n");
                break;
            default:
                break;
        }
    }
}
*/
#endif