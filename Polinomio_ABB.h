#ifndef POLINOMIO_ABB_H
#define POLINOMIO_ABB_H
#include "Polinomio.h"
#include "Archivo.h"

typedef struct nodoP{ Polinomio info;
                      nodoP *hizq;
                      nodoP *hder;
                      }nodoPoli;
typedef nodoPoli *Polinomio_ABB;

//Operaciones Basicas
void CrearArbol(Polinomio_ABB &a);
boolean EsVacio(Polinomio_ABB a);
Polinomio DarRaiz(Polinomio_ABB a);
Polinomio_ABB HijoIzquierdo(Polinomio_ABB a);
Polinomio_ABB HijoDerecho(Polinomio_ABB a);

/*Inserta alfabéticamente polinomio en árbol */
void InsertarOrdenado(Polinomio_ABB &p, Polinomio q);
boolean Pertenece (Polinomio_ABB a, String s);
/*Precondicion GetNombre(a->info,s)*/

void Borrar_Minimo (Polinomio_ABB &p);
void LiberarArbol(Polinomio_ABB &p);

//Devuelve el polinomio cuyo nombre es s
Polinomio Buscar(Polinomio_ABB a, String s);
//Precondición: El polinomio pertenece al arbol

//COMANDOS

void Mostrar(Polinomio_ABB p);	/*Muestra por pantalla todos los polinomios existentes en memoria*/

void Crear(Polinomio_ABB &p,Polinomio q);

void Sumar(Polinomio_ABB &p, Polinomio p1, Polinomio p2,String n);

void Multiplicar(Polinomio_ABB &p, Polinomio p1, Polinomio p2,String n);



#endif // POLINOMIO_ABB_H
