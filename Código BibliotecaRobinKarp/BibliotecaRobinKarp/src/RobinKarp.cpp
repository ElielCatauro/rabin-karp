#include "RobinKarp.h"
#include <cmath>

RobinKarp::RobinKarp()
{
    //ctor
}

RobinKarp::~RobinKarp()
{
    //dtor
}

bool RobinKarp::contienePatron(std::string patron ,std::string texto){


    int longiTexto=texto.length();
    int longiPatron= patron.length();
    int h=1;
    //inicializo h
    for(int i=0 ;  i<longiPatron-1 ; i++){ h=(h*base)  % numprimo;  }

    int valorNumPatron=0;
    int valorNumTo=0;

    for(int i=0 ; i< longiPatron; i++){
        valorNumPatron=(base*valorNumPatron+ tolower(patron[i])) % numprimo;
        valorNumTo=(base*valorNumTo+ tolower(texto[i])) % numprimo;
    }



    for( int j =0 ;j <= longiTexto-longiPatron ; j++){

        if  (valorNumTo== valorNumPatron){// comparar caracter por caracter

                   /*
                    if (patron== aMinuscula(texto.substr(j,longiPatron))) {   return true;
                    }*/

                    bool aux=true;
                    for(int k=0 ;k<longiPatron; k++) {
                            if(tolower(patron[k])!=tolower(texto[j+k])){aux=false;}
                    }
                    if(aux){return aux;}


        }

        //si los hash no son iguales entonces sigue iterando
        if( j < longiTexto-longiPatron){
            valorNumTo=(base* (valorNumTo - tolower(texto[j]) * h) + tolower(texto[j+longiPatron])) % numprimo;

            if (valorNumTo < 0) {
                valorNumTo += numprimo;  // Asegura que valorNumTo sea no negativo
            }



        }
    }



  return false;
}


//inicia el encontrarPatronPasoPaso

