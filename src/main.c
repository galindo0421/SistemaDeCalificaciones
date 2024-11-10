#include <stdio.h>
#include "admin.h"
#include "docente.h"
#include "estudiante.h"
#include "sistema.h"

int main() {
    char nombreUsuario[50], contrasena[50];
    int tipoUsuario;

    printf("Ingrese su nombre de usuario: ");
    scanf("%s", nombreUsuario);
    printf("Ingrese su contraseña: ");
    scanf("%s", contrasena);

    tipoUsuario = login(nombreUsuario, contrasena);

    if (tipoUsuario == 1) {
        menuAdmin();
    } else if (tipoUsuario == 2) {
        menuDocente();
    } else if (tipoUsuario == 3) {
        menuEstudiante();
    } else {
        printf("Login fallido\n");
    }

    return 0;
}
