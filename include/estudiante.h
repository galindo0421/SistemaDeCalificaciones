#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

typedef struct{
    int id;
    char nombre[50];
    char contrasena[50];
} Estudiante;

void mostrarCalificacion();
void generarBoletin();
#endif