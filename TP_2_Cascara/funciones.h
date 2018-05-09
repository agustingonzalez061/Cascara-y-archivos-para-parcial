#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long dni;

}EPersona;
int validarDNI (char dni []);
int validarEdad (char edad []);
int validarNombre (char nombre []);
void inicializador (EPersona vec[],int TAM);
int buscarLibre (EPersona vec[], int TAM);
int buscarPersona (EPersona vec[], int TAM, long dni);
void agregarPersona (EPersona vec[], int TAM);
void eliminarPersona (EPersona vec[], int tam);
void mostrarPersonas (EPersona vec[], int tam);
void ordenar (EPersona vec[], int tam);
void barras (EPersona vec[], int tam);
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

#endif // FUNCIONES_H_INCLUDED
