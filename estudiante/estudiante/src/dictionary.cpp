#include "dictionary.h"

//
// Created by aaron López Molino y 
//

//set<string> words;

/**
* @brief Constructor por defecto
*
* Crea un Dictionary vacío
*/
Dictionary::Dictionary() {}

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
    return words.size(); // devuelvo el tamaño del conjunto
}

/**
* @brief Comprueba si el diccionario está vacio.
* @return true si el diccionario está vacío, false en caso contrario
*/
bool Dictionary::empty() const 
{ 
    return words.empty(); 
}

/**
* @brief Indica si una palabra esta en el diccionario o no.
* Este método comprueba si una determinada palabra se encuentra o no en el dicccionario
* @param palabra: la palabra que se quiere buscar.
* @return Booleano indicando si la palabra existe o no en el diccionario
*/
bool Dictionary::exists(const string &val)
{
    return words.end() != words.find(val); // find devuelve el iterador( end() ) del conjunto si no esta
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
    return words.erase(val) != 0; // si erease no encuenta el val, devuelve un 0
}

/**
* @brief Sobrecarga del operador de entrada
*
* Permite leer las palabras de un fichero de texto e introducirlas en el
* diccionario
* @param isz Flujo de entrada
* @param dic Diccionario a rellenar
* @return Flujo de entrada para poder encadenar el operador
*/
istream & operator>>(istream &is, Dictionary &dic)
{
    string word;
    while(is >> word)
        dic.words.insert(word); // se deben de insertar plabra por palabra del diccionario

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
ostream & operator<<(ostream &os, const Dictionary &dic)
{
    for(string word : dic.words )
        os << word << "\n"; // insertamos las palabras del diccionario en el flujo de salida

    return os;
}

/**
* @brief Indica el numero de apariciones de una letra.
*
*
* @param c letra a buscar.
* @return Un entero indicando el numero de apariciones.
*/
int Dictionary::getOccurrences(const char c) const {
    int result = 0; 
    
    for(string word : words){
        for(char k : word){
            if(k==c)
                result++;
        }
    }

    return result;
}

/**
* @brief Indica el numero totales de letras
* @return Un entero indicando el numero totales de letras
*/
int Dictionary::getTotalLetters() const {
    int result = 0;

    for(string word : words)
        result += word.size(); // aumentamos el contador las letras que tenga word

    return result;
}

/**
* @brief Iterador del diccionario. Obtiene las palabras ordenadas alfabéticamente
*/
//set<string>::iterator it;
Dictionary::iterator::iterator(){}

Dictionary::iterator::iterator(set<string>::iterator otro){
    it = otro;
}

string Dictionary::iterator::operator *(){
    return *it;
}

Dictionary::iterator & Dictionary::iterator::operator ++(){
    ++it;
    return *this;
}

bool Dictionary::iterator::operator ==(const iterator &i){
    return it == i.it;
}

bool Dictionary::iterator::operator !=(const iterator &i){
    return it != i.it;
}

/**
* @brief Iterador constante del diccionario. Obtiene las palabras ordenadas alfabéticamente
*/
//set<string>::const_iterator it;
Dictionary::const_iterator::const_iterator(){}

Dictionary::const_iterator::const_iterator(set<string>::const_iterator otro){
    it = otro;
}

string Dictionary::const_iterator::operator *(){
    return *it;
}

Dictionary::const_iterator & Dictionary::const_iterator::operator ++(){
    ++it;
    return *this;
}

bool Dictionary::const_iterator::operator ==(const const_iterator &i){
    return it == i.it;
}

bool Dictionary::const_iterator::operator !=(const const_iterator &i){
    return it != i.it;
}

/**
* @brief Indica si una palabra esta en el diccionario
* @return iterador apuntando a la palabra si esta o end si no esta
*/
Dictionary::iterator Dictionary::find(const string & w)
{
    return iterator(words.find(w));
}

/**
* @brief Obtiene todas las palabras de una longitud
* param longitud: valor de longitud de la palabras a devolver
* @return un vector con palabra de la longitud dada
**/
vector<string> Dictionary::getWordsLength(int longitud){
    vector<string> result;

    for(string word : words){
        if(word.size() == longitud) // si tienen la misma longitud, lo insertamos en el vector
            result.push_back(word);
    }

    return result;
}

/**
* @brief Inserta una palabra en el diccionario
*
* @param val palaba a insertar en el diccionario
* @return Booleano que indica si la inserción ha tenido éxito. Una palabra se inserta
* con éxito si no existía previamente en el diccionario. El iterador apunta a la palabra
*/
std::pair<Dictionary::iterator,bool> Dictionary::insert(const string &val){
    auto insercion = words.insert(val); // esto ya devuelve un par
    return {iterator(insercion.first), insercion.second};
}

/**
* @brief Busca un las palabras con un prefijo
*
* @param val prefijo a buscar
* @return un pair con dos iteradores el primero apuntando a la primera palaba con el prefijo y
* el segundo donde ya no contiene el prefijo. Si no existe el prefijo se devuelve los dos
* iteradores apuntando a end()
*/
std::pair<Dictionary::iterator, Dictionary::iterator> Dictionary::range_prefix(const string &val){
    auto first = end(),
         last  = end();

    // Buscar la primera palabra con el prefijo
    for(auto it = begin(); it != end(); ++it) {
        string w = *it;

        // comprobar prefijo SIN compare
        if(w.size() >= val.size()) {
            bool ok = true;
            for(int i = 0; i < val.size() && ok; i++) {
                if(w[i] != val[i])
                    ok = false;
            }

            if (ok) // primera coincidencia
                first = it;
        }
    }

    if(first == end())
        return {end(), end()};

    auto it = first;
    for(; it != end(); ++it) {
        string w = *it;

        if(w.size() >= val.size()){
            bool ok = true;
            for (size_t i = 0; i < val.size() && ok; i++) {
                if(w[i] != val[i])
                    ok = false;
            }
        }
    }

    last = it;  // primera palabra que ya no cumple el prefijo

    return { iterator(first), iterator(last) };
}

/**
* @brief Obtiene el iterador apuntando a la primera palabra del diccionario
*/
Dictionary::iterator Dictionary::begin(){
    return iterator(words.begin());
}

Dictionary::const_iterator Dictionary::begin()const{
    return const_iterator(words.begin());
}

/**
* @brief Obtiene el iterador apuntando al final del diccionario.
*/
Dictionary::iterator Dictionary::end(){
    return iterator(words.end());
}

Dictionary::const_iterator Dictionary::end()const{
    return const_iterator(words.end());
}    