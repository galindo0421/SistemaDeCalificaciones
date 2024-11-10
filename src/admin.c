#include <stdio.h>
#include "admin.h"
#include "docente.h"
#include "estudiante.h"
#include "curso.h"
#include "materia.h"

void adminMenu() {
    int opcion;
    do {
        printf("\nMenú Admin\n");
        printf("1. Gestionar Estudiantes\n");
        printf("2. Gestionar Docentes\n");
        printf("3. Gestionar Cursos\n");
        printf("4. Gestionar Materias\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                gestionarEstudiantes();
                break;
            case 2:
                gestionarDocentes();
                break;
            case 3:
                gestionarCursos();
                break;
            case 4:
                gestionarMaterias();
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while(opcion != 5);
}

void gestionarEstudiantes() {
    int opcion;
    do {
        printf("\nGestionar Estudiantes\n");
        printf("1. Crear Estudiante\n");
        printf("2. Leer Estudiantes\n");
        printf("3. Actualizar Estudiante\n");
        printf("4. Eliminar Estudiante\n");
        printf("5. Regresar\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                createEstudiante();
                break;
            case 2:
                readEstudiantes();
                break;
            case 3:
                updateEstudiante();
                break;
            case 4:
                deleteEstudiante();
                break;
            case 5:
                printf("Regresando...\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while(opcion != 5);
}

void gestionarDocentes() {
    int opcion;
    do {
        printf("\nGestionar Docentes\n");
        printf("1. Crear Docente\n");
        printf("2. Leer Docentes\n");
        printf("3. Actualizar Docente\n");
        printf("4. Eliminar Docente\n");
        printf("5. Regresar\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                createDocente();
                break;
            case 2:
                readDocentes();
                break;
            case 3:
                updateDocente();
                break;
            case 4:
                deleteDocente();
                break;
            case 5:
                printf("Regresando...\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while(opcion != 5);
}

void gestionarCursos() {
    int opcion;
    do {
        printf("\nGestionar Cursos\n");
        printf("1. Crear Curso\n");
        printf("2. Leer Cursos\n");
        printf("3. Actualizar Curso\n");
        printf("4. Eliminar Curso\n");
        printf("5. Regresar\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                createCurso();
                break;
            case 2:
                readCursos();
                break;
            case 3:
                updateCurso();
                break;
            case 4:
                deleteCurso();
                break;
            case 5:
                printf("Regresando...\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while(opcion != 5);
}

void gestionarMaterias() {
    int opcion;
    do {
        printf("\nGestionar Materias\n");
        printf("1. Crear Materia\n");
        printf("2. Leer Materias\n");
        printf("3. Actualizar Materia\n");
        printf("4. Eliminar Materia\n");
        printf("5. Regresar\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                createMateria();
                break;
            case 2:
                readMaterias();
                break;
            case 3:
                updateMateria();
                break;
            case 4:
                deleteMateria();
                break;
            case 5:
                printf("Regresando...\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while(opcion != 5);
}
