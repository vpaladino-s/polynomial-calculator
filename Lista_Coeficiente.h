#ifndef LISTA_COEFICIENTE_H
#define LISTA_COEFICIENTE_H
#include "Boolean.h"

typedef struct nodoC{ int info;
                      nodoC *sig;
                    }nodo;
typedef nodo *Lista_Coeficiente;

//OPERACIONES BASICAS
void CrearLista(Lista_Coeficiente &c);    //Crea la lista
boolean CoeficienteVacia(Lista_Coeficiente c);  //Devulve si la lista es vacia
int PrimerCoeficiente(Lista_Coeficiente c); //Devuelve primer valor de la lista
/* Precondición: lista NO vacía */
void RestoCoeficiente(Lista_Coeficiente &lis);   //Borra primer nodo
/* Precondición: lista NO vacía */
void InsFront (Lista_Coeficiente &c, int n);  //Inserta primero en la lista
void InsBack (Lista_Coeficiente &c, int n);  //Inserta ultimo en la lista

boolean CoeficienteCeros(Lista_Coeficiente l);   //Devuelve si toda la lista esta compuesta por ceros
int GetLargoCoeficientes(Lista_Coeficiente l);  //Devuelve el largo de la lista (Grado)
/* Precondición: lista NO vacía */
void ImprimeCoeficientes(Lista_Coeficiente l,int g);  //Imprime la lista y el x elevado
void BorrarCoeficiente(Lista_Coeficiente &c);      //Borra la lista

boolean MismoGrado(Lista_Coeficiente c1, Lista_Coeficiente c2); /*Devuelve si dos listas tienen el mismo grado*/

void SumaMenorGrado(Lista_Coeficiente l1,Lista_Coeficiente l2 ,Lista_Coeficiente &l3, int i);
/*Va cargando la l3 hasta que la lista l1 tenga igual grado que la lista 2, ahi sale y saca posicion*/

void SumaIgualGrado(Lista_Coeficiente l1,Lista_Coeficiente l2,Lista_Coeficiente &l3);

void SumaCoeficiente(Lista_Coeficiente l1,Lista_Coeficiente l2,Lista_Coeficiente &resultado); /*Devuelve Coeficiente sumado*/

void MultiplicaCoeficiente(Lista_Coeficiente c1,Lista_Coeficiente c2,Lista_Coeficiente &resultado); /*Devuelve Coeficiente multiplicado*/

int GetInfo(Lista_Coeficiente l);


#endif // LISTA_COEFICIENTE_H
