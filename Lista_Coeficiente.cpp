#include "Lista_Coeficiente.h"

void CrearLista(Lista_Coeficiente &c)
{
    c=NULL;
}

boolean CoeficienteVacia(Lista_Coeficiente c)
{
    boolean es = FALSE;
    if (c == NULL)
        es = TRUE;
    return es;
}

int PrimerCoeficiente(Lista_Coeficiente c)
{
     return c -> info;
}

void RestoCoeficiente(Lista_Coeficiente &lis)
{
     Lista_Coeficiente aux = lis;
     lis = lis -> sig;
     delete aux;
}

void InsFront (Lista_Coeficiente &c, int n)
{
     Lista_Coeficiente aux = new nodo;
     aux -> info = n;
     aux -> sig = c;
     c = aux;
}

void InsBack (Lista_Coeficiente &c, int n)
{
    Lista_Coeficiente nuevo = new nodo;
    nuevo -> info = n;
    nuevo -> sig = NULL;
    if (c == NULL)
        c = nuevo;
    else{
        Lista_Coeficiente aux = c;
        while (aux -> sig != NULL)
            aux = aux -> sig;
        aux -> sig = nuevo;
    }
}

boolean CoeficienteCeros(Lista_Coeficiente l)
{
    boolean es=TRUE;
    while ((l!=NULL)&&(es)){
        if (l->info==0)
            l=l->sig;
        else
            es=FALSE;
    }
    return es;
}

int GetLargoCoeficientes(Lista_Coeficiente l)
{
    int cantidad=0;
    while(l!=NULL){
        cantidad++;
        l=l->sig;
    }
    return cantidad;
}

void ImprimeCoeficientes(Lista_Coeficiente l,int g)
{
    int i=0;
    int grado=0;
    while(l->sig!=NULL){
        if((l->info)>1){
            grado=g-i-1;
            if(grado!=1)
                printf(" +%dx%d",l->info,grado);
            else
                printf(" +%dx",l->info);
            i++;
            l=l->sig;
        }else
            if((l->info)<0){
                if((l->info)==-1){
                    grado=g-i-1;
                    if(grado!=1)
                        printf(" -x%d",grado);
                    else
                        printf(" -x");
                    i++;
                    l=l->sig;
                }else{
                    grado=g-i-1;
                    if(grado!=1)
                        printf(" %dx%d",l->info,grado);
                    else
                        printf(" %dx",l->info);
                    i++;
                    l=l->sig;
                }

            }else
                if((l->info)==1){
                    grado=g-i-1;
                    if (grado!=1)
                        printf(" +x%d",grado);
                    else
                        printf(" +x");
                    i++;
                    l=l->sig;
                }else{
                    l=l->sig;
                    i++;
                }
    }
    if((l->info)>0){
        printf(" +%d",l->info);
    }else{
         if ((l->info)<=0)
            printf(" %d",l->info);
        }
}

void BorrarCoeficiente(Lista_Coeficiente &c)
{
    if(c!=NULL){
        Lista_Coeficiente aux = c;
            delete aux;
            c = c->sig;
    	}
}

boolean MismoGrado(Lista_Coeficiente c1, Lista_Coeficiente c2)
{
    boolean son=FALSE;
    int largo1=GetLargoCoeficientes(c1);
    int largo2=GetLargoCoeficientes(c2);
    if (largo1 == largo2)
        son=TRUE;
    return son;
}

void SumaMenorGrado(Lista_Coeficiente l1,Lista_Coeficiente l2 ,Lista_Coeficiente &l3, int i)
{
    Lista_Coeficiente aux;
    CrearLista(aux);
    int n=0;
    int suma=0;
    while(n<i){
        InsBack(l3,l2->info);
        l2=l2->sig;
        n++;
    }
    while(l1!=NULL){
        suma = l1->info + l2->info;
        InsBack(l3,suma);
        l1 = l1->sig;
        l2 = l2->sig;
    }
}

void SumaIgualGrado(Lista_Coeficiente l1,Lista_Coeficiente l2,Lista_Coeficiente &l3)
{
    int suma=0;
    while (l1 != NULL) {
        suma = l1->info + l2->info;
        InsBack(l3,suma);
        l1 = l1->sig;
        l2 = l2->sig;
    }

}

void SumaCoeficiente(Lista_Coeficiente l1,Lista_Coeficiente l2,Lista_Coeficiente &resultado)
{
    int grado1=GetLargoCoeficientes(l1);
    int grado2=GetLargoCoeficientes(l2);
    int suma=0;
    int i=0;
    if(MismoGrado(l1,l2))
        SumaIgualGrado(l1,l2,resultado);
    else{
        if(grado1<grado2){
            SumaMenorGrado(l1,l2,resultado,grado2-grado1);
        }else{
            while(grado2<grado1){
                suma =l1->info;
                InsBack(resultado,suma);
                i++;
                grado1--;
                l1=l1->sig;
            }
                SumaIgualGrado(l2,l1,resultado);
        }
    }
}

int GetInfo(Lista_Coeficiente l){
    return l->info;
}


void MultiplicaCoeficiente(Lista_Coeficiente c1,Lista_Coeficiente c2,Lista_Coeficiente &resultado)
{
    int multiplicacion=0;
    Lista_Coeficiente auxcof1;
    Lista_Coeficiente auxc=c2;
    Lista_Coeficiente aux;
    CrearLista(aux);

    CrearLista(resultado);
    CrearLista(auxcof1);
    int largo = (GetLargoCoeficientes(c1)-1)+(GetLargoCoeficientes(c2)-1) + 1;
    int e = 1;
       while(c1!=NULL){
            auxcof1 = NULL;
            CrearLista(auxcof1);
            int cont = largo;
            while(c2!=NULL){
                multiplicacion = c1->info * c2->info;
                InsBack(auxcof1,multiplicacion);
                c2=c2->sig;
                cont--;
            }
            for(int i = 0;i<cont;i++)
                InsBack(auxcof1,0);
            largo--;
            c2=auxc;
            c1 = c1->sig;

            if(resultado!=NULL){
                aux = NULL;
                SumaMenorGrado(auxcof1,resultado,aux, e);
                BorrarCoeficiente(resultado);
                resultado = aux;
                e++;
            }else{
                resultado=auxcof1;
            }
        }
}

