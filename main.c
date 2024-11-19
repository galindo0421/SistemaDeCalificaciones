#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "login.h"

int main() {
    //saludoBienvenida();
    //manejarLogin();
    menuEstudiante();
    Estudiante estudiante[2];
    estudiante[0] = crearEstudiante();
    actualizarEstudiante(estudiante[0]);
    return 0;
}
