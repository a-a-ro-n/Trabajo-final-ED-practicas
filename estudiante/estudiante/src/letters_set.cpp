#include "letters_set.h"

using namespace std;

/*
 * @bief Constructor por defecto
 * 
 * @param se pasara por referencia el nombre del archivo a abrir
 */
LetterSet::LetterSet(const string & nombre){ // abriremos el archivo para la extraccion de las letras
    ifstream archivo(nombre); // abrimos el archivo
    char letra;
    LetterInfo datosLetra = LetterInfo(); // en caso que no se pueda abrir o leer el archivo se devuelve vacio

    if(archivo){                                    // verificamos si hemos podido habrir el archivo
        string cabecera;
        getline(archivo, cabecera);                 // leemos la primera line
        
        if(cabecera == "#Letra Cantidad Puntos"){   // comprobamos que la cabecera este correcta
            while(archivo){
                archivo >> letra;                   // obtenemos la letra
                archivo >> datosLetra.repetitions;  // las veces que se repite
                archivo >> datosLetra.score;        // la puntuacion de la letra
                
                charSet[letra] = datosLetra;        // agregamos la letra al map y le mapeamos sus datos
            }
        }
        else{
            cerr << "Archivo de formato invalido...\n\tSaliendo del programa";
            exit(1);   // salimos del programa si no es el archivo correspondiente
        }
    }
    else{
        cerr << "Archivo <" << nombre << "> no se ha podido abrir correctamente..";
        exit(1);       // salimos del constructor si no existe o no se pude abrir el archivo
    }
}

/*
 * @bief getter de la letra
 *
 * @param le pasamos el char letra para obtener su informacion
 * @return Devuelve la informacion de la letra en el conjunto
 */
const LetterInfo LetterSet::getLetterInfo(char letter) const{
    auto it = charSet.find(letter); // primero buscamos si la letra esta en el conjunto

    if(it != charSet.end()) 
        return it->second; // si existe la letra, devolveos la estructura de datos de la letra
    else
        return LetterInfo(); // si no existe la letra, devolvemos un LetterInfo vacio
}

// void LetterSet::setLetter(map<char,LetterInfo>); // añadimos la letra a la conjunto   (no le veo mucho sentido que podamos añadir letras)

bool LetterSet::empty() const {
    return charSet.empty();
}

unsigned LetterSet::size() const {
    return charSet.size();
}

LetterSet::iterator::iterator() {}

LetterSet::iterator::iterator(map<char, LetterInfo>::iterator iter) : it(iter) {}

pair<const char, LetterInfo> & LetterSet::iterator::operator*(){
    return *it;
}

pair<const char, LetterInfo>* LetterSet::iterator::operator->() {
    return &(*it);
}

LetterSet::iterator & LetterSet::iterator::operator++(){
    ++it;
    return *this;
}

bool LetterSet::iterator::operator!=(const iterator & other) const {
    return it != other.it;
}

bool LetterSet::iterator::operator==(const iterator & other) const {
    return it == other.it;
}

LetterSet::const_iterator::const_iterator() {}

LetterSet::const_iterator::const_iterator(const map<char, LetterInfo>::const_iterator iter) : it(iter) {}

const pair<const char, LetterInfo> & LetterSet::const_iterator::operator*(){
    return *it;
}

const pair<const char, LetterInfo>* LetterSet::const_iterator::operator->() {
    return &(*it);
}

LetterSet::const_iterator & LetterSet::const_iterator::operator++(){
    ++it;
    return *this;
}

bool LetterSet::const_iterator::operator!=(const const_iterator & other) const {
    return it != other.it;
}

bool LetterSet::const_iterator::operator==(const const_iterator & other) const {
    return it == other.it;
}

LetterSet::iterator LetterSet::begin() {
    return iterator(charSet.begin());
}

LetterSet::iterator LetterSet::end() {
    return iterator(charSet.end());
}

LetterSet::const_iterator LetterSet::begin() const {
    return const_iterator(charSet.begin());
}

LetterSet::const_iterator LetterSet::end() const {
    return const_iterator(charSet.end());
}