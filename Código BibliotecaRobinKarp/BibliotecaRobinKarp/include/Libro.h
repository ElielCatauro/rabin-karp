#ifndef LIBRO_H
#define LIBRO_H
#include <string>
#include "Buscador.h"

class Libro
{
    public:
        Libro(int id, int numEstanteria, int numEstante , std::string titulo,std::string editorial, std:: string autor ,std:: string genero , std::string subgenero );
        virtual ~Libro();
        // definicion de metodos
        void impLibro();

       bool buscarPalabra(std::string palabra,Buscador* buscadorInst ,bool tituloB = true, bool editorialB = true, bool autorB = true, bool generoB = true, bool subgeneroB = true);


        //getters
         int getId() const ;
         int getNumEstanteria() const;
         int getNumEstante () const;
         std::string getTitulo() const;
         std::string getEditorial() const;
         std:: string getAutor() const;
         std:: string getGenero () const;
         std::string getSubgenero () const;
         bool getEstado() const;
        //setters

         void setId(int id);
         void setNumEstanteria(int numEstanteria) ;
         void setNumEstante (int numEstante);
         void setTitulo(std::string titulo);
         void setEditorial(std::string editorial);
         void setAutor(std::string autor) ;
         void setGenero (std::string genero) ;
         void setSubgenero (std::string subgenero) ;
         void setEstado(bool estado);

    protected:

    private:
         int id;
         int numEstanteria;
         int numEstante ;
         std::string titulo;
         std::string editorial;
         std:: string autor;
         std:: string genero ;
         std::string subgenero ;
         bool estado;
};

#endif // LIBRO_H
