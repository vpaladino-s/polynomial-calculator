#include "Polinomio.h"

/*Carga Polinomio*/
void CargarPolinomio(Polinomio &p, String s,Lista_Coeficiente c, int grado){
    p.nombre = s;
    p.c = c;
    p.grado = grado;

}

//Imprime Polinomio
void ImprimePolinomio(Polinomio p){
    //Imprimo nombre de polinomio con un procedimiento de String
    print(p.nombre);
    printf(" = ");
    //Imprimo los coeficientes con un procedimiento de Lista_coeficientes
    ImprimeCoeficientes(p.c, p.grado );
}

//Evalua el polinomio en x
int Evaluar(Polinomio p, int x){
    Lista_Coeficiente l = GetCoeficiente(p);
    int i = p.grado-1;
    int resultado = 0;
    if (i!=-1){
        while(l!=NULL){
            if(GetInfo(l) != 0){
                if(i > 0){
                    int e = i;
                    int xElevado = x;
                    while(e>1){
                        xElevado = xElevado * x;
                        e--;
                    }
                    resultado = resultado + (GetInfo(l) * xElevado);
                }else
                    resultado = resultado + GetInfo(l);
            }
            l = l -> sig;
            i--;
        }
    }else
        resultado=PrimerCoeficiente(l);
    return resultado;

}

//Imprime si r es raiz o no
void EsRaiz(Polinomio p, int r){
    int eva = Evaluar(p, r);
    if(eva == 0)
        printf("\n%d es raiz de ", r);
    else
        printf("\n%d no es raiz de ", r);
    print(p.nombre);
}


//Getter

//Devuelve el coeficiente
Lista_Coeficiente GetCoeficiente(Polinomio p){
    return p.c;
}

//Devuelve grado
int GetGrado(Polinomio p){
    return p.grado;
}

//Devuelve nombre
void GetNombre(Polinomio p, String &s){
    strcop(s, p.nombre);
}

//Setter
//Carga coeficiente con coeficiente dado
void SetCoeficiente(Polinomio &p,Lista_Coeficiente c){
    p.c = c;
}

//Carga grado con valor dado
void SetGrado(Polinomio &p,int g){
    p.grado = g;
}

//Carga nombre con string dado
void SetNombre(Polinomio &p, String s ){
    p.nombre = s;
}

void LiberaPolinomio(Polinomio p)
{
    strDestruir(p.nombre);
    BorrarCoeficiente(p.c);
}
