#ifndef COMANDO_H
#define COMANDO_H
#include "Polinomio_ABB.h"
#include "Arreglo_String.h"

void Comando(Polinomio_ABB &arbol, int &resu); //Interpreta los comandos y devuelve un estatus a main

int SplitString(String s, Arreglo_String &a);  //Encuentra espacio y va gaurdando strings en el arreglo

int SplitCoeficiente(Arreglo_String s,Lista_Coeficiente &c, int pos);   //Encuentra numeros y los va clocando la lista.

#endif // COMANDO_H
