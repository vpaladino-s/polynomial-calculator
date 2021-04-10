#include "Archivo.h"

void GuardarEntero(int n, FILE * f)
{
    fwrite (&n, sizeof (int), 1, f);
}

void GuardarLista(Lista_Coeficiente c, FILE * f)
{
    while (c!= NULL){
        GuardarEntero(c->info, f);
        c=c->sig;
    }
}

void LevantarEntero(int &n, FILE * f)
{
    fread (&n, sizeof(int), 1, f);
}

void LevantarLista(Lista_Coeficiente &c, FILE * f)
{
    int num;
    LevantarEntero(num, f);
    CrearLista(c);
    if(!feof(f)){
         c = new nodo;
         c -> info = num;
         c -> sig = NULL;
    }
    Lista_Coeficiente aux = c ;
    LevantarEntero(num, f);
    while (!feof(f)){
        aux -> sig = new nodo;
        aux = aux -> sig;
        aux->info=num;
        LevantarEntero(num, f);
    }
    aux->sig = NULL;
}


// Determina si el archivo está vacío o no. Precondición: El archivo existe
boolean ArchivoVacio(String nomArchivo){

        boolean resu = TRUE;
        FILE * f = fopen(nomArchivo, "rb");
        fseek(f,0,SEEK_END);
        long int largo = ftell(f);
        if(largo != 0)
                resu = FALSE;
        fclose(f);
        return resu;

}


/*Precondicion el nombre polinomio pertenece al arbol*/
void Guardar(Polinomio p,String nomArchivo)
{
    FILE * f = fopen (nomArchivo, "wb");
    fwrite(&p.grado, sizeof (int), 1, f);
    GuardarLista(p.c,f);
    fclose (f);

}


void Recuperar(Polinomio &p,String nomArchivo)
{
    FILE * f = fopen (nomArchivo, "rb");
    LevantarEntero(p.grado,f);
    LevantarLista(p.c,f);
    fclose (f);

}

boolean ExisteArchivo(String nomArchivo)
{
    boolean existe=TRUE;
    FILE *f=fopen(nomArchivo,"rb");
    if(f==NULL)
        existe=FALSE;
    return existe;

}
