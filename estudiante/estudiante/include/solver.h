#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <string>
#include <utility>
#include <vector>

#include "letters_set.h"
#include "dictionary.h"

using namespace std;

class Solver{
    private:
        Dictionary dictionary;
        LetterSet ls;

  //A completar
    public: // tienen que ser publicos para poder usarlos en el letras.cpp
        Solver(const Dictionary & dic, const LetterSet & letter) : dictionary(dic) , ls(letter){};
        vector<string> getSolutions(const vector<char>& available_letters, bool score_game);
        int puntosPalabra(string palabra);
        bool poderConstruir(string palabra, vector<char> available_letters);
        bool existe(string palabra);
};

#endif // __SOLVER_H__
