#include <fstream>
#include <iostream>
#include <cmath>
#include "dictionary.h"
#include "letters_set.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 4){
      cout << "Los parametros son: " << endl;
      cout << "1.- El fichero con el diccionario" << endl;
      cout << "2.- El fichero con las letras" << endl;
      cout << "3.- El fichero de salida"<<endl;
      return 0;
    }

    ifstram dic(argv[1]);
    Dictionary diccionario;

    if(dic){ // Si se abre el archivo porporcionado, lo registramos como diccionario
        dic >> diccionario; 
        dic.close();
    }
    else{
        cerr << "Error al abrir el archivo del diccionario: " << argv[1] << endl;
        return 1;
    }

    LetterSet conjunto(argv[2]); // registramos el conjunto de letras
    
       
}
