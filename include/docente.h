#ifndef DOCENTE_H
#define DOCENTE_H

typedef struct { int id; char nombre[50]; char asignatura[50]; char contrasena[50]; } Docente;

#include "sistema.h"

void menuDocente();
void verNotasEstudiantes();
void agregarNota();

#endif
