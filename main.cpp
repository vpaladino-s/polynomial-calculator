#include "Comando.h"


int main()
{

    Polinomio_ABB arbol;
    CrearArbol(arbol);
    int resu ;
    do{
        printf("\n\nIngrese comando: ");

        Comando(arbol, resu);

        switch(resu){

            case 0   : printf("\nResultado: NO SE ENCONTRO COMANDO");
                       break;
            case 2   : printf("\nResultado: CANTIDAD DE PARAMETROS DEL COMANDO INCORRECTA");
                       break;
            case 3   : printf("\nResultado: NO SE PASARON COEFICIENTES");
                       break;
            case 4   : printf("\nResultado: EL COMANDO NO ADMITE COEFICIENTES");
                       break;
            case 5   : printf("\nResultado: NO HAY POLINOMIOS EN EL ARBOL");
                       break;
            case 6   : printf("\nResultado: EL NOMBRE DEL POLINOMIO YA EXISTE EN EL ARBOL");
                       break;
            case 7   : printf("\nResultado: HAY UNA LETRA ENTRE EN LOS COEFICIENTES");
                       break;
            case 8   : printf("\nResultado: EL PRIMER COEFICIENTE ES 0 Y EL POLINOMIO TIENE 2 O MAS ELEMENTOS");
                       break;
            case 9   : printf("\nResultado: EL POLINOMIO NO EXISTE EN EL ARBOL");
                       break;
            case 10  : printf("\nResultado: EL PRIMER POLINOMIO NO EXISTE EN EL ARBOL");
                       break;
            case 11  : printf("\nResultado: EL SEGUNDO POLINOMIO NO EXISTE EN EL ARBOL");
                       break;
            case 12  : printf("\nResultado: NINGUNO DE LOS POLINOMIOS EXISTEN EN EL ARBOL");
                       break;
            case 13  : printf("\nResultado: LOS PARAMETROS DEL COMANDO NO SON ALFANUMERICOS");
                       break;
            case 14  : printf("\nResultado: EL ARCHIVO NO TIENE EXTENSION .TXT");
                       break;
            case 15  : printf("\nResultado: SE CANCELO EL GUARDADO");
                       break;
            case 16  : printf("\nResultado: EL ARCHIVO NO EXISTE");
                       break;
        }


    }while(resu!=99);

}
