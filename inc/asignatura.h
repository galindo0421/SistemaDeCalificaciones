#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include "docente.h"

typedef struct {
    char nombre[50];
    Docente docente;
} Asignatura;

void crearAsignatura();
void actualizarAsignatura();
void mostrarAsignatura();
void eliminarAsignatura();

#endif