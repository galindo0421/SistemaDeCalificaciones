#ifndef ADMIN_H
#define ADMIN_H

typedef struct {
    int id;
    char nombre[50];
    char contrasena[50];
} Admin;

void menuAdmin();
void crearAdmin();

#endif // ADMIN_H
