#include "String.h"

//Crea un string vacío (solo con el carácter ‘\0’)
void strCrear(String &s){
    s = new char[1];
    s[0] = '\0';
}

//Libera la memoria ocupada por el string y lo deja nulo.
void strDestruir(String &s){
    delete[] s;
    s = NULL;

}

int strlar(String s)
{
    int i=0;
    while(s[i]!= '\0'){
        i++;
    }
    return i;
}

void strcop(String &str1,String str2)
{
    int i=0;
    int largo = strlar(str2);
    strDestruir(str1);
    str1 = new char[largo+1];
    while(str2[i]!='\0'){
        str1[i]=str2[i];
        i++;
    }
    str1[i]='\0';
}

void scan(String &palabra)
{
    String aux = new char[MAX];
    char caracter;
    int i;
    fflush(stdin);
    scanf("%c",&caracter);
    i=0;
    while((caracter!='\n') && (i<MAX-1)){
        aux[i]=caracter;
        i++;
        scanf("%c",&caracter);
    }
    aux[i]='\0';
    strcop(palabra,aux);
    strDestruir(aux);
}

void strcon(String &str1,String str2)
{
    int largo = strlar(str1) + strlar(str2) + 1;
    if(largo>=80)
        largo = MAX-1;
    String aux = new char[largo];
    int i=0,j=0;
    while(str1[i]!='\0'){
        aux[i] = str1[i];
        i++;
    }
    while (i<largo){
            aux[i]=str2[j];
            i++;
            j++;
    }
    aux[i]='\0';
    strDestruir(str1);
    str1 = aux;
}

void strswp(String &str1,String &str2)
{
    String aux = str1;
    str1 = str2;
    str2 = aux;
}

void print(String s)
{
    int i;
    i=0;
    while(s[i]!='\0'){
        printf("%c",s[i]);
        i++;
    }
}



boolean strmen(String str1,String str2)
{
    int i=0;
    boolean esmenor=FALSE,iguales, determine;
    determine = FALSE;
    iguales=streq(str1,str2);
    if(!iguales){
        while(!determine && str1[i]!='\0' && str2[i]!='\0'){
            if(str1[i]<str2[i]){
                esmenor = TRUE;
                determine = TRUE;
            }else{
                if(str1[i]!=str2[i])
                    determine = TRUE;
            }
            i++;
        }
    }

    return esmenor;
}

boolean streq(String str1,String str2)
{
    int i=0;
    boolean iguales;
    iguales=TRUE;
    while((str1[i]!='\0')&&(iguales)){
        if(str1[i]==str2[i])
            i++;
        else
            iguales=FALSE;
    }
    if(str2[i]!='\0'){
        iguales=FALSE;
    }
   return iguales;
}

int strCantPalabras(String s){
    int i = 0;
    int resu = 0;
    while(s[i]!='\0'){
        if(s[i]!=' ' && s[i+1]==' '){
            resu++;
        }else
            if(s[i]!=' '&& s[i+1]=='\0')
                resu++;
        i++;
    }
    return resu;
}



char strDevuelvePos(String s, int pos){
    char a = s[pos];
    return a;
}

void strSetPos(String s, char c ,int pos){
    s[pos] = c;
}
