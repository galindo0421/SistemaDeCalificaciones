#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

typedef struct{
    int id;
    char nombre[50];
    char contrasena[50];
    char apellido[50];
} Docente;

void crearCalificacion();
void actualizarCalificacion();
void mostrarCalificacion();
void eliminarCalificacion();
#endif