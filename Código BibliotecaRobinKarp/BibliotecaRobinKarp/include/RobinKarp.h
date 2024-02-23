#ifndef ROBINKARP_H
#define ROBINKARP_H
#include "Buscador.h"
#include <string>
#include <iostream>

class RobinKarp : public Buscador
{
    public:
        RobinKarp();
        virtual ~RobinKarp();

    bool contienePatron(std::string patron ,std::string texto);
    bool encontrarPatronPasoPaso(std::string patron ,std::string texto);
    protected:

    private:
          int base=256;                 // craacteres en ascci
          int numprimo=1103; // numeros primos para probar  5 , 101 , 1103
          std::string aMinuscula(std::string  texto);

};

#endif // ROBINKARP_H