bool RobinKarp::encontrarPatronPasoPaso(std::string patron ,std::string texto){

    std::cout <<"Palabra buscada : "<<patron<<std::endl;
    std::cout <<"Texto donde busca "<<std::endl;
    std::cout <<texto<< std::endl;

    int longiTexto=texto.length();
    int longiPatron= patron.length();


    //inicializo h ="pow(base, longiPatron-1)%numprimo"
           std::cout <<  std::endl<<  std::endl<< " = = = = = = = = = = = = = = = = = = = = = = = = = = = =  "<<  std::endl<<std::endl;


    int h =1;
    for(int i=0 ;  i<longiPatron-1 ; i++)
    {
         h=(h*base)  % numprimo;
    }

    std::cout <<"se calcula H  =  ";
    std::cout <<" ["<< base  << " ^ ( "<<longiPatron <<"- 1) ] mod "<< numprimo <<" = " <<h <<std::endl;

           std::cout <<  std::endl<<  std::endl<< " = = = = = = = = = = = = = = = = = = = = = = = = = = = =  "<<  std::endl<<std::endl;



    int valorNumPatron=0;
    int valorNumTo=0;

    //++++
    std::string imrpPatUno="[";
    std::string imrpPatDos="";
    std::string imrpToUno="[";
    std::string imrpToDos="";
    //-------
    std::cout <<"Calculo del hash de el patron y primer ventana de texto "<<std::endl;
    for(int i=0 ; i< longiPatron; i++){
        //+++++
        imrpPatDos=imrpPatDos+"["+patron[i] +"="+ std::to_string(tolower(patron[i])) +"]        ";
        imrpPatUno=imrpPatUno+"(" +std::to_string(tolower(patron[i])) +"*("+std::to_string(base)+"^" +std::to_string(longiPatron - i - 1) +")) +";
        imrpToDos=imrpToDos+"["+texto[i] +"="+ std::to_string(tolower(texto[i])) +"]        ";
        imrpToUno=imrpToUno+"(" +std::to_string(tolower(texto[i])) +"*("+std::to_string(base)+"^" +std::to_string(longiPatron - i - 1) +")) +";
        //--------

        valorNumPatron=(base*valorNumPatron+ tolower(patron[i])) % numprimo;
        valorNumTo=(base*valorNumTo+ tolower(texto[i])) % numprimo;
    }
    //++++++
    std::cout <<"hash del patron = "<< valorNumPatron<<std::endl;;
    imrpPatUno.pop_back();
    imrpPatUno=imrpPatUno+ " ] mod " + std::to_string(numprimo);
     std::cout <<imrpPatDos<< std::endl;
     std::cout <<imrpPatUno<< std::endl;

     std::cout<<std::endl <<"-------------------------------------------- "<<std::endl<<std::endl;

    std::cout <<"hash primer ventana =  "<< valorNumTo<<std::endl;;
    imrpToUno.pop_back();
    imrpToUno=imrpToUno+ " ] mod " + std::to_string(numprimo);
    std::cout <<imrpToDos<< std::endl;
    std::cout <<imrpToUno<< std::endl;


    std::cout <<  std::endl<<  std::endl<< " = = = = = = = = = = = = = = = = = = = = = = = = = = = =  "<<  std::endl<<std::endl;


    //-------

    for( int j =0 ;j <= longiTexto-longiPatron ; j++){
        //Imprime la ventana actual
        std::cout <<"----------------- Desplasamiento Num "<< j<<" ----------------------- "<<std::endl;


        imrpToUno="[";
        imrpToDos="";
        for (int i = 0; i < longiPatron; i++) {
            imrpToDos=imrpToDos +"["+ texto[j + i] +"="+std::to_string( tolower(texto[j + i]))+"]        ";
            imrpToUno=imrpToUno+"(" +std::to_string( tolower(texto[j + i]))+ "*(" +std::to_string(base)+"^"+std::to_string(longiPatron - i - 1)+")) +";

         //   std::cout << "[" << (texto[j + i]) << " ]"<< "{" << tolower(texto[j + i]) << " * (" << base << " ^ " << (longiPatron - i - 1) << ") }"<< std::endl;

        }
            std::cout <<"hash ventana =  "<< valorNumTo<<std::endl;;
        imrpToUno.pop_back();
        imrpToUno=imrpToUno+ "] mod " + std::to_string(numprimo);
        std::cout <<imrpToDos<< std::endl;
        std::cout <<imrpToUno<< std::endl;



        if  (valorNumTo== valorNumPatron){// comparar caracter por caracter
                    std::cout <<"-------------------------------------------- "<<std::endl;
                    std::cout <<"Ambos hash son iguales y valen "<<valorNumPatron <<std::endl;
                    std::cout <<"Comapra si los textos son iguales caracter por caracter"<<std::endl;

                    bool aux=true;
                    for(int k=0 ;k<longiPatron; k++)
                     {
                            std::cout <<"patron : " << patron[k]<< "   texto  : " << texto[j+k] <<std::endl;
                            if(tolower(patron[k])!=tolower(texto[j+k])){aux=false;}
                    }
                    if(aux){return aux;}
        }



        //si los hash no son iguales entonces sigue iterando
        if( j < longiTexto-longiPatron){

            valorNumTo=(base* (valorNumTo - tolower(texto[j]) * h) + tolower(texto[j+longiPatron])) % numprimo;

            if (valorNumTo < 0) {
                valorNumTo += numprimo;
            }

        }


        std::cout <<  std::endl<<  std::endl<< " = = = = = = = = = = = = = = = = = = = = = = = = = = = =  "<<  std::endl<<std::endl;

    }


  return false;
}

//finaliza el encontrarPatronPasoPaso


std::string RobinKarp::aMinuscula(std::string  texto){
    std::string  cadena=texto;
    for (int i = 0; i < cadena.length(); i++) {
             cadena[i] = tolower(cadena[i]);
  }
return cadena;
}


