#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "curso.h"

typedef struct{
    int id;
    char nombre[50];
    char contrasena[50];
    char apellido[50];
    Curso curso;
} Estudiante;

void crearEstudiante();
void actualizarEstudiante();
void mostrarEstudiante();
void eliminarEstudiante();
void mostrarCalificacion();
void generarBoletin();

#endif