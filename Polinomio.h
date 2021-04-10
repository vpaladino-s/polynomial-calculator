#ifndef POLINOMIO_H
#define POLINOMIO_H
#include "Lista_Coeficiente.h"
#include "Arreglo_String.h"

typedef struct{ Lista_Coeficiente c;
                int grado;
                String nombre;
            }Polinomio;

/*Carga Polinomio*/
void CargarPolinomio(Polinomio &p, String s,Lista_Coeficiente c, int grado);

//Imprime Polinomio
void ImprimePolinomio(Polinomio p);

//Evalua el polinomio en x
int Evaluar(Polinomio p, int x);

//Imprime si r es raiz o no
void EsRaiz(Polinomio p, int r);

//Getter
Lista_Coeficiente GetCoeficiente(Polinomio p);     //Devuelve el coeficiente
int GetGrado(Polinomio p);   //Devuelve grado
void GetNombre(Polinomio p, String &s);   //Devuelve nombre

//Setter
void SetCoeficiente(Polinomio &p,Lista_Coeficiente c);     //Carga coeficiente con coeficiente dado
void SetGrado(Polinomio &p,int g);     //Carga grado con valor dado
void SetNombre(Polinomio &p, String s );    //Carga nombre con string dado

void LiberaPolinomio(Polinomio p);

#endif // POLINOMIO_H
