#ifndef ADMIN_H
#define ADMIN_H

typedef struct {
    int id;
    char nombre[50];
    char contrasena[50];
    char apellido[50];
} Admin;

void menuAdmin();
void crearAdmin();
void leerAdmin();
void actualizarAdmin();
void eliminarAdmin();
void cerrarSesion();
#endif
