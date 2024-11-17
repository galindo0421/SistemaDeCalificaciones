#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "asignatura.h"

typedef struct{
    int id;
    char nombre[50];
    char apellido[50];
    char contrasena[50];
} Estudiante;


void menuEstudiante();
void crearEstudiante();
void actualizarEstudiante();
void mostrarEstudiante();
void eliminarEstudiante();
void mostrarCalificacion();
void generarBoletin();

#endif