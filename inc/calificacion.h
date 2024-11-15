#ifndef CALIFICACIONES_H
#define CALIFICACIONES_H

typedef struct {
    int id;
    int estudiante_id;
    int docente_id;
    int asignatura_id;
    float calificacion;
} Calificacion;

void crearCalificacion();
void actualizarCalificacion();
void mostrarCalificacion();
void eliminarCalificacion();

#endif