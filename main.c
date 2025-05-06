#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define DIMENSION 40


typedef struct {
    int matricula;
    char nombre[30];
    char genero[30];
} stAlumno;

int cargarAlumnos(stAlumno arr[], int validos);void mostrarArreglo(stAlumno arr[], int validos);
void buscarPorMatricula(stAlumno arr[], int validos);
int encontrarMenorPos(int pos, int validos, stAlumno arr[]);
void ordenarSeleccion(stAlumno arr[], int validos);

int main()
{
    char seguir = 's';
    int cantAlumnos;
    int ejercicio;
    stAlumno arr[DIMENSION];

    while(seguir == 's'){
    printf("Ejercicio a ejecutar: ");
    scanf("%i", &ejercicio);
    system("cls");
        switch(ejercicio){
        case 1:
            cantAlumnos = cargarAlumnos(arr, DIMENSION);
            break;
        case 2:
            mostrarArreglo(arr, cantAlumnos);
            break;
        case 3:
            buscarPorMatricula(arr, cantAlumnos);
            break;
        case 4:
            ordenarSeleccion(arr, cantAlumnos);
            mostrarArreglo(arr, cantAlumnos);
            break;
        }

    printf("\n Deseas ejecutar otro ejercicio? (s/n): ");
    fflush(stdin);
    scanf("%c", &seguir);
    }




 return 0;
}

int cargarAlumnos(stAlumno arr[], int validos){
    char seguir = 's';
    int i = 0;
    while(seguir == 's' && i < validos){
        printf("\n Ingrese matricula: ");
        fflush(stdin);
        scanf("%i", &arr[i].matricula);

        printf("\n Ingrese nombre: ");
        fflush(stdin);
        scanf("%s", &arr[i].nombre);

        printf("\n Ingrese el genero: ");
        fflush(stdin);
        scanf("%s", &arr[i].genero);

        printf("Deseas continuar?: (s/n) ");
        fflush(stdin);
        scanf("%c", &seguir);

        i++;
    }

    return i;
}

void mostrarArreglo(stAlumno arr[], int validos){

    for(int j = 0; j < validos; j++){
        printf("\n\n [Matricula: %i|", arr[j].matricula);
        printf("\n |Nombre: %s|", arr[j].nombre);
        printf("\n |Genero: %s]", arr[j].genero);
    }
}


void buscarPorMatricula(stAlumno arr[], int validos){
    char opcion = 's';
    int matricula;
    int flag = 0;
    char nombre[30];

    while(opcion == 's'){
        printf("Ingrese matricula: ");
        scanf("%i", &matricula);
        for(int i = 0; i < validos; i++){
            if(arr[i].matricula == matricula){
                flag = 1;
                strcpy(nombre, arr[i].nombre);
            }
        }
       if(flag == 1){
         printf("Alumno con matricula: %i Encontrado! \n Nombre: %s", matricula, nombre);
       } else if (flag == 0){
        printf("Alumno con matricula: %i No fue encontrado :(", matricula);
       }

       printf("\n Deseas buscar otra matricula? (s/n): ");
       fflush(stdin);
       scanf("%c", opcion);
    }
}

int encontrarMenorPos(int pos, int validos, stAlumno arr[]){
    int posMenor = pos;
    stAlumno menor = arr[pos];

    for(int i = pos; i < validos; i++){
        if(arr[i].matricula < menor.matricula){
            posMenor = i;
            menor = arr[i];
        }
    }
    return posMenor;
}


void ordenarSeleccion(stAlumno arr[], int validos){
    int i = 0;
    int posMenor;
    stAlumno aux;

    while(i < validos - 1){
        posMenor = encontrarMenorPos(i, validos, arr);
        printf("\nPosmenor: %i", posMenor);
        aux = arr[i];
        arr[i] = arr[posMenor];
        arr[posMenor] = aux;
        i++;
    }
}
