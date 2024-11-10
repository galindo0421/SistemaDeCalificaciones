#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "docente.h"
#include "estudiante.h"

Admin admin = {1, "admin", "adminpass"};
Docente docente = {1, "docente", "Math", "docentepass"};
Estudiante estudiante = {1, "estudiante", 0.0, "estudianterpass"};

void login(char *nombreUsuario, char *contrasena);
void adminMenu();
void docenteMenu();
void estudianteMenu();

int main() {
    char nombreUsuario[50];
    char contrasena[50];

    printf("Ingrese nombre de usuario: ");
    scanf("%s", nombreUsuario);
    printf("Ingrese contraseña: ");
    scanf("%s", contrasena);

    login(nombreUsuario, contrasena);
    return 0;
}

void login(char *nombreUsuario, char *contrasena) {
    if (strcmp(nombreUsuario, admin.nombre) == 0 && strcmp(contrasena, admin.contrasena) == 0) {
        printf("Inicio de sesión exitoso como Admin\n");
        adminMenu();
    } else if (strcmp(nombreUsuario, docente.nombre) == 0 && strcmp(contrasena, docente.contrasena) == 0) {
        printf("Inicio de sesión exitoso como Docente\n");
        docenteMenu();
    } else if (strcmp(nombreUsuario, estudiante.nombre) == 0 && strcmp(contrasena, estudiante.contrasena) == 0) {
        printf("Inicio de sesión exitoso como Estudiante\n");
        estudianteMenu();
    } else {
        printf("Nombre de usuario o contraseña incorrectos\n");
        login(nombreUsuario, contrasena);
    }
}

void adminMenu() {
    printf("Bienvenido Admin!\n");
    // Aquí irían las funcionalidades del admin
}

void docenteMenu() {
    printf("Bienvenido Docente!\n");
    // Aquí irían las funcionalidades del docente
}

void estudianteMenu() {
    printf("Bienvenido Estudiante!\n");
    // Aquí irían las funcionalidades del estudiante
}
