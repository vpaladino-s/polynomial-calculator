#include "Polinomio_ABB.h"

void CrearArbol(Polinomio_ABB &a)
{
    a=NULL;
}

boolean EsVacio(Polinomio_ABB a)
{
    boolean es=FALSE;
    if(a==NULL)
        es=TRUE;
    return es;
}

Polinomio DarRaiz(Polinomio_ABB a)
{
    return (a->info);
}

Polinomio_ABB HijoIzquierdo(Polinomio_ABB a)
{
    return (a->hizq);
}

Polinomio_ABB HijoDerecho(Polinomio_ABB a)
{
     return (a->hder);
}

void InsertarOrdenado(Polinomio_ABB &p, Polinomio q)
{
    if (p == NULL){
		p = new nodoPoli;
		p -> info = q;
		p -> hizq = NULL;
		p -> hder = NULL;
	}else{
		if (strmen(q.nombre,p->info.nombre))
			InsertarOrdenado(p->hizq,q);
		else
			InsertarOrdenado(p->hder,q);
    }
}


boolean Pertenece (Polinomio_ABB a, String s)
{
    if (a == NULL)
        return FALSE;
    else{
        String n;
        strCrear(n);
        GetNombre(a->info,n);
        if (streq(s,n))
            return TRUE;
        else{
             if(strmen(s,n))
                return Pertenece(a -> hizq,s);
             else
                return Pertenece (a -> hder,s);
        }
        strDestruir(n);
    }
}

void Borrar_Minimo (Polinomio_ABB &p)
{
    Polinomio_ABB aux;
    if (p -> hizq == NULL){
        aux = p -> hder;
        delete p;
        p = aux;
    }else
        Borrar_Minimo (p -> hizq);
}

void LiberarArbol (Polinomio_ABB &p)
{
    do{
       Borrar_Minimo(p);
    }while(!EsVacio(p));

}

Polinomio Buscar(Polinomio_ABB a, String s)
{
    String n;
    strCrear(n);
    GetNombre(a->info,n);
    if (streq(s,n))
        return a->info;
    else{
         if(strmen(s,n))
            return Buscar(a -> hizq,s);
         else
            return Buscar (a -> hder,s);
    }
    strDestruir(n);
}


//---------------COMANDOS-------------
void Mostrar(Polinomio_ABB p)   //imprime haciedo recorrida por orden
{
    if(p!=NULL){
        Mostrar(p->hizq);
        ImprimePolinomio(p->info);
        printf("\n                 ");
        Mostrar(p->hder);
    }

}

void Crear(Polinomio_ABB &p,Polinomio q)
{
    InsertarOrdenado(p,q);
}

void Sumar(Polinomio_ABB &p, Polinomio p1, Polinomio p2,String n)
{
    Lista_Coeficiente c;
    CrearLista(c);
    int g;
    SumaCoeficiente(GetCoeficiente(p1),GetCoeficiente(p2),c);
    g=GetLargoCoeficientes(c);
    Polinomio nuevoSuma;
    CargarPolinomio(nuevoSuma,n,c,g);
    Crear(p,nuevoSuma);
}

void Multiplicar(Polinomio_ABB &p, Polinomio p1, Polinomio p2,String n)
{
    Lista_Coeficiente c;
    int g;
    MultiplicaCoeficiente(GetCoeficiente(p1),GetCoeficiente(p2),c);
    g=GetLargoCoeficientes(c);
    Polinomio nuevoMultipli;
    CargarPolinomio(nuevoMultipli,n,c,g);
    Crear(p,nuevoMultipli);
}

