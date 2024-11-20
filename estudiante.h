#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "asignatura.h"
#include <stdio.h>
#include "utilidades.h"
#include <stdlib.h>

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
        case 5:
            /*printf("Ingrese el nuevo nombre de asignatura: \n");
            scanf("%d", &estudiante.asignaturas[0].nombre);
            printf("Nombre de asignatura actualizado exitosamente.\n");
            break;*/
        case 6:
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

void eliminarEstudiante();

void mostrarCalificacion();

void generarBoletin();

void menuEstudiante(Estudiante *estudiantes){
    int tamanoVector = sizeof(estudiantes)/sizeof(estudiantes[0]);
    int posicionVector = 0;
    int opcion = 1;
    int validarId;
    
    while(opcion != 0){
        printf("\nMenu Estudiante\n");
        printf("1. Crear estudiante\n");
        printf("2. Actualizar estudiante\n");
        printf("3. Mostrar estudiante\n");
        printf("4. Eliminar estudiante\n");
        printf("5. Mostrar calificacion\n");
        printf("6. Generar boletin\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                if(sizeof(estudiantes)/sizeof(estudiantes[0]) == tamanoVector){
                    estudiantes = malloc((tamanoVector+1) * sizeof(estudiantes));
                }
                Estudiante estudiante;
                estudiante = crearEstudiante();
                estudiantes[posicionVector] = estudiante;
                posicionVector++;
                tamanoVector++;
                break;
            case 2:
                printf("\nIngrese el ID del estudiante a modificar: ");
                scanf("%d", &validarId);
                for(int contador = 0; contador < tamanoVector; contador++){
                    if(validarId != estudiantes[contador].id){
                        printf("\nEl ID ingresado no corresponde a ningun estudiante!\n");
                        return;
                    }else if(validarId == estudiantes[contador].id){
                        printf("\nEstudiante encontrado!\n");
                        printf("%d", contador);
                        estudiantes[contador] = actualizarEstudiante(estudiantes, contador);
                    }
                }
                break;
            case 3:
            for (int contador = 0; contador < posicionVector; contador++){
                printf("\nEstudiante %d:\n", contador);
                mostrarEstudiante(estudiantes[contador]);
            }
                break;
            case 4:
                //eliminarEstudiante();
                break;
            case 5:
                //mostrarCalificacion();
                break;
            case 6:
                //generarBoletin();
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