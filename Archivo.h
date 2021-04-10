#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "Polinomio.h"

//Lista_Coefiente
void GuardarEntero(int n, FILE * f);
void GuardarLista(Lista_Coeficiente c, FILE * f);    //Guarda en disco lista
void LevantarEntero(int &n, FILE * f);
/* Precondición: archivo NO vacío */
void LevantarLista(Lista_Coeficiente &c,FILE * f);   //Levanta lista del disco

boolean ArchivoVacio(String nomArchivo);  // Determina si el archivo está vacío o no.
//Precondición: El archivo existe

//COMANDOS
void Guardar(Polinomio p,String nomArchivo);    //Guarda un polinomio

void Recuperar(Polinomio &p,String nomArchivo); //Recupera un polinomio

boolean ExisteArchivo(String nomArchivo);    //Devuelve si el archivo existe

#endif // ARCHIVO_H
