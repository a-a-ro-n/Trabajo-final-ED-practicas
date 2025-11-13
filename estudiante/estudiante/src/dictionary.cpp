#include "dictionary.h"

//
// Created by 
//

//set<string> words;

/**
* @brief Constructor por defecto
*
* Crea un Dictionary vacío
*/
Dictionary::Dictionary()
{
    words = set<string>; // inicialiazmos el conjunto words a un conjunto vacio
}

/**
* @brief Destructor
*/
Dictionary::~Dictionary(){}

/**
* @brief Limpia el Dictionary
*
* @post el diccionario queda con 0 palabras
*/
void Dictionary::clear()
{
    words.clear(); // limpiamos el conjunto de palabras
}

/**
* @brief Tamaño del diccionario
*
* @return Número de palabras guardadas en el diccionario
*/
unsigned int Dictionary::size() const
{
    return word.size(); // devuelvo el tamaño del conjunto
}

/**
* @brief Comprueba si el diccionario está vacio.
* @return true si el diccionario está vacío, false en caso contrario
*/
bool Dictionary::empty() const 
{ 
    return words.size() == 0; 
}

/**
* @brief Indica si una palabra esta en el diccionario o no.
* Este método comprueba si una determinada palabra se encuentra o no en el dicccionario
* @param palabra: la palabra que se quiere buscar.
* @return Booleano indicando si la palabra existe o no en el diccionario
*/
bool Dictionary::exists(const string &val)
{
    return word.end() != words.find(val); // find devuelve el iterador( end() ) del conjunto si no esta
}

/**
* @brief Elimina una palabra del diccionario
*
* @param val Palabra a borrar del diccionario
*
* @return Booleano que indica si la palabra se ha borrado del diccionario
*/
bool Dictionary::erase(const string &val)
{
    return words.erease(val) != 0; // si erease no encuenta el val, devuelve un 0
}

/**
* @brief Sobrecarga del operador de entrada
*
* Permite leer las palabras de un fichero de texto e introducirlas en el
* diccionario
* @param is Flujo de entrada
* @param dic Diccionario a rellenar
* @return Flujo de entrada para poder encadenar el operador
*/
friend istream Dictionary::&operator>>(istream &is, Dictionary &dic)
{
    dis.words.insert(); // se deben de insertar plabra por palabra del diccionario

    return is;
}

/**
* @brief Sobrecarga del operador de salida
*
* Permite imprimir el diccionario completo a un flujo de salida
*
* @param os Flujo de salida, donde imprimir el diccionario
* @param dic Diccionario a imprimir
* @return Flujo de salida, para poder encadenar el operador
*/
friend ostream Dictionary::&operator<<(ostream &os, const Dictionary &dic)
{
    for( word : dic.words )
        os << word; // insertamos las palabras del diccionario en el flujo de salida

    return os;
}

/**
* @brief Indica el numero de apariciones de una letra.
*
*
* @param c letra a buscar.
* @return Un entero indicando el numero de apariciones.
*/
int Dictionary::getOccurrences(const char c)const;

/**
* @brief Indica el numero totales de letras
* @return Un entero indicando el numero totales de letras
*/
int Dictionary::getTotalLetters()const;

/**
* @brief Iterador del diccionario. Obtiene las palabras ordenadas alfabéticamente
*/
//set<string>::iterator it;
Dictionary::iterator ();
string Dictionary::iterator::operator *();
iterator & Dictionary::iterator::operator ++();
bool Dictionary::iterator::operator ==(const iterator &i);
bool Dictionary::iterator::operator !=(const iterator &i);

/**
* @brief Iterador constante del diccionario. Obtiene las palabras ordenadas alfabéticamente
*/
//set<string>::const_iterator it;
Dictionary::const_iterator ();
string Dictionary::const_iterator::operator *();
const_iterator & Dictionary::const_iterator::operator ++();
bool Dictionary::const_iterator::operator ==(const const_iterator &i);
bool Dictionary::const_iterator::operator !=(const const_iterator &i);

/**
* @brief Indica si una palabra esta en el diccionario
* @return iterador apuntando a la palabra si esta o end si no esta
*/
iterator Dictionary::find(const string & w)
{
    return words.find(w);
}

/**
* @brief Obtiene todas las palabras de una longitud
* param longitud: valor de longitud de la palabras a devolver
* @return un vector con palabra de la longitud dada
**/
vector<string> Dictionary::getWordsLength(int longitud);

/**
* @brief Inserta una palabra en el diccionario
*
* @param val palaba a insertar en el diccionario
* @return Booleano que indica si la inserción ha tenido éxito. Una palabra se inserta
* con éxito si no existía previamente en el diccionario. El iterador apunta a la palabra
*/
pair<iterator,bool> Dictionary::insert(const string &val);

/**
* @brief Busca un las palabras con un prefijo
*
* @param val prefijo a buscar
* @return un pair con dos iteradores el primero apuntando a la primera palaba con el prefijo y
* el segundo donde ya no contiene el prefijo. Si no existe el prefijo se devuelve los dos
* iteradores apuntando a end()
*/
pair<iterator, iterator> Dictionary::range_prefix(const string &val);

/**
* @brief Obtiene el iterador apuntando a la primera palabra del diccionario
*/
iterator Dictionary::begin() ;

const_iterator Dictionary::begin()const;

/**
* @brief Obtiene el iterador apuntando al final del diccionario.
*/
iterator Dictionary::end() ;

const_iterator Dictionary::end()const;     