#include "test_ListaCoeficientes.h"

void TestCoeficientes()
{
    Lista_Coeficiente l1,l2,suma,mult;
    int num,tamanio;
    CrearLista(l1);
    CrearLista(l2);
    CrearLista(suma);
    CrearLista(mult);


    printf("\n\n----------------Voy a testear Coeficientes----------------\n\n");
    printf("Ingrese un numero: ");
    scanf("%d",&num);
    InsBack(l1,num);

     printf("Ingrese un numero: ");
    scanf("%d",&num);
    InsBack(l1,num);

    printf("Ingrese un numero: ");
    scanf("%d",&num);
    InsBack(l1,num);

    printf("Ingrese un numero: ");
    scanf("%d",&num);
    InsBack(l1,num);

    tamanio=GetLargoCoeficientes(l1);
    printf("%d",tamanio);
    printf("\n");
    if (CoeficienteCeros(l1))
        printf("Coeficiente vacio");
    else
        ImprimeCoeficientes(l1,tamanio);

    printf("\n");
    printf("\n");
    printf("Ingrese un numero: ");
    scanf("%d",&num);
    InsBack(l2,num);

    printf("Ingrese un numero: ");
    scanf("%d",&num);
    InsBack(l2,num);

//    printf("Ingrese un numero: ");
//    scanf("%d",&num);
//    InsBack(l2,num);

    tamanio=GetLargoCoeficientes(l2);
    printf("%d",tamanio);
    printf("\n");
    if (CoeficienteCeros(l2))
        printf("Coeficiente vacio");
    else
        ImprimeCoeficientes(l2,tamanio);


    printf("\n");
    SumaCoeficiente(l1,l2,suma);
    tamanio=GetLargoCoeficientes(suma);

    printf("\nLa suma es: ");
    ImprimeCoeficientes(suma,tamanio);

    MultiplicaCoeficiente(l1,l2,mult);
    tamanio = GetLargoCoeficientes(mult);
    printf("\n%d",tamanio);

    printf("\n\n\nLa m es: ");
    ImprimeCoeficientes(mult,tamanio);
}
