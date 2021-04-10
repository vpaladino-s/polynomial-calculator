#include "test_PolinomioABB.h"


void TestPolinomioABB()
{
    printf("\n\n----------------Voy a testear PolinomioABB----------------\n\n");
    Polinomio p;
    Lista_Coeficiente c;
    CrearLista(c);
    int num;
    String nombre;
    strCrear(nombre);
    Polinomio_ABB a;

    int grado;
    printf("\n\nIngrese el grado del polinomio\n");
    scanf("%d",&grado);
    for(int i = 0; i <= grado; i++){
        printf("Ingrese el grado %d: ", i);
        scanf("%d",&num);
        InsFront(c,num);
    }

    printf("\n\nIngrese el nombre del polinomio: ");
    scan(nombre);
    printf("\nEl nombre es:");
    print(nombre);
    CargarPolinomio(p,nombre,c,grado+1);
    InsertarOrdenado(a,p);


    String nombre2;
    strCrear(nombre2);
    Polinomio p2;
    printf("\n\nIngrese el nombre del polinomio2: ");
    scan(nombre2);
    printf("\nEl nombre2 es:");
    print(nombre2);
    CargarPolinomio(p2,nombre2,c,grado+1);
    InsertarOrdenado(a,p2);
    printf("\n\n\n\nArbol: \n");
    Mostrar(a);

}
