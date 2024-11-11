#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "login.h"

int main() {
    char usuario[50];
    char contrasena[50];
    int tipoUsuario;

    printf("Ingrese su usuario: ");
    scanf("%s", usuario);
    printf("Ingrese su contraseña: ");
    scanf("%s", contrasena);

    tipoUsuario = loginAdmin(usuario, contrasena);

    if (tipoUsuario == 1) {
        printf("Bienvenido Administrador\n");
        menuAdmin();
    } else {
        printf("Usuario o contraseña incorrectos\n");
    }

    return 0;
}
