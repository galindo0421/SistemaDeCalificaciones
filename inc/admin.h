#ifndef ADMIN_H
#define ADMIN_H

typedef struct {
    int id;
    char nombre[50];
    char contrasena[50];
} Admin;

void menuCrud();
void menuPrincipalAdmin();
void menuGestionAdmin();
void crearAdmin();
void leerAdmin();
void actualizarAdmin();
void eliminarAdmin();
void cerrarSesion();
#endif
