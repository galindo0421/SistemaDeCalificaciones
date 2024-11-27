#ifndef DOCENTE_H
#define DOCENTE_H
#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"
#include "asignatura.h"

typedef struct {
    int id;
    char nombre[50];
    char apellido[50];
    char contrasena[50];
    Asignatura asignaturas[6];
} Docente;

// Definición de las funciones de docente:
Docente crearUsuarioDocente();
void mostrarDocente(Docente docente);
void menuActualizarDocente();
Docente actualizarDatosDocente(Docente *docentes, int tamanoVector);
void guardararchivoDocentes(Docente *docentes, int tamanoVectorDocentes);
void leerArchvivosDocentes(Docente *docentes, int *tamanoVectorDocentes);
void eliminarUsuarioDocente(Docente *docentes, int *tamanoVectorDocentes, int idDocente);
void menuPrincipalDocente();

// Inicialización de las funciones:
Docente crearUsuarioDocente(){
    Docente docente;
    printf("\nIngrese ID del docente: ");
    scanf("%d", &docente.id);
    printf("\nIngrese nombre del docente: ");
    scanf("%s", docente.nombre);
    printf("\nIngrese apellido del docente: ");
    scanf("%s", docente.apellido);
    printf("\nIngrese la contrasena del docente: ");
    scanf("%s", docente.contrasena);
    printf("\nDocente creado exitosamente.\n");
    return docente;
}

void menuActualizarDocente(){
    printf("\nMenu para actualizar datos de un docente\n");
    printf("\n1. Actualizar ID");
    printf("\n2. Actualizar nombre");
    printf("\n3. Actualizar apellido");
    printf("\n4. Actualizar contrasena");
    printf("\n0. Salir\n");
    printf("\nSeleccione una opcion: ");
}

Docente actualizarDatosDocente(Docente *docente, int tamanoVector){
    int opcion = 1;    
    while (opcion != 0){
        menuActualizarDocente();
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Actualice ID de docente:");
            scanf("%d", &docente[tamanoVector].id);
            printf("ID actualizado exitosamente.\n");
            break;
        case 2:
            printf("Actualice nombre del docente:");
            scanf("%s", docente[tamanoVector].nombre);
            printf("Nombre actualizado exitosamente.\n");
            break;
        case 3:
            printf("Actualice apellido del docente:");
            scanf("%s", docente[tamanoVector].apellido);
            printf("Apellido actualizado exitosamente.\n");
            break;
        case 4:
            printf("Actualice la contraseña del docente:");
            scanf("%s", docente[tamanoVector].contrasena);
            printf("Contraseña actualizada exitosamente.\n");
        case 5:
            break;
        case 0:
            printf("\nHas salido del menu para actualizar datos de un docente\n");
            break;
        default:
            break;
        }
    }
    return docente[tamanoVector];
}

void mostrarDocente(Docente docente){
    printf("\nID: %d", docente.id);
    printf("\nNombre: %s", docente.nombre);
    printf("\nApellido: %s", docente.apellido);
    printf("\nContrasena: %s", docente.contrasena);
}

void guardarArchivosDocentes(Docente *docente, int tamanoVectorDocentes){
    FILE *archivoDocentesDocentes = fopen("data/docentes.bat", "wb"); 
    if(archivoDocentesDocentes == NULL){
        perror("Error al abrir archivo Docentes");
        exit(EXIT_FAILURE);
    }
    fwrite(docente, sizeof(Docente), tamanoVectorDocentes, archivoDocentesDocentes);
    fclose(archivoDocentesDocentes);
}

void leerArchvivosDocentes(Docente *docente, int *tamanoVectorDocentes){
    FILE *archivoDocentes = fopen("data/docentes.bat", "rb");
    if (archivoDocentes == NULL) {
        perror("Error al abrir archivo de docentes");
        exit(EXIT_FAILURE);
    }

    *tamanoVectorDocentes = 0; // Inicializa el contador
    while (*tamanoVectorDocentes < MAXDOCENTES && fread(&docente[*tamanoVectorDocentes], sizeof(Docente), 1, archivoDocentes)) {
        (*tamanoVectorDocentes)++;
    }
}

void eliminarUsuarioDocente(Docente *docentes, int *tamanoVectorDocentes, int idDocente){
    int posicionDocenteEliminar = -1;

    for (int contador = 0; contador < *tamanoVectorDocentes; contador++){
        if (docentes[contador].id == idDocente){
            posicionDocenteEliminar = contador; 
            break;
        }
    }

    if (posicionDocenteEliminar != -1) {
        for (int contador = posicionDocenteEliminar; contador < *tamanoVectorDocentes - 1; contador++){
            docentes[contador] = docentes[contador + 1];
        }
        (*tamanoVectorDocentes)--;
        printf("El docente con ID %d, ha sido eliminado exitosamente.\n", idDocente);
    } else {
        printf("El docente con ID %d, no ha sido encontrado.\n", idDocente);
    }
}

void menuPrincipalDocente(){
    Docente docente[MAXDOCENTES];
    int tamanoVectorDocentes = 0;
    int opcion = 1;
    int validarId;

    leerArchvivosDocentes(docente, &tamanoVectorDocentes);

    while(opcion != 0){
        printf("\n--- Menu CRUD de Docentes ---\n");
        printf("\n1. Crear usuario de docente");
        printf("\n2. Filtrar un docente");
        printf("\n3. Actualizar datos de un docente");
        printf("\n4. Eliminar usuario de docente");
        printf("\n0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                if (tamanoVectorDocentes < MAXDOCENTES){
                    Docente docentes = crearUsuarioDocente();
                    docente[tamanoVectorDocentes] = docentes;
                    tamanoVectorDocentes++;
                    guardarArchivosDocentes(docente, tamanoVectorDocentes);
                    printf("\nEl usuario del docente fue creado exitosamente.\n");
                } else {
                    printf("\nCapacidad maxima alcanzada. No se pueden crear mas usuarios para docentes.\n");
                }
                break;
            case 2:
                for (int contador = 0; contador < tamanoVectorDocentes; contador++){
                    printf("\nDocente %d:\n", contador);
                    mostrarDocente(docente[contador]);
                }
                break;
            case 3:
                printf("\nIngrese ID del docente a modificar: ");
                scanf("%d", &validarId);
                for(int contador = 0; contador < tamanoVectorDocentes; contador++){
                    if(validarId != docente[contador].id){
                        printf("\nEl ID ingresado no corresponde a ningun docente!\n");
                        break;
                    }else if(validarId == docente[contador].id){
                        printf("\ndocente encontrado!\n");
                        docente[contador] = actualizarDatosDocente(docente, contador);
                    }
                }
                break;
            case 4:
                printf("\nIngrese ID del docente a eliminar: ");
                scanf("%d", &validarId);
                for(int contador = 0; contador < tamanoVectorDocentes; contador++){
                    if(validarId != docente[contador].id){
                        printf("\nEl ID ingresado no corresponde a ningun docente!\n");
                        break;
                    }else if(validarId == docente[contador].id){
                        printf("\nEl docente ha sido encontrado en la base de datos!\n");
                        eliminarUsuarioDocente(docente, &tamanoVectorDocentes, validarId);
                        break;
                    }
                }
            case 0:
                printf("\nSaliendo...\n");
                Sleep(2000);
                break;
            default:
                printf("\nOpcion invalida. Intente nuevamente.\n");
                break;
        }
    }
}

#endif