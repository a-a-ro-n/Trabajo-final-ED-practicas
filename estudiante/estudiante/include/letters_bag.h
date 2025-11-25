#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "letters_set.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;


class LettersBag {
    private:
        char *bag; // array  dinamico de letras segun las repeticiones de dicha letra
        int cantidad_letras; // recuento de las letras totales de la bolsa

    public:
        LettersBag();
        const char getLetter() const;   // conseguimos la letra
        // void setLetter(const char);     // añadimos la letra a la bolsa   (no le veo mucho sentido que podamos añadir letras)
        const string toString();        // mostramos por pantalla todas las letras de la bolsa
};

#endif
