#ifndef ARREGLO_STRING_H_INCLUDED
#define ARREGLO_STRING_H_INCLUDED
#include "String.h"

typedef struct { String * arre;
                 int tamanio;
                } Arreglo_String;

void CrearArreglo(Arreglo_String &a, int n); /* Reserva n celdas para el arreglo.Precondición: n > 0 */
void DestruirArreglo(Arreglo_String &a); /* Libera las celdas ocupadas por el arreglo */
void ImprimirArreglo(Arreglo_String a);
void CargarArreglo(Arreglo_String &a,String s, int pos); //Carga arreglo en la posicion que le pasan
void GetElemento(Arreglo_String s, int pos, String &cop); //Devuelve un elemento del arreglo
int GetTamanio(Arreglo_String s);                         //Devuelve el tamanio del arreglo

#endif // ARREGLO_STRING_H_INCLUDED
