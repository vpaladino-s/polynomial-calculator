#ifndef STRING_H
#define STRING_H
#include "Boolean.h"

const int MAX=240;
typedef char * String;

void strCrear(String &s);   //Crea un string vacío (solo con el carácter ‘\0’)

void strDestruir(String &s);    //Libera la memoria ocupada por el string y lo deja nulo.

int strlar(String s); //Devuelve el largo del string s

void strcop(String &str1,String str2);  //Copia string 2 en string 1

void scan(String &s);   //Lee un string desde teclado

void strcon(String &str1,String str2);  //Concatena el contenido de s2 al final de s1

void strswp(String &str1,String &str2); //Intercambia los string

void print(String s);   //Imprime string

boolean strmen(String str1,String str2);    //Determina si str1 es alfabeticamente menor que str2

boolean streq(String str1,String str2); //Determina si dos strings son iguales

int strCantPalabras(String s);  //Devuelve la cantidad de palabras del string

char strDevuelvePos(String s, int pos);         //Devuelve el caracter de la posicion

void strSetPos(String s, char c ,int pos);      //Carga el caracter en la posicion

#endif // STRING_H
