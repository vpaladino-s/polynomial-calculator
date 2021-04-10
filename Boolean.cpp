#include "Boolean.h"

void CargarBool(boolean &b)
{
    int num;
    printf ("Ingrese 1 para TRUE ó 0 para FALSE: ");
    fflush (stdin);
    scanf ("%d", &num);
    if (num==1)
        b = TRUE;
    else
        b = FALSE;
}

void ImprimirBool(boolean b)
{
    if (b)
        printf ("VERDADERO");
    else
        printf ("FALSO");
}
