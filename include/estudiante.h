#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "sistema.h"

typedef struct { int id; char nombre[50]; float grade; char contrasena[50]; } Estudiante;

void menuEstudiante();
void verBoletin();
void verCalificacionIndividual();

#endif
