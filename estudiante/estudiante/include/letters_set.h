#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <iostream>
#include <string>
#include <fstream> // para la apertura del archivo y extraccion de letras
#include <map>
#include <stdlib.h> // para exit()

using namespace std;

/**
 * @brief Estructura para almacenar información sobre una letra
 */
struct LetterInfo{
  unsigned int repetitions;
  unsigned int score;

  /**
   * @brief Constructor por defecto
   */
  LetterInfo(): repetitions(0), score(0){}

  /**
   * @brief Constructor con parámetros
   *
   * @param reps Número de repeticiones del carácter en la partida
   * @param score Puntuación del carácter
   */
  LetterInfo(unsigned int reps, unsigned int score): repetitions(reps), score(score){};
};

/**
 * @brief TDA LetterSet
 *
 * Esta clase gestiona un conjunto de letras, asociando a cada carácter
 * su información de juego (repeticiones permitidas y puntuación).
 */
class LetterSet{
    private:
        map<char, LetterInfo> charSet;  // mapeado de las letras

    public:
        /*
         * @bief Constructor por defecto
         * 
         * @param se pasara por referencia el nombre del archivo a abrir
         */
        LetterSet(const string &); // abriremos el archivo para la extraccion de las letras

        /**
         * @brief Getter de la información de la letra
         *
         * @param val Carácter del cual se quiere obtener la información
         * @return Devuelve la informacion (LetterInfo) de la letra en el conjunto
         */
        const LetterInfo getLetterInfo(char) const;
        
        // void setLetter(map<char,LetterInfo>); // inecesaria implementacion
        
        /**
         * @brief Comprueba si el conjunto está vacío
         * @return true si no hay letras, false en caso contrario
         */
        bool empty() const;

        /**
         * @brief Obtiene el tamaño del conjunto (número de tipos de letras distintas)
         * @return Entero con el tamaño
         */
        unsigned size() const;
        
        /**
         * @brief Iterador para recorrer el conjunto de letras
         */
        class iterator {
            private:
                map<char, LetterInfo>::iterator it;

            public:

                iterator();
                iterator(map<char, LetterInfo>::iterator );
                
                pair<const char, LetterInfo> & operator*(); // Devuelve una referencia al par clave-valor del mapa
                pair<const char, LetterInfo> * operator->(); 

                iterator & operator++();
                bool operator!=(const iterator &) const;
                bool operator==(const iterator &) const;

                friend class LetterSet; 
        };

        /**
         * @brief Iterador constante para recorrer el conjunto de letras
         */
        class const_iterator { // me salio un error y por eso lo implemente
            private:
                map<char, LetterInfo>::const_iterator it;

            public:

                const_iterator();
                const_iterator(map<char, LetterInfo>::const_iterator );
                
                const pair<const char, LetterInfo> & operator*(); // Devuelve una referencia al par clave-valor del mapa
                const pair<const char, LetterInfo> * operator->(); 

                const_iterator & operator++();
                bool operator!=(const const_iterator &) const;
                bool operator==(const const_iterator &) const;

                friend class LetterSet; 
        };
    
        /**
         * @brief Devuelve un iterador al inicio del conjunto
         */
        iterator begin();

        /**
         * @brief Devuelve un iterador al final del conjunto
         */
        iterator end();

        /**
         * @brief Devuelve un iterador constante al inicio del conjunto
         */
        const_iterator begin() const;
        
        /**
         * @brief Devuelve un iterador constante al final del conjunto
         */
        const_iterator end() const;
};

#endif
