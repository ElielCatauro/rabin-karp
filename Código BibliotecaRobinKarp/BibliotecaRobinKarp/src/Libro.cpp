#include <iostream>
#include "Libro.h"


#include <string>

Libro::Libro(int id, int numEstanteria, int numEstante , std::string titulo,std::string editorial, std:: string autor ,std:: string genero , std::string subgenero ){
        this->id= id;
        this->numEstanteria=numEstanteria;
        this->numEstante = numEstante ;
        this->titulo=titulo;
        this->editorial=editorial;
         this->autor= autor;
        this->genero=genero ;
        this->subgenero= subgenero ;
        this->estado=true;

}

Libro::~Libro() {

}

       void Libro::impLibro(){
        std::cout<< id<< " | "<<numEstanteria<< " | "<< numEstante << " | "<<titulo<< " | "<<editorial<< " | "<<autor << " | "<< genero << " | "<< subgenero <<std::endl;
        }
/*
      void Libro::impLibro()  {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Numero de estanteria: " << numEstanteria << std::endl;
    std::cout << "Numero de estante: " << numEstante << std::endl;
    std::cout << "Titulo: " << titulo << std::endl;
    std::cout << "Editorial: " << editorial << std::endl;
    std::cout << "Autor: " << autor << std::endl;
    std::cout << "Genero: " << genero << std::endl;
    std::cout << "Subgenero: " << subgenero << std::endl;
    std::cout << "Estado: " << (estado ? "Disponible" : "No disponible") << std::endl;
    std::cout << "------------------------" << std::endl;
}

*/


bool Libro::buscarPalabra(std::string palabra,Buscador* buscadorInst ,bool tituloB, bool editorialB, bool autorB, bool generoB , bool subgeneroB )
{
    std::string aux="";
    if(tituloB){aux+=" "+this->titulo;
    }
    if(editorialB){aux+=" "+this->editorial;
    }
    if(autorB){aux+=" "+this->autor;
    }
    if(generoB){aux+=" "+this->genero;
    }
    if(subgeneroB){aux+=" "+this->subgenero;
    }


    return buscadorInst->contienePatron(palabra,aux) ;

}



//getters
         int Libro::getId() const {return id;}
         int Libro::getNumEstanteria() const {return numEstanteria;}
         int Libro::getNumEstante () const {return numEstante;}
         std::string Libro::getTitulo() const {return titulo;}
         std::string Libro::getEditorial() const{return editorial;}
         std:: string Libro::getAutor() const{return autor;}
         std:: string Libro::getGenero () const{return genero;}
         std::string Libro::getSubgenero () const{return subgenero;}
         bool Libro::getEstado() const{return estado;}

        //setters

         void Libro::setId(int id){this->id= id;}
         void Libro::setNumEstanteria(int numEstanteria){this->numEstanteria=numEstanteria;}
         void Libro::setNumEstante (int numEstante){this->numEstante = numEstante ;}
         void Libro::setTitulo(std::string titulo){   this->titulo=titulo;}
         void Libro::setEditorial(std::string editorial){   this->editorial=editorial;}
         void Libro::setAutor(std::string autor){this->autor= autor;}
         void Libro::setGenero (std::string genero) {   this->genero=genero ;}
         void Libro::setSubgenero (std::string subgenero) { this->subgenero= subgenero ;}
         void Libro::setEstado(bool estado){this->estado=estado;}
