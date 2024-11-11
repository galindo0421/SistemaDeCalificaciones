#include <stdio.h>
#include <string.h>
#include "login.h"
#include "admin.h"
#include <errno.h>

// Función para verificar si un usuario es administrador
int esAdmin(char *usuario, char *contrasena) {
    // Validación de entrada
    if (usuario == NULL || contrasena == NULL) {
        printf("Usuario o contraseña no pueden ser nulos\n");
        return 0; // Entrada inválida
    }

    FILE *fp = fopen("data/admin.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir la base de datos: %s\n", strerror(errno)); // Mensaje de error mejorado
        return 0;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char tipo[10], id[10], nombre[50], password[50];
        sscanf(line, "Tipo:%[^;];ID:%[^;];Nombre:%[^;];Password:%[^;];", tipo, id, nombre, password);
        
        // Asegúrate de que la contraseña se lea correctamente
        nombre[strcspn(nombre, "\n")] = 0; // Eliminar salto de línea
        password[strcspn(password, "\n")] = 0; // Eliminar salto de línea
        
        if (strcmp(nombre, usuario) == 0 && strcmp(password, contrasena) == 0) {
            fclose(fp);
            return 1; // Admin encontrado
        }
    }
    fclose(fp);
    
    return 0; // Admin no encontrado
}

// Implementación de la función de login para administradores
int loginAdmin(char *usuario, char *contrasena) {
    if (esAdmin(usuario, contrasena)) {
        return 1; // Administrador
    } else {

        return 0; // Usuario no encontrado
    }
}
