#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "letters_set.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm> // para el find
#include <string>

using namespace std;


class LettersBag {
    private:
        vector<char> bag;       // vector de letras
    
    public:
        LettersBag(const LetterSet &);                 // pasamos el numero de letras, y el conjunto dnde estan las letras
        const char getLetter(int) const;                // conseguimos la letra
        // void setLetter(const char);                  // añadimos la letra a la bolsa   (no le veo mucho sentido que podamos añadir letras)
        const string toString() const;                        // mostramos por pantalla todas las letras de la bolsa
        unsigned size() const;
        bool empty() const;
        void clear();
        void erase(const char);
        
        class iterator{
            private:
                vector<char>::iterator it;

            public:

                iterator();
                iterator(vector<char>::iterator);

                char & operator*(); // Devuelve una referencia al valor
                iterator & operator++();
                bool operator!=(const iterator &) const;
                bool operator==(const iterator &) const;

                friend LettersBag;
        };
    
    iterator begin();
    iterator end();
};

#endif
