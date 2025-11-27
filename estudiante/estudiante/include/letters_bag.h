#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "letters_set.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include

using namespace std;


class LettersBag {
    private:
        vector<char> bag;       // vector de letras
        // int cantidad_letras; // recuento de las letras totales de la bolsa (no es necesario ya que existe .size())
    
    public:
        LettersBag(const LettersSet &);                 // pasamos el numero de letras, y el conjunto dnde estan las letras
        const char getLetter(int) const;                // conseguimos la letra
        // void setLetter(const char);                  // añadimos la letra a la bolsa   (no le veo mucho sentido que podamos añadir letras)
        const string toString();                        // mostramos por pantalla todas las letras de la bolsa
        const unsigned size() const;
        const bool empty() const;
        void clear();
        void erease(const char);
        
        class iterator{
            private:
                vector<char>::iterator it;

            public:
                

            friend LetterBag;
        };
};

#endif
