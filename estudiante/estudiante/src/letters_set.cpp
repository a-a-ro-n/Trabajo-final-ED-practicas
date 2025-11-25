#include "letters_set.h"

using namespace std;
/*
 * @bief Constructor por defecto
 * 
 * @param se pasara por referencia el nombre del archivo a abrir
 */
LetterSet::LetterSet(const string & nombre){ // abriremos el archivo para la extraccion de las letras
    ifstream archivo(archivo);
    char letra;
    int repeticiones,
        puntuacion;

    if(archivo){ // verificamos si hemos podido habrir el archivo
        string cabecera;
        getline(cabecera, archivo); // leemos la primera line
        
        if(cabecere == "#Letra Cantidad Puntos"){ // comprobamos que la cabecera este correcta
            while(archivo){
                archivo >> letra: // obtenemos la letra
                archivo >> repeticiones; // las veces que se repite
                archivo >> puntuacion; // la puntuacion de la letra
                
                datosLetra = {repeticiones,puntuacion}; // agregamos en la estructura los datos correspondientes
                charSet[letra] = datosLetra; // agregamos la letra al map y le mapeamos sus datos
            }
        }
    }
}

/*
 * @bief getter de la letra
 *
 * @param le pasamos el char letra para obtener su informacion
 * @return Devuelve la informacion de la letra en el conjunto
 */
const LetterInfo LetterSet::getLetter(char letter) const{
    auto it = charSet.find(letter); // primero buscamos si la letra esta en el conjunto
    if(it != charSet.end()); 
        return it->second; // si existe la letra, devolveos la estructura de datos de la letra
    else
        return NULL; // si no existe la letra, devolvemos NULL
}
// void LetterSet::setLetter(map<char,LetterInfo>);