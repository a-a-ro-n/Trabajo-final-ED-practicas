#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <string>
#include <utility>
#include <vector>

#include "letters_set.h"
#include "dictionary.h"

using namespace std;

/**
 * @brief TDA Solver
 *
 * Esta clase se encarga de resolver el juego, encontrando soluciones válidas
 * en el diccionario a partir de un conjunto de letras disponibles.
 */
class Solver{
    private:
        Dictionary dictionary;
        LetterSet ls;

    public: // tienen que ser publicos para poder usarlos en el letras.cpp
        /**
         * @brief Constructor de la clase Solver
         * @param dic Diccionario con las palabras válidas
         * @param letter Conjunto de letras con sus puntuaciones
         */
        Solver(const Dictionary & dic, const LetterSet & letter) : dictionary(dic) , ls(letter){};

        /**
         * @brief Obtiene las soluciones posibles para una partida
         * * Busca palabras en el diccionario que se puedan formar con las letras disponibles.
         * @param available_letters Vector con las letras disponibles para jugar
         * @param score_game Booleano: true para jugar por puntuación, false para jugar por longitud
         * @return Vector de strings con las palabras encontradas que cumplen los criterios
         */
        vector<string> getSolutions(const vector<char>& available_letters, bool score_game);

        /**
         * @brief Calcula la puntuación de una palabra
         * @param palabra Palabra a evaluar
         * @return Puntuación total basada en el LetterSet asociado
         */
        int puntosPalabra(string palabra);

        /**
         * @brief Comprueba si una palabra se puede construir con un conjunto de letras
         * @param palabra La palabra candidata
         * @param available_letters Las letras disponibles en la mano
         * @return true si es posible construirla, false en caso contrario
         */
        bool poderConstruir(string palabra, vector<char> available_letters);

        /**
         * @brief Comprueba si una palabra existe en el diccionario del Solver
         * @param palabra Palabra a buscar
         * @return true si existe, false si no
         */
        bool existe(string palabra);
};

#endif // __SOLVER_H__
