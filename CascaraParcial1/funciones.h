#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int codeProveedor;
    char descripcion [50];
    int estado;
    int proveedorID;
    int contador;
}Proveedor;


typedef struct
{
    int codeProducto;
    char descripcion [50];
    int importe;
    int cantidad;
    int estado;
    int ProductoID;
    int IDProveedor;
    Proveedor prove;
}Producto;


void inicializador (Producto vec [],int tam);
void inicializadorProduc (Producto vec [],int cant);
int buscarLibre (Producto vec[], int tam);
int buscarProveedor (Producto vec[], int tam, char descrip []);
int validarCHAR (char decrip []);
int agregarProveedor (Producto vec[], int tam);
void mostrarProveedor (Producto[], int tam);
void agregarProducto (Producto vec[], int tam);
int validarImporte(char cantidad []);
int buscarProducto (Producto vec[], int tam, char descrip []);
int validarINT (char cantidad []);
int autoIncrementoProve (Producto vec [], int tam);
int autoIncrementoProdu (Producto vec [], int tam);
void modificarProducto (Producto vec [], int tam);
void eliminarProducto (Producto vec [], int tam);
void informar(Producto vec[],int cant, int tam);
void listar (Producto vec [],int tam, int cant);
void ordenar (Producto vec[], int cant);
void mostrarProductos (Producto vec[], int cant);
void mostrarProducto (Producto vec[], int i);
void TPS (Producto vec [], int cant);
void TPNS (Producto vec [], int cant);
void cantidaStockMayor (Producto vec[], int cant);
void cantidaStockMenor (Producto vec[], int cant);
void promSUP (Producto vec [],int cant);
void promINF (Producto vec [],int cant);
void ProveedoresProductoCANT (Producto vec[],int cant, int tam);
void ProveedoresProducto(Producto vec[],int cant, int tam);
void ProveedorDeterminado (Producto vec[],int cant, int tam);
void MasProductos(Producto vec[],int cant, int tam);
void MenosProductos(Producto vec[],int cant, int tam);
#endif // FUNCIONES_H_INCLUDED
