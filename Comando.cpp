#include "Comando.h"

void Comando(Polinomio_ABB &arbol, int &resu){

    String s;
    strCrear(s);
    scan(s);

    Arreglo_String as ;
    Lista_Coeficiente lc;
    CrearLista(lc);
    int largoarre= strCantPalabras(s);
    CrearArreglo(as,largoarre);
    int errorSplit = SplitString(s, as);
    String com ;
    strCrear(com);
    GetElemento(as,0, com);
    resu = 0;

    String screar=new char[6];
    strSetPos(screar,'c',0);strSetPos(screar,'r',1);strSetPos(screar,'e',2);strSetPos(screar,'a',3);strSetPos(screar,'r',4);strSetPos(screar,'\0',5);

    String smostrar=new char[8];
    strSetPos(smostrar,'m',0);strSetPos(smostrar,'o',1);strSetPos(smostrar,'s',2);strSetPos(smostrar,'t',3);strSetPos(smostrar,'r',4);strSetPos(smostrar,'a',5);strSetPos(smostrar,'r',6);strSetPos(smostrar,'\0',7);

    String ssumar=new char[6];
    strSetPos(ssumar,'s',0);strSetPos(ssumar,'u',1);strSetPos(ssumar,'m',2);strSetPos(ssumar,'a',3);strSetPos(ssumar,'r',4);strSetPos(ssumar,'\0',5);

    String smultiplicar=new char[12];
    strSetPos(smultiplicar,'m',0);strSetPos(smultiplicar,'u',1);strSetPos(smultiplicar,'l',2);strSetPos(smultiplicar,'t',3);strSetPos(smultiplicar,'i',4);strSetPos(smultiplicar,'p',5);strSetPos(smultiplicar,'l',6);;strSetPos(smultiplicar,'i',7);strSetPos(smultiplicar,'c',8);;strSetPos(smultiplicar,'a',9);strSetPos(smultiplicar,'r',10);strSetPos(smultiplicar,'\0',11);

    String sevaluar=new char[8];
    strSetPos(sevaluar,'e',0);strSetPos(sevaluar,'v',1);strSetPos(sevaluar,'a',2);strSetPos(sevaluar,'l',3);strSetPos(sevaluar,'u',4);strSetPos(sevaluar,'a',5);strSetPos(sevaluar,'r',6);strSetPos(sevaluar,'\0',7);

    String sesraiz=new char[7];
    strSetPos(sesraiz,'e',0);strSetPos(sesraiz,'s',1);strSetPos(sesraiz,'r',2);strSetPos(sesraiz,'a',3);strSetPos(sesraiz,'i',4);strSetPos(sesraiz,'z',5);strSetPos(sesraiz,'\0',6);

    String srecuperar=new char[10];
    strSetPos(srecuperar,'r',0);strSetPos(srecuperar,'e',1);strSetPos(srecuperar,'c',2);strSetPos(srecuperar,'u',3);strSetPos(srecuperar,'p',4);strSetPos(srecuperar,'e',5);strSetPos(srecuperar,'r',6);strSetPos(srecuperar,'a',7);strSetPos(srecuperar,'r',8);strSetPos(srecuperar,'\0',9);

    String ssalir=new char[6];
    strSetPos(ssalir,'s',0);strSetPos(ssalir,'a',1);strSetPos(ssalir,'l',2);strSetPos(ssalir,'i',3);strSetPos(ssalir,'r',4);strSetPos(ssalir,'\0',5);

    String sguardar=new char[8];
    strSetPos(sguardar,'g',0);strSetPos(sguardar,'u',1);strSetPos(sguardar,'a',2);strSetPos(sguardar,'r',3);strSetPos(sguardar,'d',4);strSetPos(sguardar,'a',5);strSetPos(sguardar,'r',6);strSetPos(sguardar,'\0',7);

    /*
    Resultados posibles de comando
    resu = 0   ->    NO SE ENCONTRO COMANDO
    resu = 1   ->    OK
    resu = 2   ->    CANTIDAD DE PARAMETROS DEL COMANDO INCORRECTA
    resu = 3   ->    NO SE PASARON COEFICIENTES
    resu = 4   ->    EL COMANDO NO ADMITE COEFICIENTES
    resu = 5   ->    NO HAY POLINOMIOS EN EL ARBOL
    resu = 6   ->    EL NOMBRE DEL POLINOMIO YA EXISTE EN EL ARBOL
    resu = 7   ->    HAY UNA LETRA ENTRE EN LOS COEFICIENTES
    resu = 8   ->    EL PRIMER COEFICIENTE ES 0 Y EL POLINOMIO TIENE 2 O MAS ELEMENTOS
    resu = 9   ->    EL POLINOMIO NO EXISTE EN EL ARBOL
    resu = 10  ->    EL PRIMER POLINOMIO NO EXISTE EN EL ARBOL
    resu = 11  ->    EL SEGUNDO POLINOMIO NO EXISTE EN EL ARBOL
    resu = 12  ->    NINGUNO DE LOS POLINOMIOS EXISTEN EN EL ARBOL
    resu = 13  ->    LOS PARAMETROS DEL COMANDO NO SON ALFANUMERICOS
    resu = 14  ->    EL ARCHIVO NO TIENE EXTENSION .TXT
    resu = 15  ->    SE CANCELO EL GUARDADO
    resu = 16  ->    EL ARCHIVO NO EXISTE
    resu = 99  ->    SALIR
    */

    if(errorSplit==0 || (errorSplit ==2 && (streq(com,sguardar) || streq(com,srecuperar)))){
        //Crea un nuevo polinomio especificando todos sus coeficientes
        if(streq(com,screar)){
            Polinomio p;
            if(largoarre>2){
                int codError = SplitCoeficiente(as,lc,2);
                if(codError == 1){
                    resu = 7;
                }else{
                    if(codError==2){
                        resu=8;
                    }else{
                        String nombre;
                        strCrear(nombre);
                        GetElemento(as,1,nombre);
                        if(!Pertenece(arbol,nombre)){
                            CargarPolinomio(p, nombre,lc, GetLargoCoeficientes(lc) );
                            InsertarOrdenado(arbol,p);
                            printf("\nResultado:       ");
                            ImprimePolinomio(p);
                            resu = 1;
                        }else{
                            resu = 6;
                        }
                    }
                }
            }else{
                if(largoarre == 2)
                    resu = 3;
                else
                    resu = 2;
            }
        //Realiza la suma de dos polinomios, creando uno nuevo como resultado
        }else{
            if(streq(com,ssumar)){
                if(largoarre==4){
                    String nombreSuma;
                    strCrear(nombreSuma);
                    GetElemento(as,1,nombreSuma);
                    if(!Pertenece(arbol, nombreSuma)){
                        String nombre1, nombre2;
                        strCrear(nombre1);
                        GetElemento(as,2,nombre1);
                        strCrear(nombre2);
                        GetElemento(as,3,nombre2);
                        if(!Pertenece(arbol, nombre1)){
                                resu =10;
                           if(!Pertenece(arbol, nombre2))
                                resu = 12;
                        }else{
                            if(!Pertenece(arbol, nombre2))
                                resu = 11;
                            else{
                                Polinomio suma;
                                Sumar(arbol, Buscar(arbol,nombre1), Buscar(arbol,nombre2), nombreSuma);
                                resu = 1;
                            	suma=Buscar(arbol,nombreSuma);
                            	printf("\nResultado:       ");
                            	ImprimePolinomio(suma);
                            }
                        }
                        strDestruir(nombre1);
                        strDestruir(nombre2);
                    }else{
                        resu = 6;
                    }
                }else{
                    resu = 2;
                }
            //Realiza la multiplicación de dos polinomios, creando uno nuevo como resultado
            }else{
                if(streq(com,smultiplicar)){
                    if(largoarre==4){
                        String nombreMulti;
                        strCrear(nombreMulti);
                        GetElemento(as,1,nombreMulti);
                        if(!Pertenece(arbol, nombreMulti)){
                            String nombre1, nombre2;
                            strCrear(nombre1);
                            GetElemento(as,2,nombre1);
                            strCrear(nombre2);
                            GetElemento(as,3,nombre2);
                            if(!Pertenece(arbol, nombre1)){
                                    resu =10;
                               if(!Pertenece(arbol, nombre2))
                                    resu = 12;
                            }else{
                                if(!Pertenece(arbol, nombre2))
                                    resu = 11;
                                else{
                                    Polinomio mult;
                                    Multiplicar(arbol, Buscar(arbol,nombre1), Buscar(arbol,nombre2), nombreMulti);
                                    resu = 1;
                                    mult=Buscar(arbol,nombreMulti);
                                    printf("\nResultado:       ");
                                    ImprimePolinomio(mult);
                                }
                            }
                            strDestruir(nombre1);
                            strDestruir(nombre2);
                        }else{
                            resu = 6;
                        }
                    }else{
                        resu = 2;
                    }
                //Realiza la evaluación para un polinomio en un valor entero dado
                }else{
                    if(streq(com,sevaluar)){
                        if(largoarre==3){
                            String nombre;
                            strCrear(nombre);
                            GetElemento(as,1,nombre);
                            if(Pertenece(arbol, nombre)){
                                int codError = SplitCoeficiente(as,lc,2);
                                if(codError== 0 && lc==NULL){
                                    resu = 3;
                                }else{
                                    if(codError == 1){
                                        resu = 7;
                                    }else{
                                        if(codError==2){
                                            resu=8;
                                        }else{
                                            int resultado = Evaluar(Buscar(arbol,nombre),GetInfo(lc));
                                        resu = 1;
                                            printf("\nResultado:       %d", resultado);
                                        }
                                    }
                                }
                            }else{
                                resu = 9;
                            }
                            strDestruir(nombre);
                        }else{
                            resu = 2;
                        }
                    //Muestra por pantalla if(un número entero dado es raíz de un polinomio
                    }else{
                        if(streq(com,sesraiz)){
                            if(largoarre==3){
                                String nombre;
                                strCrear(nombre);
                                GetElemento(as,1,nombre);
                                if(Pertenece(arbol, nombre)){
                                    int codError = SplitCoeficiente(as,lc,2);
                                    if(codError== 0 && lc==NULL){
                                        resu = 3;
                                    }else{
                                        if(codError == 1){
                                            resu = 7;
                                        }else{
                                            if(codError==2){
                                                resu=8;
                                            }else{
                                                int resultado = Evaluar(Buscar(arbol,nombre),GetInfo(lc));
                                                if (resultado==0){

                                                    printf("\nResultado:       es raiz");
                                                    resu = 1;
                                                }else{
                                                    printf("\nResultado:       no es raiz");
                                                    resu = 1;
                                                }
                                            }
                                        }
                                    }
                                }else{
                                    resu = 9;
                                }
                                strDestruir(nombre);
                            }else{
                                resu = 2;
                            }
                        //Muestra por pantalla todos los polinomios existentes en memoria
                        }else{
                            if(streq(com,smostrar)){
                                if(largoarre==1){
                                    if(EsVacio(arbol)){
                                        resu = 5;
                                    }else{
                                        if(largoarre>1){
                                            resu = 2;
                                        }else{
                                            printf("\nResultado:       ");
                                            Mostrar(arbol);
                                            resu = 1;
                                        }
                                    }
                                }else{
                                    resu = 2;
                                }

                            //Guarda en archivo un polinomio existente en memoria
                            }else{
                                if(streq(com,sguardar)){
                                    if(largoarre==3){
                                        String nombre;
                                        strCrear(nombre);
                                        GetElemento(as,1,nombre);
                                        if(Pertenece(arbol, nombre)){
                                            String nombreArchivo;
                                            strCrear(nombreArchivo);
                                            GetElemento(as,2,nombreArchivo);
                                            int largoNombre = strlar(nombreArchivo);
                                            if(strDevuelvePos(nombreArchivo,largoNombre-4) == 46 && strDevuelvePos(nombreArchivo,largoNombre-3) == 116 && strDevuelvePos(nombreArchivo,largoNombre-2) == 120 && strDevuelvePos(nombreArchivo,largoNombre-1) == 116){
                                                if(!ExisteArchivo(nombreArchivo)){
                                                    Guardar(Buscar(arbol,nombre),nombreArchivo);
                                                    printf("\nResultado:       polinomio almacenado correctamente en ");
                                                    print(nombreArchivo);
                                                    resu=1;
                                                }else{
                                                    printf("\nDesea suscribir el archivo ya existente?\n\nEscriba 'si' o 'no' : ");
                                                    String opcion;
                                                    strCrear(opcion);
                                                    scan(opcion);
                                                    //Reviso si la opcion es si
                                                    if(strDevuelvePos(opcion,0) == 115 && strDevuelvePos(opcion,1) == 105 ){
                                                        Guardar(Buscar(arbol,nombre),nombreArchivo);
                                                        printf("\nResultado:       polinomio almacenado correctamente en ");
                                                        print(nombreArchivo);
                                                        resu=1;
                                                    }else{
                                                        resu = 15;
                                                    }
                                                }
                                            }else{
                                                resu = 14;
                                            }
                                            strDestruir(nombreArchivo);
                                        }else
                                            resu=9;
                                        strDestruir(nombre);
                                    }else{
                                        resu = 2;
                                    }
                                //Recupera a memoria un polinomio previamente guardado en archivo
                                }else{
                                    if(streq(com,srecuperar)){
                                        if(largoarre==3){
                                            String nombre;
                                            strCrear(nombre);
                                            GetElemento(as,1,nombre);
                                            int p = 0;
                                            char caracter = strDevuelvePos(nombre, p);
                                            boolean tienePunto = FALSE;
                                            while(caracter!='\0' && !tienePunto){
                                                if(caracter==46){
                                                    tienePunto = TRUE;
                                                }
                                                p++;
                                                caracter = strDevuelvePos(nombre, p);
                                            }
                                            if(!tienePunto){
                                                if(!Pertenece(arbol, nombre)){
                                                    String nombreArchivo;
                                                    strCrear(nombreArchivo);
                                                    GetElemento(as,2,nombreArchivo);
                                                    int largoNombre = strlar(nombreArchivo);
                                                    if(strDevuelvePos(nombreArchivo,largoNombre-4) == 46 && strDevuelvePos(nombreArchivo,largoNombre-3) == 116 && strDevuelvePos(nombreArchivo,largoNombre-2) == 120 && strDevuelvePos(nombreArchivo,largoNombre-1) == 116){
                                                        if(ExisteArchivo(nombreArchivo)){
                                                            Polinomio p;
                                                            Recuperar(p, nombreArchivo);
                                                            SetNombre(p, nombre);
                                                            Crear(arbol, p);
                                                            resu = 1;
                                                            printf("\nResultado:       ");
                                                            ImprimePolinomio(p);
                                                        }else{
                                                           resu = 16;
                                                        }
                                                    }else{
                                                        resu = 14;
                                                    }
                                                    strDestruir(nombreArchivo);
                                                }else{
                                                    resu = 6;
                                                }
                                            }else{
                                                resu = 13;
                                            }
                                        }else{
                                            resu = 2;
                                        }
                                    //Abandona la aplicación, libera la memoria y sale
                                    }else if(streq(com,ssalir)){
                                    	if(!EsVacio(arbol)){
                                      		LiberarArbol(arbol);
                                      		DestruirArreglo(as);
                                      		BorrarCoeficiente(lc);
                                      		printf("\nResultado:       Hasta la proxima!\n\n");
                                    	}else{
                                        	printf("\nResultado:       Hasta la proxima!\n\n");
                                    	}
                                        resu = 99;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else{
        resu = 13;
    }
    strDestruir(com);
    strDestruir(screar);
    strDestruir(smostrar);
    strDestruir(ssumar);
    strDestruir(smultiplicar);
    strDestruir(sevaluar);
    strDestruir(sesraiz);
    strDestruir(sguardar);
    strDestruir(srecuperar);
    strDestruir(ssalir);
    strDestruir(s);
}

    //Encuentra espacio y va guardando strings en el arreglo
    int SplitString (String s, Arreglo_String  &a)
    {
        int q=0, i=0, r=0;
        String aux = new char[MAX];
        strSetPos(aux,'\0',0);
        String guardo;
        int error = 0;
        char c = strDevuelvePos(s,q);
        while(c != '\0' && (error==0 || error ==2)){
            if(c!=' '){
                //Valido que sean letras y números, si pasan un punto a guión reviso en que lugar o aviso a comando para que termine la validación
                if((c==45 && i>=2) || (c>=48 && c<58) || (c>=65 && c<91) || (c>=97 && c<123) || c==46){
                    strSetPos(aux,c,r);
                    //Valido si hay un punto
                    if(c==46)
                        error = 2;
                    q++;
                    r++;
                }else{
                    error = 1;
                }
            }else{
                if(strlar(aux)!=0){
                    strSetPos(aux,'\0',r);
                    strCrear(guardo);
                    strcop(guardo,aux);
                    CargarArreglo(a,guardo,i);
                    strDestruir(aux);
                    aux = new char[MAX];
                    strSetPos(aux,'\0',0);
                    i++;
                }
                while(c==' '&& c!='\0'){
                    q++;
                    c = strDevuelvePos(s,q);
                }
                r=0;
            }
            c = strDevuelvePos(s,q);
        }
        strSetPos(aux,'\0',r);
        strCrear(guardo);
        strcop(guardo,aux);
        CargarArreglo(a,guardo,i);
        strDestruir(aux);

        return error;
    }

    //Encuentra numeros y los va clocando la lista.
    int SplitCoeficiente(Arreglo_String s,Lista_Coeficiente &c, int pos){
        //Valido que se hallan ingresado coeficientes
        int error = 0;
        String elemento;
        strCrear(elemento);
        GetElemento(s,pos,elemento);
        if(elemento!=NULL){
            int i = pos;
            int tam = GetTamanio(s);
            while(i<tam && error == 0){
                    GetElemento(s,i,elemento);
                    int z=0;
                    int aux = 0;
                    int largoNum = strlar(elemento);
                    int total=0;
                    int negativo=1;
                    char car = strDevuelvePos(elemento,z);
                    while(car!='\0' && error == 0){
                        if ( car>=48 && car<58){
                            aux = (int)car - 48;
                            for(int v = 1; v<largoNum;v++){
                                aux= aux*10;
                            }
                            largoNum--;
                            total = total + aux;
                            z++;
                        }else{
                            if(car==45 && z==0){
                                negativo = -1;
                                largoNum--;
                                z++;
                            }else{
                                //Hay una letra entre en los coeficentes
                                error = 1;
                            }
                        }
                        car = strDevuelvePos(elemento,z);
                    }
                    if(total==0 && i==pos && (tam>pos+1) && error==0){
                        //El primer coeificiente es 0 y el polinomio tiene 2 o más elementos
                        error = 2;
                    }else{
                        total = total * negativo;
                        InsBack(c,total);
                    }
                    i++;
                    strDestruir(elemento);
            }
        }

    return error;
}


