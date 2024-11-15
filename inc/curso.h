#ifndef CURSO_H
#define CURSO_H
#include "asignatura.h"

typedef struct {
    int id;
    char nombre;
    Asignatura asignaturas[50];
} Curso;

void crearCurso();
void actualizarCurso();
void mostrarCurso();
void eliminarCurso();

#endif