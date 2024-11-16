#ifndef CALIFICACION_H
#define CALIFICACION_H
#include "estudiante.h"
#include "docente.h"

typedef struct {
    int id;
    Estudiante estudianteId;
    Docente docenteId;
    int asignaturaId;
    float calificacion;
} Calificacion;

void crearCalificacion();
void actualizarCalificacion();
void mostrarCalificacion();
void eliminarCalificacion();

#endif