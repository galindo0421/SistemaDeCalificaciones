#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include "docente.h"
#include "calificacion.h"

typedef struct {
    char nombre[50];
    Docente docente;
    Calificacion calificaciones[50];
} Asignatura;

void crearAsignatura();
void actualizarAsignatura();
void mostrarAsignatura();
void eliminarAsignatura();

#endif