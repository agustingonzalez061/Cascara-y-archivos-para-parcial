#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

void inicializador (Producto vec [],int tam)
 {
     int i;
     for (i = 0 ; i< tam ; i++)
     {
         vec[i].prove.estado = 0;
     }
 }
 void inicializadorProduc (Producto vec [],int cant)
 {
     int i;
     for (i = 0 ; i< cant ; i++)
     {
         vec[i].estado = 0;
     }
 }
 int buscarLibre (Producto vec[], int tam)
 {
     int i;
     int indice = -1;
     for (i = 0; i < tam ; i++)
     {
         if (vec[i].prove.estado == 0)
         {
             indice = i;
             break;
         }
     }
     return indice;
 }
 int buscarProveedor(Producto vec[], int tam, char descrip [])
{
    int i;
    int indice = -1;
    for (i = 0; i< tam; i ++)
    {
        if (vec[i].prove.estado == 1 && strcmp(vec[i].prove.descripcion,descrip) == 0)
        {
            indice = i;
            break;
        }

    }
    return indice;
}

int validarCHAR (char descrip [])
{
    int i;
    int letras;
    letras = strlen(descrip);
    if(letras > 50)
    {
        printf("La descripcion es demasiado largo");
        return 0;
    }
    for (i = 0; i < letras ; i++)
    {
        if (!(isalpha(descrip[i])))
        {
            if(descrip [i] != ' ')
            {
                printf("La descripcion no es valido.");
                return 0;
            }
        }

    }

    return 1;
}
// FUNCIONES PARA PROVEEDOR
int agregarProveedor (Producto vec[], int tam)
{
    int indice;
    int code;
    int esta;
    char descripcion [500];
    int descripcionVal;
    indice = buscarLibre(vec, tam);

    if (indice == -1)
    {
        printf("El sistema esta completo, si quiere agregar un proveedor tendra que eliminar primero a otra");
    }
    else
    {
        do
        {
            printf("\nIngrese descripcion:");
            fflush(stdin);
            scanf("%[^\n]",descripcion);
            descripcionVal = validarCHAR(descripcion);
        }while (descripcionVal == 0);


        esta = buscarProveedor(vec,tam,descripcion);
        if (esta != -1 )
        {
            printf("Esta Descripcion ya esta en el sistema\n El codigo es:\n %d\n",vec[esta].prove.codeProveedor);
        }
            else{

                strcpy(vec[indice].prove.descripcion,descripcion);

                vec[indice].prove.estado =1;
                code = autoIncrementoProve(vec,tam);
                vec[indice].prove.proveedorID = vec[indice].prove.codeProveedor;
                vec[indice].prove.codeProveedor = code;
                printf("Su codigo de proveedor es: %d", indice);
                }
     }
     return code;
}
void mostrarProveedor(Producto vec[], int tam)
{
    int i;
    printf("CODIGO\t\tDescripcion\n\n");
    for (i = 0; i < tam; i ++)
    {
        if (vec[i].prove.estado==1)
        {
            printf("%d\t\t%s\n\n",vec[i].prove.codeProveedor, vec[i].prove.descripcion);
        }
    }

}

int autoIncrementoProve (Producto vec [], int tam)
{
    int i;
    int code = 1;
    for (i = 0; i < tam; i ++)
    {
        if (vec[i].prove.codeProveedor != code && vec[i].prove.estado == 1)
        {
            break;
        }
        else
        {
            code ++;
        }

    }
    return code;
}
// FUNCIONES PARA PRODUCTO
int autoIncrementoProdu (Producto vec [], int tam)
{
    int i;
    int code = 1;
    for (i = 0; i < tam; i ++)
    {
        if (vec[i].codeProducto != code && vec[i].estado == 1)
        {
            break;
        }
        else
        {
            code ++;
        }

    }
    return code;
}
 int buscarProducto (Producto vec[], int tam, char descrip [])
{
    int i;
    int indice = -1;
    for (i = 0; i< tam; i ++)
    {
        if (vec[i].estado == 1 && strcmp(vec[i].descripcion,descrip) == 0)
        {
            indice = i;
            break;
        }

    }
    return indice;
}
int validarINT (char cantidad [])//operacion de carga de datos

{
    int i;
    int numero;
    for (i = 0; i < strlen(cantidad) ; i++)
    {
        if (!(isdigit(cantidad[i])))
        {
            printf("La cantidad no es valida");
            return 0;
        }

    }
    numero = atoi(cantidad);
    while( numero < 1)
    {
        printf("La cantidad debe ser mayor a 0");
        return 0;
    }
    return numero;
}
int validarImporte (char cantidad [])//operacion de carga de datos

