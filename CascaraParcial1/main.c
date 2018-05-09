#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 50
#define CANT 500

int main()
{
    char seguir='s';
    int opcion=0;
    Producto prove [TAM];
    Producto produ [CANT];
    inicializador(prove,TAM);
    inicializadorProduc (produ,CANT);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar \n");
        printf("2- Modificar \n");
        printf("3- Borrar\n");
        printf("4- Informar\n");
        printf("5- Listar\n");
        printf("6- Salir\n");

        printf("\n\nIndique opcion:");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarProducto(produ, CANT);
                system("pause");
                //agregar
                    break;
            case 2:
                system("cls");
                modificarProducto(produ, CANT);
                system("pause");
                //borrar
                break;
            case 3:
                system("cls");
                eliminarProducto(produ,CANT);
                system("pause");
                //imprimir lista
                break;
            case 4:
                system("cls");
                informar (produ,TAM,CANT);
                system("pause");
                break;
            case 5:
                system("cls");
                listar(produ,TAM,CANT);
                system("pause");
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                printf("Ingrese una opcion que este dentro del menu");
                break;

        }
    }

    return 0;
}
