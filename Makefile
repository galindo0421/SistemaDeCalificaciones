CC = gcc
CFLAGS = -Wall -g -Iinclude
OBJ_DIR = obj
SRC_DIR = src
TARGET = program

# Archivos fuente
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/admin.c $(SRC_DIR)/docente.c $(SRC_DIR)/estudiante.c $(SRC_DIR)/sistema.c $(SRC_DIR)/curso.c $(SRC_DIR)/materia.c

# Archivos objeto
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Regla por defecto
all: $(TARGET)

# Regla para crear el ejecutable
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

# Regla para compilar los archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Crear el directorio obj si no existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
	rmdir $(OBJ_DIR) || true  # Ignorar error si el directorio no existe
