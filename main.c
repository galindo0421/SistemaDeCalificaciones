#include <stdio.h>
#include "inicio.h"
#include <string.h>
#include <stdbool.h>
#include "utilidades.h"
#include "admin.h"
#include "estudiante.h"

Menu option;
int totalAdmins = 0; // Variables globales

// Declaración de funciones
Menu menuPrincipal();

int main(){  
    option = menuPrincipal(); // Llamar a la función de menu principal
    return 0;
}




