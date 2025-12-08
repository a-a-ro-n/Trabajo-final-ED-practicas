#include "letters_bag.h"

LettersBag::LettersBag(const LettersSet & conjunto){    // pasamos el numero de letras, y el conjunto dnde estan las letras
    auto it = conjunto.begin();         // iterador a la primera posicon del conjunto
    
    for(it; it != conjunto.end(); it++){
        int reps = it->second.repetitions;  // repeticiones
        char letra = it->first;             // letra

        for(int i = 0; i < reps; i++)   // añadimos la letra tantas veces como repetciones tenga
            bag.push_back(letra);
    }
}

const char LettersBag::getLetter(int index) const {     // conseguimos la letra
    char result = (index > -1 && index < bag.size()) ? bag[index] : '\0';
    return result;
}

// void setLetter(const char);          // añadimos la letra a la bolsa   (no le veo mucho sentido que podamos añadir letras)

const string LettersBag::toString() {   // mostramos por pantalla todas las letras de la bolsa
    string result = "{";
    for(int i = 0; i < bag.size()-1; i++)
       result +=  bag[i] + ",";
    result += bag[bag.size()-1] + "}";

    return result;
}

LettersBag::iterator::iterator(){
    /*
        vector<char>::iterator aux;
        it = aux;
    */
}

LettersBag::iterator::iterator(vector<char>::iterator & iter){
    it(iter);
}

char & LettersBag::iterator::operator*() const {
    return *it;
}

iterator & LettersBag::iterator::operator++(){
    ++it:
    return *this;
}

bool LettersBag::iterator::operator!=(const iterator & other) const {
    return it != other.it; 
}

bool LettersBag::iterator::operator==(const iterator & other) const{
    return  it == other.it;
}

LettersBag::iterator begin(){
    return iterator(bag.begin());
}

LettersBag::iterator end(){
    return iterator(bag.end());
}