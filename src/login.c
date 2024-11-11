#include <stdio.h>
#include <string.h>
#include "login.h"
#include "admin.h"

// Función para verificar si un usuario es administrador
int esAdmin(char *usuario, char *contrasena) {
    FILE *fp = fopen("db.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir la base de datos\n");
        return 0;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char tipo[10];
        Admin admin;
        sscanf(line, "%[^,],%d,%[^,],%[^,\n]", tipo, &admin.id, admin.nombre, admin.contrasena);
        if (strcmp(tipo, "Admin") == 0 && strcmp(admin.nombre, usuario) == 0 && strcmp(admin.contrasena, contrasena) == 0) {
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
