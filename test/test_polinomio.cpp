#include "test_polinomio.h"

void TestPolinomio(){


    printf("\n\n----------------Voy a testear Polinomio----------------\n\n");
    Lista_Coeficiente l1;
    int num,tamanio;
    CrearLista(l1);
    int grado;
    printf("Ingrese el grado del polinomio\n");
    scanf("%d",&grado);

    for(int i = 0; i <= grado; i++){
        printf("Ingrese el grado %d: ", i);
        scanf("%d",&num);
        InsFront(l1,num);
    }


    tamanio=GetLargoCoeficientes(l1);
    printf("Tamanio del polinomio %d",tamanio);
    printf("\n");

    String nom1;
    strCrear(nom1);
    printf("\nIngrese el nombre del polinomio\n");
    scan(nom1);

    Polinomio pol1;
    CargarPolinomio(pol1,nom1, l1,grado+1);

    printf("\n");

   printf("\n\nImprime el polinomio: \n");
   ImprimePolinomio(pol1);

   printf("\n\nVoy a evaluar el polinomio con el numero que me ingreses debajo: \n");

   int eva;
   scanf("%d",&eva);
   int resuEva = Evaluar(pol1,eva);
   printf("\nEl resultado de la evaluación es: %d\n", resuEva);

    printf("\n\nVoy a ver si el numero que ingreses debajo es raiz: \n");
    int raiz;
    scanf("%d",&raiz);
    EsRaiz(pol1,raiz);


}

