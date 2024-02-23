#ifndef BUSCADOR_H
#define BUSCADOR_H
#include <string>
class Buscador
{
    public:
        virtual bool contienePatron(std::string patron ,std::string texto)=0;
};

#endif // BUSCADOR_H
