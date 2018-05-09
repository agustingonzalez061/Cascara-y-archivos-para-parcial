#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
#define TAM 20

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona gente [TAM];
    inicializador(gente,TAM);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        printf("\n\nIndique opcion:");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPersona(gente,TAM);
                system("pause");
                //agregar
                break;
            case 2:
                system("cls");
                eliminarPersona(gente,TAM);
                system("pause");
                //borrar
                break;
            case 3:
                system("cls");
                ordenar(gente,TAM);
                mostrarPersonas(gente,TAM);
                system("pause");
                //imprimir lista
                break;
            case 4:
                barras (gente,TAM);
                //grafico edades
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Ingrese una opcion que este dentro del menu");
                break;

        }
    }

    return 0;
}
