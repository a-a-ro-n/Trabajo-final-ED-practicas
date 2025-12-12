#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "letters_set.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm> // para el find
#include <string>

using namespace std;

/**
 * @brief TDA LettersBag
 *
 * Esta clase representa una bolsa de letras que permite la extracción aleatoria
 * de caracteres, útil para generar manos de juego o secuencias aleatorias.
 */
class LettersBag {
    private:
        vector<char> bag;       // vector de letras
    
    public:
        /**
         * @brief Constructor de la clase LettersBag a partir de un LetterSet
         *
         * Rellena la bolsa con las letras definidas en el conjunto de letras proporcionado.
         * @param letterSet Conjunto de información de letras (LetterSet)
         */
        LettersBag(const LetterSet &);                  // pasamos el numero de letras, y el conjunto dnde estan las letras
        
        /**
         * @brief Constructor de la clase LettersBag a partir de un string
         * @param str Cadena de texto para inicializar la bolsa
         */ 
        LettersBag(const string &);                     // pasamos el numero de letras, y el conjunto dnde estan las letras

        /**
         * @brief Obtiene una letra de la bolsa en una posición específica
         * @param index Índice de la letra a recuperar
         * @return El carácter en la posición indicada
         */
        const char getLetter(int) const;                // conseguimos la letra
        
        // void setLetter(const char);                  // añadimos la letra a la bolsa   (no le veo mucho sentido que podamos añadir letras)

        /**
         * @brief Convierte el contenido de la bolsa a un string
         * @return Cadena con todas las letras de la bolsa
         */
        const string toString() const;                  // mostramos por pantalla todas las letras de la bolsa

        /**
         * @brief Obtiene el tamaño de la bolsa
         * @return Número de letras en la bolsa
         */
        unsigned size() const;

        /**
         * @brief Comprueba si la bolsa está vacía
         * @return true si está vacía, false en caso contrario
         */
        bool empty() const;

        /**
         * @brief Limpia el contenido de la bolsa
         */
        void clear();

        /**
         * @brief Elimina una ocurrencia de una letra específica de la bolsa
         * @param c Carácter a eliminar
         */
        void erase(const char);
        
        /**
         * @brief Iterador para recorrer la bolsa de letras
         */
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
    
    /**
     * @brief Devuelve un iterador al inicio de la bolsa
     */
    iterator begin();

    /**
     * @brief Devuelve un iterador al final de la bolsa
     */
    iterator end();
};

#endif
