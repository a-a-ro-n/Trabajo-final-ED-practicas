#include "letters_bag.h"

LettersBag::LettersBag(const LetterSet & conjunto){    // pasamos el numero de letras, y el conjunto dnde estan las letras
    auto it = conjunto.begin();         // iterador a la primera posicon del conjunto
    
    for(it; it != conjunto.end(); ++it){
        int reps = it->second.repetitions;  // repeticiones
        char letra = it->first;             // letra

        for(int i = 0; i < reps; i++)   // añadimos la letra tantas veces como repetciones tenga
            bag.push_back(letra);
    }
}

LettersBag::LettersBag(const string & nombre){
    ifstream archivo(nombre);
    char letra;

    while(archivo >> letra){
        
}

const char LettersBag::getLetter(int index) const { // conseguimos la letra
    char result = (index > -1 && index < bag.size()) ? bag[index] : '\0';
    return result;
}

// void setLetter(const char);          // añadimos la letra a la bolsa   (no le veo mucho sentido que podamos añadir letras)

const string LettersBag::toString() const { // mostramos por pantalla todas las letras de la bolsa
    string result = "{";
    
    if(!bag.empty()){
        for(int i = 0; i < bag.size(); ++i){
            result +=  bag[i];
            if(i < bag.size()-1)
                result += ",";
        }
    }
    
    result += "}";

    return result;
}

unsigned LettersBag::size() const {
    return bag.size();
}

bool LettersBag::empty() const {
    return bag.empty();
}

void LettersBag::clear() {
    bag.clear();
}

void LettersBag::erase(const char c) {
    auto it = find(bag.begin(), bag.end(), c); // buscamos c en el conjunto
    
    if (it != bag.end()) // si esta, la eliminamos
        bag.erase(it);
}

LettersBag::iterator::iterator(){}

LettersBag::iterator::iterator(vector<char>::iterator iter) : it(iter){}

char & LettersBag::iterator::operator*(){
    return *it;
}

LettersBag::iterator & LettersBag::iterator::operator++(){
    ++it;
    return *this;
}

bool LettersBag::iterator::operator!=(const iterator & other) const {
    return it != other.it; 
}

bool LettersBag::iterator::operator==(const iterator & other) const{
    return  it == other.it;
}

LettersBag::iterator LettersBag::begin(){
    return iterator(bag.begin());
}

LettersBag::iterator LettersBag::end(){
    return iterator(bag.end());
}