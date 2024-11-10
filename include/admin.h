#ifndef ADMIN_H
#define ADMIN_H

typedef struct { int id; char nombre[50]; char contrasena[50]; } Admin;

void menuAdmin(); // Prototipo de la función
void agregarUsuario();
void agregarCurso();
void agregarMateria();
void verUsuarios();

#endif // ADMIN_H
