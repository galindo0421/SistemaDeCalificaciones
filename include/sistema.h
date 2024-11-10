#ifndef SISTEMA_H
#define SISTEMA_H

typedef struct {
    char nombreUsuario[50];
    char contrasena[50];
    int tipoUsuario;
} Usuario;

int login(char *nombreUsuario, char *contrasena);
void cargarDatos();  // Función para cargar los datos desde db.txt
void menuDocente();
void menuEstudiante();

#endif