{
    int i;
    int numero;
    for (i = 0; i < strlen(cantidad) ; i++)
    {
        if (!(isdigit(cantidad[i])))
        {
            printf("El importe no es valida");
            return 0;
        }

    }
    numero = atof(cantidad);
    while( numero < 1)
    {
        printf("El importe debe ser mayor a 0");
        return 0;
    }
    return numero;
}
int buscarCode (Producto vec[], int tam, int code) //FUNCION PARA BUSCAR SI EL PRODUCTO YA ESTABA INGRESADO
{
    int i;
    int flag;
    for (i = 0; i< tam; i ++)
    {
        if (vec[i].prove.estado == 1 && vec[i].prove.codeProveedor == code)
        {
            flag = 1;
            break;
        }
        else
        {
            printf("\nNo se encontro el codigo ingresado");
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        return code;
    }
    return flag;
}
int buscarCodigo (Producto vec[], int tam, int code) //FUNCION PARA BUSCAR DIRECCION DEL PRODUCTO
{
    int i;
    int flag;
    for (i = 0; i< tam; i ++)
    {
        if (vec[i].prove.estado == 1 && vec[i].codeProducto == code)
        {
            flag = i;
            break;
        }
        else
        {
            printf("\nNo se encontro el codigo ingresado");
            flag = 0;
            break;
        }
    }
    return flag;
}
void agregarProducto (Producto vec[], int tam)
{
    int indice;
    char opcion;
    int esta;
    char descripcion [500];
    int descripcionVal;
    char importe [20];
    float importeVal;
    char cantidad [10];
    int cantVal;
    int codeProdu;
    int codeVal;
    int flag = 0;
    indice = buscarLibre(vec, tam);

    if (indice == -1)
    {
        printf("El sistema esta completo, si quiere agregar una persona tendra que eliminar primero a otra");
    }
    else
    {
        do
        {
            printf("\nIngrese descripcion:");
            fflush(stdin);
            scanf("%[^\n]",descripcion);
            descripcionVal = validarCHAR(descripcion);
        }while (descripcionVal == 0);


        esta = buscarProducto(vec,tam,descripcion);
        if (esta != -1 )
        {
            printf("Esta Descripcion ya esta en el sistema\n La descripcion es:\n %s\n",vec[esta].descripcion);
        }
            else{

                strcpy(vec[indice].descripcion,descripcion);
                do{
                    printf("\nIngrese importe:");
                    scanf("%s", importe);
                    importeVal = validarImporte(importe);
                }while (importeVal == 0);
                vec[indice].importe = importeVal;
                do{
                    printf("\nIngrese cantidad:");
                    scanf("%s", cantidad);
                    cantVal = validarINT(cantidad);
                }while (cantVal == 0);

                vec[indice].cantidad = cantVal;


                mostrarProveedor(vec,tam);
                while (flag == 0){
                printf("Si su proveedor se encuentra en la lista ingrese 's', de lo contrario 'n'");
                fflush(stdin);
                scanf("%c", &opcion);
                switch(opcion)
                {
                    case 's':
                        do
                        {
                            printf("Ingrese codigo del productor");
                            scanf("%d", &codeProdu);
                            fflush(stdin);
                            codeVal = buscarCode(vec, tam, codeProdu);

                        }while (codeVal== 0);
                        flag =1;
                    break;
                    case 'n':
                        {
                            codeProdu = agregarProveedor(vec,tam);
                            flag = 1;
                            break;
                        }
                    default:
                    {
                        printf("Ingrese un valor 's' o 'n'");
                    }
                }
                }


                vec[indice].estado = 1;
                vec[indice].codeProducto = autoIncrementoProdu(vec,tam);
                vec[indice].ProductoID = codeProdu;

                printf("\n\nEl codigo del producto es: %d\n", indice);
                }
     }
}

void modificarProducto (Producto vec [], int tam)
{
    int esta;
    int code;
    char confirm;
    int opcion;
    char descripcion [500];
    int descripcionVal;
    char importe [20];
    float importeVal;
    char cantidad [10];
    int cantVal;

    system("cls");
    printf("Ingrese el codigo del producto que quiera modificar:");
    scanf("%d", &code);

    esta = buscarCodigo(vec,tam,code);
    if (esta != -1)
    {
        printf ("El producto que desea modificar es: %s\n",vec[esta].descripcion);
        printf("\nPara aceptar ingrese 's' para cancelar 'n':");
        fflush(stdin);
        scanf("%c",&confirm);
        while(confirm == 's')
        {
            printf("Que quiere modificar del empleado?\n");
            printf("1:Descripcion\n");
            printf("2:Importe\n");
            printf("3:Cantidad\n");
            printf("4:Todos\n");
            printf("\nIndique opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            switch (opcion)
            {
                case 1:
                        do
                            {
                                printf("\nIngrese descripcion:");
                                fflush(stdin);
                                scanf("%[^\n]",descripcion);
                                descripcionVal = validarCHAR(descripcion);
                            }while (descripcionVal == 0);
                            strcpy(vec[esta].descripcion,descripcion);
                        break;
                case 2:
                        do{
                            printf("\nIngrese importe:");
                            scanf("%s", importe);
                            importeVal = validarImporte(importe);
                        }while (importeVal == 0);
                        vec[esta].importe = importeVal;
                        break;
                case 3:
                        do{
                            printf("\nIngrese cantidad:");
                            scanf("%s", cantidad);
                            cantVal = validarINT(cantidad);
                        }while (cantVal == 0);
                        vec[esta].cantidad = cantVal;
                        break;
                case 4:
                        do
                            {
                                printf("\nIngrese descripcion:");
                                fflush(stdin);
                                scanf("%[^\n]",descripcion);
                                descripcionVal = validarCHAR(descripcion);
                            }while (descripcionVal == 0);
                            strcpy(vec[esta].descripcion,descripcion);

                        do{
                            printf("\nIngrese importe:");
                            scanf("%s", importe);
                            importeVal = validarImporte(importe);
                        }while (importeVal == 0);
                        vec[esta].importe = importeVal;

                        do{
                            printf("\nIngrese cantidad:");
                            scanf("%s", cantidad);
                            cantVal = validarINT(cantidad);
                        }while (cantVal == 0);
                        vec[esta].cantidad = cantVal;
                default:
                    printf("No ingreso ninguna opcion del menu");
            }
                printf("Desea realizar otra modificacion? s/n\n");
                printf("Indique opcion: ");
                fflush(stdin);
                scanf("%c", &confirm);
        }


    if (confirm == 'n')
    {
        printf("\n\nSe cancelo la operacion correctamente\n\n");
    }

    }
    else
    {
        printf("No se encontro el codigo del producto");
    }
}
void eliminarProducto (Producto vec [], int tam)
{
    int esta;
    int code;
    char confirm;

    system("cls");
    printf("Ingrese el codigo del producto que quiera eliminar:");
    scanf("%d", &code);

    esta = buscarCodigo(vec,tam,code);
    if (esta != -1)
    {
        printf ("El producto que desea eliminar es: %s\n",vec[esta].descripcion);
        printf("\nPara aceptar ingrese 's' para cancelar 'n':");
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


int promedio (Producto vec[],int cant)
{
    int i;
    int contador = 0;
    int acumulador = 0;
    int prom;
    for (i = 0; i < cant; i ++)
    {
        if (vec[i].estado == 1)
        {
            acumulador = acumulador + vec[i].importe;
            contador ++;
        }
    }
    prom = acumulador / contador;
    return prom;
}

void informar(Producto vec[],int cant, int tam)
{
    char seguir='s';
    char opcion;
    while(seguir=='s')
    {
        system("cls");
        printf("A- TOTAL y PROMEDIO de los importes y cuantos productos superan ese promedio. \n");
        printf("B- TOTAL y PROMEDIO de los importes y cuantos productos NO superan ese promedio.\n");
        printf("C- La cantidad de productos cuyo stock es menor o igual a 10.\n");
        printf("D- La cantidad de productos cuyo stock es mayor a 10.\n");
        printf("E- Salir\n");

        printf("\n\nIndique opcion:");
        fflush(stdin);
        scanf("%c",&opcion);

        switch(opcion)
        {
            case 'a':
                system("cls");
                TPS (vec,cant);
                system("pause");
                break;
            case 'b':
                system("cls");
                TPNS (vec,cant);
                system("pause");
                break;
            case 'c':
                system("cls");
                cantidaStockMayor (vec,cant);
                system("pause");
                break;
            case 'd':
                system("cls");
                cantidaStockMenor (vec,cant);
                system("pause");
                break;
            case 'e':
                seguir = 'n';
                break;
            default:
                printf("Ingrese una opcion que este dentro del menu");
                break;

        }
    }
}
void TPS (Producto vec [], int cant)
{
    int i, acumulador = 0, prom,contador= 0,contadorSUP=0;
    for (i = 0; i < cant; i ++)
                {
                    if (vec[i].estado == 1)
                    {
                        acumulador = acumulador + vec[i].importe;
                        contador ++;
                    }
                }
                prom = acumulador / contador;
                for (i = 0; i < cant; i ++)
                {
                    if (vec[i].estado == 1&& vec[i].importe > prom)
                    {
                        contadorSUP ++;
                    }
                }
                printf("TOTAL: %d \nPROMEDIO: %d\nCANTIDAD: %d\n", acumulador,prom,contadorSUP);
}
void TPNS (Producto vec [], int cant)
{
    int i, acumulador = 0, prom,contador= 0,contadorMEN=0;
    for (i = 0; i < cant; i ++)
                {
                    if (vec[i].estado == 1)
                    {
                        acumulador = acumulador + vec[i].importe;
                        contador ++;
                    }
                }
                prom = acumulador / contador;
                for (i = 0; i < cant; i ++)
                {
                    if (vec[i].estado == 1&& vec[i].importe < prom)
                    {
                        contadorMEN ++;
                    }
                }
                printf("TOTAL: %d \nPROMEDIO: %d\nCANTIDAD: %d\n", acumulador,prom,contadorMEN);
}


void cantidaStockMayor (Producto vec[], int cant)
{
    int i, contador = 0;
    for (i = 0; i < cant; i ++)
                {
                    if (vec[i].estado == 1 && vec[i].cantidad <= 10)
                    {
                        contador ++;
                    }
                }
                printf("\nCANTIDAD: %d\n",contador);
}

void cantidaStockMenor (Producto vec[], int cant)
{
    int i, contador = 0;
    for (i = 0; i < cant; i ++)
                {
                    if (vec[i].estado == 1 && vec[i].cantidad > 10)
                    {
                        contador ++;
                    }
                }
                printf("\nCANTIDAD: %d\n",contador);
}




void listar (Producto vec [],int tam, int cant)
{
    char opcion;
    char seguir='s';


    int i;


    while(seguir=='s')
    {
        system("cls");
        printf("A- Ordenar productos \n");
        printf("B- Todos los productos que en cantidad son menores o igual a 10\n");
        printf("C- Todos los productos que en cantidad son mayor a 10\n");
        printf("D- Todos los productos que superan el promedio de los importes\n");
        printf("E- Todos los productos que no superan el promedio de los importes\n");
        printf("F- Todos los proveedores cuya cantidad de producto es menor o igual a 10\n");
        printf("G- Todos los productos provistos por cada proveedor\n");
        printf("H- Todos los productos provistos por un proveedor determinado\n");
        printf("I- El proveedor que provee mas productos, y sus productos \n");
        printf("J- El proveedor que provee menos productos, y sus productos \n");
        printf("K- El proveedor que provee el producto mas caro,y cual es \n");
        printf("L- El proveedor que provee el producto mas barato,y cual es \n");
        printf("M- Salir\n");

        printf("\n\nIndique opcion:");
        fflush(stdin);
        scanf("%c",&opcion);

        switch(opcion)
        {
            case 'a':
                system("cls");
                ordenar (vec,cant);
                mostrarProductos (vec,cant);
                system("pause");
                break;
            case 'b':
                system("cls");
                printf("CODIGO\t\t\tDESCRIPCION\t\t\tIMPORTE\t\t\tCANTIDAD\n\n");
                for (i = 0; i < cant; i ++)
                {
                    if (vec[i].estado == 1 && vec[i].cantidad <= 10)
                    {
                       mostrarProducto (vec,i);
                    }
                }
                system("pause");
                break;
            case 'c':
                system("cls");
                printf("CODIGO\t\t\tDESCRIPCION\t\t\tIMPORTE\t\t\tCANTIDAD\n\n");
                for (i = 0; i < cant; i ++)
                {
                    if (vec[i].estado == 1 && vec[i].cantidad > 10)
                    {
                       mostrarProducto (vec,i);
                    }
                }
                system("pause");
                break;
            case 'd':
                system("cls");
                printf("CODIGO\t\t\tDESCRIPCION\t\t\tIMPORTE\t\t\tCANTIDAD\n\n");
                promSUP (vec,cant);
                system("pause");
                break;
            case 'e':
                system("cls");
                printf("CODIGO\t\t\tDESCRIPCION\t\t\tIMPORTE\t\t\tCANTIDAD\n\n");
                promINF(vec,cant);
                system("pause");
                break;
            case 'f':
                system("cls");
                printf("PROVEEDOR\tDESCRIPCION\tPRODUCTO\tDESCRIPCION\tIMPORTE\tCANTIDAD\n\n");
                ProveedoresProductoCANT (vec,cant,tam);
                system("pause");
                break;
            case 'g':
                system("cls");
                printf("PROVEEDOR\tDESCRIPCION\tPRODUCTO\tDESCRIPCION\tIMPORTE\tCANTIDAD\n\n");
                ProveedoresProducto(vec,cant,tam);
                system("pause");
                break;
            case 'h':
                system("cls");
                printf("PROVEEDOR\tDESCRIPCION\tPRODUCTO\tDESCRIPCION\tIMPORTE\tCANTIDAD\n\n");
                ProveedorDeterminado (vec,cant,tam);
                system("pause");
                break;
            case 'i':
                system("cls");
                printf("PROVEEDOR\tDESCRIPCION\tPRODUCTO\tDESCRIPCION\tIMPORTE\tCANTIDAD\n\n");
                MasProductos(vec,cant,tam);
                system("pause");
                break;
            case 'j':
                system("cls");
                printf("PROVEEDOR\tDESCRIPCION\tPRODUCTO\tDESCRIPCION\tIMPORTE\tCANTIDAD\n\n");
                MenosProductos(vec,cant,tam);
                system("pause");
                break;
            case 'k':
                break;
            case 'l':
                break;
            case 'm':
                seguir = 'n';
                break;
            default :
                printf("Ingrese una opcion que este en el menu");
        }
    }
}


void ordenar (Producto vec[], int cant)
{
    int i;
    int j;
    Producto aux;
    for (i=0; i < cant; i++)
    {
        for(j= i + 1; j < cant; j ++)
        {
            if (vec[i].importe > vec[j].importe)
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            else if (vec[i].importe == vec[j].importe)
            {
                if (strcmp (vec[i].descripcion , vec[j].descripcion)> 0)
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
    }
}
void mostrarProductos (Producto vec[], int cant)
{
    int i;
    printf("CODIGO\t\t\tDESCRIPCION\t\t\tIMPORTE\t\t\tCANTIDAD\n\n");
    for (i = 0; i < cant; i ++)
    {
        if (vec[i].estado==1)
        {
            mostrarProducto(vec,i);
        }
    }

}

void mostrarProducto (Producto vec[], int i)
{
    printf("%d\t\t\t%s\t\t\t%d\t\t\t%d\n\n",vec[i].codeProducto, vec[i].descripcion, vec[i].importe, vec[i].cantidad);
}


void promSUP (Producto vec [],int cant)
{
    int i, acumulador = 0, prom,contador= 0;
    for (i = 0; i < cant; i ++)
                {
                    if (vec[i].estado == 1)
                    {
                        acumulador = acumulador + vec[i].importe;
                        contador ++;
                    }
                }
                prom = acumulador / contador;
                for (i = 0; i < cant; i ++)
                {
                    if (vec[i].estado == 1&& vec[i].importe > prom)
                    {
                        mostrarProducto(vec,cant);
                    }
                }
}

void promINF (Producto vec [],int cant)
{
    int i, acumulador = 0, prom,contador= 0;
    for (i = 0; i < cant; i ++)
                {
                    if (vec[i].estado == 1)
                    {
                        acumulador = acumulador + vec[i].importe;
                        contador ++;
                    }
                }
                prom = acumulador / contador;
                for (i = 0; i < cant; i ++)
                {
                    if (vec[i].estado == 1&& vec[i].importe < prom)
                    {
                        mostrarProducto(vec,cant);
                    }
                }
}

void ProveedoresProductoCANT (Producto vec[],int cant, int tam)
{
    int i, j;
    for (i = 0; i < tam; i ++)
    {
        for (j = 0; j < cant; j ++)
        {
            if(vec[i].prove.codeProveedor == vec[j].ProductoID && vec[i].prove.estado == 1 && vec[j].estado == 1&& vec[j].cantidad < 10)
            {
                printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\n\n",vec[i].prove.codeProveedor,vec[i].prove.descripcion,vec[j].codeProducto,vec[j].descripcion,vec[j].importe,vec[j].cantidad);
            }
        }
    }
}

void ProveedoresProducto(Producto vec[],int cant, int tam)
{
    int i, j;
    for (i = 0; i < tam; i ++)
    {
        for (j = 0; j < cant; j ++)
        {
            if(vec[i].prove.codeProveedor == vec[j].ProductoID && vec[i].prove.estado == 1 && vec[j].estado == 1)
            {
                printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\n\n",vec[i].prove.codeProveedor,vec[i].prove.descripcion,vec[j].codeProducto,vec[j].descripcion,vec[j].importe,vec[j].cantidad);
            }
        }
    }
}
void ProveedorDeterminado (Producto vec[],int cant, int tam)
{
    int j;
    int code;
    int codigoVAL;
    do
    {
    printf("Ingrese codigo del proveedor:");
    fflush(stdin);
    scanf("%d", &code);
    codigoVAL =buscarCode(vec,tam,code);
    }while(codigoVAL == 0);
    for(j=0; j < cant; j ++)
    {
        if(vec[codigoVAL].prove.codeProveedor == vec[j].ProductoID && vec[codigoVAL].prove.estado == 1 && vec[j].estado == 1)
            {
                printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\n\n",vec[codigoVAL].prove.codeProveedor,vec[codigoVAL].prove.descripcion,vec[j].codeProducto,vec[j].descripcion,vec[j].importe,vec[j].cantidad);
            }
    }
}

void MasProductos(Producto vec[],int cant, int tam)
{
    int i, j,k, mayor;
    vec[i].prove.contador = 0;
    k= i-1;
    mayor = i;
    for (i = 0; i < tam; i ++)
    {
        for (j = 0; j < cant; j ++)
        {
            if(vec[i].prove.codeProveedor == vec[j].ProductoID && vec[i].prove.estado == 1 && vec[j].estado == 1)
            {
                vec[i].prove.contador ++;
                if (vec[k].prove.contador > vec[i].prove.contador)
                {
                    mayor = k;
                }
            }
        }
    }
    if (mayor == i)
    {
        for (j = 0; j < cant; j ++)
        {
            if(vec[i].prove.codeProveedor == vec[j].ProductoID && vec[i].prove.estado == 1 && vec[j].estado == 1)
            {
                printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\n\n",vec[i].prove.codeProveedor,vec[i].prove.descripcion,vec[j].codeProducto,vec[j].descripcion,vec[j].importe,vec[j].cantidad);
            }
        }
    }
    else if (mayor == k)
        for (j = 0; j < cant; j ++)
        {
            if(vec[k].prove.codeProveedor == vec[j].ProductoID && vec[k].prove.estado == 1 && vec[j].estado == 1)
            {
                printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\n\n",vec[k].prove.codeProveedor,vec[k].prove.descripcion,vec[j].codeProducto,vec[j].descripcion,vec[j].importe,vec[j].cantidad);
            }
        }
}


void MenosProductos(Producto vec[],int cant, int tam)
{
    int i, j,k, menor;
    vec[i].prove.contador = 0;
    k= i-1;
    menor = i;
    for (i = 0; i < tam; i ++)
    {
        for (j = 0; j < cant; j ++)
        {
            if(vec[i].prove.codeProveedor == vec[j].ProductoID && vec[i].prove.estado == 1 && vec[j].estado == 1)
            {
                vec[i].prove.contador ++;
                if (vec[k].prove.contador < vec[i].prove.contador)
                {
                    menor = k;
                }
            }
        }
    }
    if (menor == i)
    {
        for (j = 0; j < cant; j ++)
        {
            if(vec[i].prove.codeProveedor == vec[j].ProductoID && vec[i].prove.estado == 1 && vec[j].estado == 1)
            {
                printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\n\n",vec[i].prove.codeProveedor,vec[i].prove.descripcion,vec[j].codeProducto,vec[j].descripcion,vec[j].importe,vec[j].cantidad);
            }
        }
    }
    else if (menor == k)
        for (j = 0; j < cant; j ++)
        {
            if(vec[k].prove.codeProveedor == vec[j].ProductoID && vec[k].prove.estado == 1 && vec[j].estado == 1)
            {
                printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\n\n",vec[k].prove.codeProveedor,vec[k].prove.descripcion,vec[j].codeProducto,vec[j].descripcion,vec[j].importe,vec[j].cantidad);
            }
        }
}















