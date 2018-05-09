#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int validarDNI (char dni [])//operacion de carga de datos

{
    int i;
    long numero;
    for (i = 0; i < strlen(dni) ; i++)
    {
        if (!(isdigit(dni[i])))
        {
            printf("El DNI no es valida");
            return 0;
        }

    }
    numero = atol(dni);
    while( numero < 1 || numero > 99999999)
    {
        printf("El dni debe ser entre 1 y 99999999");
        return 0;
    }
    return numero;
}
int validarEdad (char edad [])//operacion de carga de datos
{
    int i;
    int numero;
    for (i = 0; i < strlen(edad) ; i++)
    {
        if (!(isdigit(edad[i])))
        {
            printf("La edad no es valida");
            return 0;
        }

    }
    numero = atoi(edad);
    while (numero <0 || numero > 120)
    {
        printf("La edad debe ser entre 0 y 120");
        return 0;
    }
    return numero;
}
int validarNombre (char nombre [])
{
    int i;
    int letras;
    letras = strlen(nombre);
    while(letras > 49)
    {
        printf("El nombre es demasiado largo");
        return 0;
    }
    for (i = 0; i < strlen(nombre) ; i++)
    {
        if (!(isalpha(nombre[i])))
        {
            printf("El nombre no es valido.");
            return 0;
        }

    }

    return 1;
}

void inicializador (EPersona vec [],int tam)
 {
     int i;
     for (i = 0 ; i< tam ; i++)
     {
         vec[i].estado = 0;
     }
 }
 int buscarLibre (EPersona vec[], int tam)
 {
     int i;
     int indice = -1;
     for (i = 0; i < tam ; i++)
     {
         if (vec[i].estado == 0)
         {
             indice = i;
             break;
         }
     }
     return indice;
 }
int buscarPersona (EPersona vec[], int tam, long dni)
{
    int i;
    int indice = -1;
    for (i = 0; i< tam; i ++)
    {
        if (vec[i].estado == 1 && vec[i].dni == dni)
        {
            indice = i;
            break;
        }

    }
    return indice;
}
void agregarPersona (EPersona vec[], int tam)
{
    int indice;
    int esta;
    long dniVal;
    char edad [4];
    char dni [9];
    int edadVal;
    char nombre [500];
    int nombreVal;
    indice = buscarLibre(vec, tam);

    if (indice == -1)
    {
        printf("El sistema esta completo, si quiere agregar una persona tendra que eliminar primero a otra");
    }
    else
    {
        do{
            printf("\nIngrese DNI:");
            scanf("%s",dni);
            dniVal = validarDNI(dni);
           }while (dniVal == 0);


        esta = buscarPersona(vec,tam,dniVal);
        if (esta != -1 )
        {
            printf("Esta persona ya esta en el sistema\n La persona es:\n %s\n",vec[esta].nombre);
        }
            else{

                vec[indice].dni = dniVal;



                do{
                    printf("\nIngrese edad:");
                    scanf("%s", edad);
                    edadVal = validarEdad(edad);
                }while (edadVal == 0);

                vec[indice].edad = edadVal;



                do
                {
                    printf("\nIngrese nombre:");
                    fflush(stdin);
                    scanf("%[^\n]", nombre);
                    nombreVal = validarNombre(nombre);
                }while (nombreVal == 0);

                strcpy(vec[indice].nombre,nombre);



                vec[indice].estado =1;

                printf("Se agrego exitosamente\n");
                }
     }
}
void eliminarPersona (EPersona vec [], int tam)
{
    int esta;
    int dni;
    char confirm;

    system("cls");
    printf("Ingrese el DNI del usuario que quiera eliminar:");
    scanf("%d", &dni);

    esta = buscarPersona(vec,tam,dni);
    if (esta != -1)
    {
        printf ("La persona que desea eliminar es: %s\n",vec[esta].nombre);
        printf("Para aceptar ingrese 's' para cancelar 'n':");
        fflush(stdin);
        scanf("%c",&confirm);
        if(confirm == 's')
        {
            vec[esta].estado = 0;
            printf("\n\nSe elimino a la persona correctamente\n\n");
        }
        else if (confirm == 'n')
        {
            printf("\n\nSe cancelo la operacion correctamente\n\n");
        }
        else
        {
            printf("Ingrese 's' para realizar la operacion o 'n' para cancelar");
        }
    }
}
void mostrarPersonas (EPersona vec[], int tam)
{
    int i;
    printf("  DNI         Nombre         Edad\n\n");
    for (i = 0; i < tam; i ++)
    {
        if (vec[i].estado==1)
        {
            ordenar(vec,tam);
            printf("  %ld       %s      %d\n\n",vec[i].dni, vec[i].nombre, vec[i].edad);
        }
    }

}
void ordenar (EPersona vec[], int tam)
{
    int i;
    int j;
    EPersona aux;
    for (i=0; i < tam; i++)
    {
        for(j= i + 1; j < tam; j ++)
        {
            if (strcmp (vec[i].nombre , vec[j].nombre)> 0)
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
            else if (strcmp (vec [i].nombre , vec [j].nombre) == 0)
            {
                if (vec[i].dni > vec[j].dni)
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
    }
}

void barras (EPersona vec[], int tam)
{

    int i, contador35 = 0, contador19 = 0, contador18 = 0, flag=0, mayor;
    for (i = 0; i <= tam; i++)
    {
        if(vec[i].edad <19 && vec[i].estado ==1)
        {
            contador18 ++;
        }


        if(vec[i].edad >=19 && vec[i].edad <=35 && vec[i].estado ==1)
        {
            contador19 ++;
        }

        if(vec[i].edad >35 && vec[i].estado ==1)
        {
            contador35 ++;
        }

    }

    if(contador18 >= contador19 && contador18 >= contador35)
    {
        mayor = contador18;
    }
    else
    {
        if(contador19 >= contador18 && contador19 >= contador35)
        {
            mayor = contador19;
        }
        else
        {
            mayor = contador35;
        }
    }
    system("cls");
    for(i = mayor; i > 0; i --){
        if(i<= contador18)
        {
            printf("*");
        }
        if(i<= contador19)
        {
            flag = 1;
            printf("\t*");
        }
        if(i<= contador35)
        {
            if(flag == 0)
                printf("\t\t*");
            if(flag == 1)
                printf("\t*");

        }
        printf("\n");
    }
    printf("<18\t19-35\t>35\n\n");
    system("pause");
}
