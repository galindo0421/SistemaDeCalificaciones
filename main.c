#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "login.h"

int main(){
    FILE *archivoEstudiantes = fopen("data/estudiante.txt", "r");
    if (archivoEstudiantes == NULL) {
        printf("Error al abrir el archivo de estudiantes\n");
        return 1;
    }
    //Estudiante *estudiantes;
    //saludoBienvenida();
    //manejarLogin();
    //menuEstudiante(estudiantes);
    return 0;
}
