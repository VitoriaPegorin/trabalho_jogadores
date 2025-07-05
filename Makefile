CC = gcc
TARGET = trabalho
SOURCE = ./src
INCLUDE = ./include
OBJETOS = ./objs

all: obj
	$(CC) $(OBJETOS)/utils.o $(OBJETOS)/menus.o $(OBJETOS)/arquivo.o $(OBJETOS)/cadastro.o $(OBJETOS)/relatorios.o $(OBJETOS)/consultas.o $(OBJETOS)/main.o -o $(TARGET)


obj:
	$(CC) -c $(SOURCE)/utils.c -o $(OBJETOS)/utils.o
	$(CC) -c $(SOURCE)/menus.c -o $(OBJETOS)/menus.o
	$(CC) -c $(SOURCE)/arquivo.c -o $(OBJETOS)/arquivo.o
	$(CC) -c $(SOURCE)/cadastro.c -o $(OBJETOS)/cadastro.o
	$(CC) -c $(SOURCE)/relatorios.c -o $(OBJETOS)/relatorios.o
	$(CC) -c $(SOURCE)/consultas.c -o $(OBJETOS)/consultas.o
	$(CC) -c main.c -o $(OBJETOS)/main.o


clear:
	rm $(TARGET)
	rm $(OBJETOS)/*.o

