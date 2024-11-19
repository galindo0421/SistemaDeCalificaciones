#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "asignatura.h"
#include <stdio.h>

typedef struct{
    int id;
    char nombre[50];
    char apellido[50];
    char contrasena[50];
    Asignatura asignaturas[6];
} Estudiante;

void menuEstudiante(){
    printf("\nMenu Estudiante\n");
    printf("1. Crear estudiante\n");
    printf("2. Actualizar estudiante\n");
    printf("3. Mostrar estudiante\n");
    printf("4. Eliminar estudiante\n");
    printf("5. Mostrar calificacion\n");
    printf("6. Generar boletin\n");
    printf("0. Salir\n");
    printf("Seleccione una opcion: ");
}
Estudiante crearEstudiante(){
    Estudiante estudiante;
    printf("\nIngrese el ID de estudiante: \n");
    scanf("%d", &estudiante.id);
    printf("Ingrese el nombre del estudiante: \n");
    scanf("%s", estudiante.nombre);
    printf("Ingrese el apellido del estudiante: \n");
    scanf("%s", estudiante.apellido);
    printf("Ingrese la contraseña del estudiante: \n");
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
Estudiante actualizarEstudiante(Estudiante estudiante){ 
    int opcion = 1;    
    while (opcion != 0){
        menuActualizarEstudiante();
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Ingrese el nuevo ID de estudiante: \n");
            scanf("%d", &estudiante.id);
            printf("ID actualizado exitosamente.\n");
            break;
        case 2:
            printf("Ingrese el nuevo nombre del estudiante: \n");
            scanf("%s", estudiante.nombre);
            printf("Nombre actualizado exitosamente.\n");
            break;
        case 3:
            printf("Ingrese el nuevo apellido del estudiante: \n");
            scanf("%s", estudiante.apellido);
            printf("Apellido actualizado exitosamente.\n");
            break;
        case 4:
            printf("Ingrese la nueva contraseña del estudiante: \n");
            scanf("%s", estudiante.contrasena);
            printf("Contraseña actualizada exitosamente.\n");
        case 0:
            printf("\nHas salido del menu de crear estudiante\n");
            break;
        default:
            break;
        }
    }
    return estudiante;
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

#endif