#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <iostream>
#include <string>
#include <ifstream> // para la apertura del archivo y extraccion de letras
#include <map>

using namespace std;

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


class LettersSet{
    private:
        map<char, LetterInfo> charSet;  // mapeado de las letras
        string fichero;                 // Nombre del fichero a leer

    public:
        /*
         * @bief Constructor por defecto
         * 
         * @param se pasara por referencia el nombre del archivo a abrir
         */
        LetterSet(const string & archivo); // abriremos el archivo para la extraccion de las letras

        /*
         * @bief getter de la letra
         *
         * @param le pasamos el char letra para obtener su informacion
         * @return Devuelve la informacion de la letra en el conjunto
         */
        const LetterInfo getLetter(char letra) const;
        // void setLetter(map<char,LetterInfo>); // inecesaria implementacion
};

#endif
