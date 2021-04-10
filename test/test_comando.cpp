#include "test_comando.h"

void TestComando()
{
    Arreglo_String a;
    Lista_Coeficiente c;
    CrearLista(c);
    String s;
    strCrear(s);

    printf("\n\n----------------Voy a testear Comando----------------\n\n");
    printf("\n\nEscriba un comando: ");
    fflush(stdin);
    scan(s);
    printf("El string ingresado es:");
    print(s);

    int largoarre= strCantPalabras(s);
    printf("\nEl string tiene %d palabras\n", largoarre);
    CrearArreglo(a,largoarre);
    SplitString(s,a);
    printf("\n\nEl arreglo esta cargado por:\n");
    ImprimirArreglo(a);

//    SplitCoeficiente(a,c,pos);
//    int num=GetLargoCoeficientes(c);
//    printf("\n\nLos coeficientes son:");
//    if(!CoeficienteVacia(c)){
//        ImprimeCoeficientes(c,num);
//    }
    Polinomio_ABB arbol;
    CrearArbol(arbol);
    int resu  = 0;
    Comando(arbol, resu);

    printf("\nEl resultado de comando es : %d\n", resu);
    Mostrar(arbol);


}
