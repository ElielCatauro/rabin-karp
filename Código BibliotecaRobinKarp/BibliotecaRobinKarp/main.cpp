#include <iostream>
#include <string>
#include "Libro.h"
#include "RobinKarp.h"

using namespace std;



void servicio1( Libro biblioteca[],int numLibros) {
    std::cout << "Seleccionaste el Servicio 1"<<std::endl;
     for(int i=0;i<numLibros;i++){
                biblioteca[i].impLibro();
        }
}

void servicio2(Libro biblioteca[],int numLibros,Buscador* buscadorInstancia) {
    std::cout << "Seleccionaste el Servicio 2"<<std::endl;
    std::string palabraBuscada;
    std::cout<<"ingrese la palabra que esta buscando en los libros "<<std::endl;
    cin>>palabraBuscada;


    for(int i=0;i<numLibros;i++){

        if(biblioteca[i].buscarPalabra(palabraBuscada,buscadorInstancia) ){
                 std::cout <<std::endl<<"-------------------------------------------- "<<std::endl<<std::endl;
                biblioteca[i].impLibro();
        }
    }
}

void servicio3(Libro biblioteca[],int numLibros,Buscador* buscadorInstancia) {
    std::cout << "Seleccionaste el Servicio 3"<<std::endl;
    std::string palabraBuscada;
    std::cout<<"Ingrese la palabra que esta buscando en los libros "<<std::endl;
    cin>>palabraBuscada;

    std::cout <<std::endl<< "A continuacion ingrese 1 = si     0 = no  "<<std::endl;

    bool tituloB, editorialB, autorB, generoB, subgeneroB;
    std::cout << "Buscar en titulo? (1/0): ";
    std::cin >> tituloB;
    std::cout << "Buscar en editorial? (1/0): ";
    std::cin >> editorialB;
    std::cout << "Buscar en autor? (1/0): ";
    std::cin >> autorB;
    std::cout << "Buscar en genero? (1/0): ";
    std::cin >> generoB;
    std::cout << "Buscar en subgenero? (1/0): ";
    std::cin >> subgeneroB;


    for(int i=0;i<numLibros;i++){

        if(biblioteca[i].buscarPalabra(palabraBuscada,buscadorInstancia, tituloB, editorialB, autorB, generoB, subgeneroB) ){
                 std::cout <<std::endl<<"-------------------------------------------- "<<std::endl<<std::endl;
                biblioteca[i].impLibro();
        }
    }

}

void servicio4(RobinKarp buscadorInstancia) {
        std::cout << "Seleccionaste el Servicio 4"<<std::endl;
        std::cout << "Ingresa el texto: ";
        std::cin.ignore(); // para limpiar lo que ingreso antes por teclado
        std::string textB;
        std::getline(std::cin, textB);

        std::cout << "Ingresa la palabra a buscar: ";
        std::string textA;
        std::getline(std::cin, textA);




        std::cout<<std::endl<<buscadorInstancia.encontrarPatronPasoPaso(textA,textB) <<std::endl;
        std::cin;
}




