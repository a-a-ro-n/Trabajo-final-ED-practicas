#include "letters_bag.h"

LettersBag(const int CANTIDAD_LETRAS, const LettersSet conjunto){  // pasamos el numero de letras, y el conjunto dnde estan las letras
    srand(time(NULL));      // para la obtencion de las letras aleatorias
    for(int i = 0; i < CANTIDAD_LETRAS; i++)
    {
        int indice = rand() % conjunto.size() + 1; // obtenemos el indice de una letra aleatoria, hay que pasarlo a la letra correspondinte
        
    }
}

const char getLetter() const;                   // conseguimos la letra
// void setLetter(const char);                  // añadimos la letra a la bolsa   (no le veo mucho sentido que podamos añadir letras)
const string toString();                        // mostramos por pantalla todas las letras de la bolsa
