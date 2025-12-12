#include <fstream>
#include <iostream>
#include <cmath>
#include "dictionary.h"
#include "letters_set.h"
#include <limits>
#include <vector>

using namespace std;

struct letra{
    char caracter;
    int apariciones;
    double porcentaje;
};

int main(int argc, char *argv[])
{
    if(argc != 4){
      cout << "Los parametros son: " << endl;
      cout << "1.- El fichero con el diccionario" << endl;
      cout << "2.- El fichero con las letras" << endl;
      cout << "3.- El fichero de salida"<<endl;
      return 0;
    }

    Dictionary diccionario;
    ifstream dic(argv[1]);
    

    if(dic){ // Si se abre el archivo porporcionado, lo registramos como diccionario
        dic >> diccionario; 
        dic.close();
    }
    else{
        cerr << "Error al abrir el archivo del diccionario: " << argv[1] << endl;
        return 1;
    }

    ofstream salida(argv[3]);
    if(!salida){
        cerr << "Error al abrir el archivo de salida: " << argv[3] << endl;
        return 1;
    }

    LetterSet conjunto(argv[2]); // registramos el conjunto de letras

    double min = numeric_limits<double>::infinity();

    int total_letras = diccionario.getTotalLetters();
    vector<letra> v(conjunto.size());
    int apariciones;
    double porcentaje;
    double min_log;
    int i = 0;
    for(auto it = conjunto.begin(); it != conjunto.end(); ++it){
        v[i].caracter = it->first;
        apariciones = diccionario.getOccurrences(it->first);
        v[i].apariciones = apariciones;
        porcentaje = (double)apariciones/total_letras;
        v[i].porcentaje = porcentaje;
        if(min > porcentaje){
            min = porcentaje;
        }
        ++i;
    }
    min_log = -log10(min);
    salida << "#Letra\tCantidad\tPuntos" << endl;
    for(auto it = v.begin(); it != v.end(); ++it){
        salida << it->caracter << "\t" << it->apariciones << "\t" << (int)(10*(-log10(it->porcentaje)/min_log)) << endl;
    }
    
    salida.close();
}