int main()
{  const int numLibros = 46;
    Libro biblioteca[numLibros] = {
        {1, 1, 1, "Caperucita Roja", "Lumen", "Charles Perrault", "Cuento de hadas", "Maerchen"},
        {2, 1, 1, "Hansel y Gretel", "Anaya", "Hermanos Grimm", "Cuento de hadas", "Maerchen"},
        {3, 1, 1, "La Sirenita", "Austral", "Hans Christian Andersen", "Cuento de hadas", "Kunstmaerchen"},
        {4, 1, 1, "El Gato con Botas", "Edelvives", "Charles Perrault", "Cuento de hadas", "Maerchen"},
        {5, 1, 2, "El Patito Feo", "Alfaguara", "Hans Christian Andersen", "Cuento de hadas", "Kunstmaerchen"},
        {6, 1, 2, "La Bella y la Bestia", "Vicens Vives", "Jeanne-Marie Leprince de Beaumont", "Cuento de hadas", "Maerchen"},
        {7, 1, 2, "Los Tres Cerditos", "SM", "Joseph Jacobs", "Cuento de hadas", "Maerchen"},
        {8, 1, 2, "Cenicienta", "Ediciones B", "Charles Perrault", "Cuento de hadas", "Maerchen"},
        {9, 1, 3, "Blancanieves y los Siete Enanitos", "RBA", "Hermanos Grimm", "Cuento de hadas", "Maerchen"},
        {10, 1, 3, "Peter Pan", "M. Moleiro Editor", "James Matthew Barrie", "Novela de fantasia", "Fantasia"},
        {11, 1, 3, "El Principito", "Salamandra", "Antoine de Saint-Exupery", "Novela de fantasia", "Fantasia"},
        {12, 1, 3, "Alicia en el Pais de las Maravillas", "Alianza Editorial", "Lewis Carroll", "Novela de fantasia", "Fantasia"},
        {13, 1, 4, "El Libro de la Selva", "Planeta Junior", "Rudyard Kipling", "Cuentos", "Aventura"},
        {14, 1, 4, "Las Aventuras de Tom Sawyer", "SM", "Mark Twain", "Novela de aventuras", "Aventura"},
        {15, 1, 4, "La Isla del Tesoro", "Austral", "Robert Louis Stevenson", "Novela de aventuras", "Aventura"},
        {16, 1, 4, "Veinte Mil Leguas de Viaje Submarino", "Anaya", "Julio Verne", "Novela de aventuras", "Aventura"},
        {17, 2, 1, "Don Quijote de la Mancha", "Espasa-Calpe", "Miguel de Cervantes", "Novela", "Ficcion"},
        {18, 2, 1, "El Lazarillo de Tormes", "Catedra", "Anonimo", "Novela picaresca", "Ficcion"},
        {19, 2, 1, "Platero y Yo", "Espasa-Calpe", "Juan Ramon Jimenez", "Novela lirica", "Ficcion"},
        {20, 2, 1, "La Celestina", "Austral", "Fernando de Rojas", "Tragicomedia", "Ficcion"},
        {21, 2, 2, "Hamlet", "Austral", "William Shakespeare", "Tragedia", "Teatro"},
        {22, 2, 2, "Romeo y Julieta", "Alianza Editorial", "William Shakespeare", "Tragedia", "Teatro"},
        {23, 2, 2, "Sueno de una Noche de Verano", "Catedra", "William Shakespeare", "Comedia", "Teatro"},
        {24, 2, 2, "El Mercader de Venecia", "Vicens Vives", "William Shakespeare", "Comedia", "Teatro"},
        {25, 2, 3, "El Quijote de los Ninos", "Edelvives", "Andres Trapiello", "Adaptacion infantil", "Ficcion"},
        {26, 2, 3, "Cuentos de la Alhambra", "Alianza Editorial", "Washington Irving", "Cuentos", "Romance"},
        {27, 2, 3, "Leyendas", "Austral", "Gustavo Adolfo Becquer", "Leyendas", "Romanticismo"},
        {28, 2, 3, "Fortunata y Jacinta", "Catedra", "Benito Perez Galdos", "Novela realista", "Ficcion"},
        {29, 2, 4, "Cien Anos de Soledad", "Penguin Random House", "Gabriel Garcia Marquez", "Realismo magico", "Ficcion"},
        {30, 2, 4, "La Casa de los Espiritus", "Planeta", "Isabel Allende", "Realismo magico", "Ficcion"},
        {31, 2, 4, "Rayuela", "Alfaguara", "Julio Cortazar", "Novela experimental", "Ficcion"},
        {32, 2, 4, "Hombres de Maiz", "Siglo XXI Editores", "Miguel Angel Asturias", "Novela indigenista", "Ficcion"},
        {33, 3, 1, "Crimen y Castigo", "Alianza Editorial", "Fiodor Dostoievski", "Novela psicologica", "Ficcion"},
        {34, 3, 1, "Ana Karenina", "Espasa-Calpe", "Leon Tolstoi", "Novela realista", "Ficcion"},
        {35, 3, 1, "Guerra y Paz", "Austral", "Leon Tolstoi", "Novela historica", "Ficcion"},
        {36, 3, 1, "Los Hermanos Karamazov", "Catedra", "Fiodor Dostoievski", "Novela filosofica", "Ficcion"},
        {37, 3, 2, "El Ulises", "Alianza Editorial", "James Joyce", "Novela vanguardista", "Ficcion"},
        {38, 3, 2, "La Metamorfosis", "Austral", "Franz Kafka", "Novela corta", "Ficcion"},
        {39, 3, 2, "El Proceso", "Alianza Editorial", "Franz Kafka", "Novela", "Ficcion"},
        {40, 3, 2, "El Extranjero", "Planeta", "Albert Camus", "Novela existencialista", "Ficcion"},
        {41, 3, 3, "1984", "Debolsillo", "George Orwell", "Novela distopica", "Ficcion"},
        {42, 3, 3, "Rebelion en la Granja", "Debolsillo", "George Orwell", "Fabula politica", "Ficcion"},
        {43, 3, 3, "Fahrenheit 451", "Minotauro", "Ray Bradbury", "Novela distopica", "Ficcion"},
        {44, 3, 3, "El Senor de los Anillos: La Comunidad del Anillo", "Minotauro", "J. R. R. Tolkien", "Novela de fantasia", "Fantasia"},
        {45, 3, 4, "El Senor de los Anillos: Las Dos Torres", "Minotauro", "J. R. R. Tolkien", "Novela de fantasia", "Fantasia"},
        {46, 3, 4, "El Senor de los Anillos: El Retorno del Rey", "Minotauro", "J. R. R. Tolkien", "Novela de fantasia", "Fantasia"}
    };

    RobinKarp buscadorInstancia;

     int opcion;

    do {

        std::cout << "==== Menu de Servicios ===="<<std::endl;
        std::cout << "1. Servicio 1: IMPRIMIR TABLA DE LIBROS"<<std::endl;
        std::cout << "2. Servicio 2: BUSQUEDA BASICA"<<std::endl;
        std::cout << "3. Servicio 3: BUSQUEDA AVANZADA"<<std::endl;
        std::cout << "4. Servicio 4: EJEMPLO PASO A PASO RABIN-KARP"<<std::endl;
        std::cout << "0. Salir"<<std::endl;
        std::cout << "=========================="<<std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        // Ejecuta la función correspondiente según la selección del usuario
        switch (opcion) {
            case 1:
                servicio1(biblioteca,numLibros);
                break;
            case 2:
                servicio2( biblioteca,numLibros,&buscadorInstancia);
                break;
            case 3:
                servicio3(biblioteca,numLibros,&buscadorInstancia);
                break;
            case 4:
                servicio4(buscadorInstancia);
                break;
            case 0:
                std::cout << "Saliendo del programa. "<<std::endl;
                break;
            default:
                std::cout << "Opcion no valida. Por favor, elija una opcion valida."<<std::endl;
                break;
        }

    } while (opcion != 0);

    return 0;
}
