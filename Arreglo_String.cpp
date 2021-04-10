#include "Arreglo_String.h"

/* Reserva n celdas para el arreglo.Precondición: n > 0 */
void CrearArreglo(Arreglo_String &a, int n){
    a.arre = new String[n];
    a.tamanio = n;
}



/* Libera las celdas ocupadas por el arreglo */
void DestruirArreglo(Arreglo_String &a){
    delete [] a.arre;
    a.arre = NULL;
    a.tamanio = 0;
}

void ImprimirArreglo(Arreglo_String a)
{
    int i;
    for(i=0;i<a.tamanio;i++){
        printf("Arre[%d] : ",i);
        print(a.arre[i]);
        printf("\n");
    }
    printf("\n");
}

void CargarArreglo(Arreglo_String &a,String s, int pos)
{
    a.arre[pos] = s;
}

void GetElemento(Arreglo_String s, int pos, String &cop){
    strcop(cop, s.arre[pos]);
}

int GetTamanio(Arreglo_String s){
    return s.tamanio;
}
