#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <set>

#include "dictionary.h"     // diccionario
#include "letters_bag.h"    // bolsa de letras repetidas
#include "letters_set.h"    // conjunto de todas las letras con puntuaciones y repeticiones
#include "solver.h"         // puntuacion y construccion de palabras


using namespace std;

void ModoPalabraMasLarga(Solver & , const LetterSet & , const int , string & , set<string> & , string &);
void ModoPalabraMayorPuntuacion(Solver & , const LetterSet & , const int , string & , set<string> & , string &);

int main(int argc, char *argv[]){
    if(argc != 5){
        cerr << "Error. Número de argumentos incorrecto. Se esperan 4 argumentos: \n\t1. Ruta del archivo del diccionario.\n"
             << "\t2. Ruta del archivo de letras (LetterSet).\n\t3. Cantidad de letras a repartir (entero positivo).\n"
             << "\t4. Modo de juego (L para Palabra Más Larga, P para Mayor Puntuación).\n";

        return 1;
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

    LetterSet set_config(argv[2]); // registramos el conjunto de letras
    Solver solver(diccionario, set_config); 

    int CANTIDAD_LETRAS = stoi(argv[3]); // obtenemos la cantidad de letras con las que se jugaran
    if (CANTIDAD_LETRAS <= 0) {
        cerr << "Error... Cantidad de letras debe ser un entero positivo, no " << argv[3] << endl;
        return 1;
    }

    string solucion_usuario = "";               
    set<string> soluciones;                     
    string mejor_solucion = "";                 

    char modo = *argv[4]; // obtenemos el modo de juego
    
    if(modo == 'L' || modo == 'l')
        ModoPalabraMasLarga(solver, set_config, CANTIDAD_LETRAS, solucion_usuario, soluciones, mejor_solucion);
    else if (modo == 'P' || modo == 'p')
        ModoPalabraMayorPuntuacion(solver, set_config, CANTIDAD_LETRAS, solucion_usuario, soluciones, mejor_solucion);
    else{
        cerr << "Error... \n\t parametro 4 (modo de juego) no corresponde con lo esperado [P/L]" << endl;
        return 1;
    }

    return 0;
}

void ModoPalabraMasLarga(Solver & solver, const LetterSet & set_config, const int CANTIDAD_LETRAS, string & solucion_user, set<string> & soluciones, string & mejor_solucion){
    srand(time(NULL));
    bool seguir_jugando = true;

// ---------------------------------------------------------------------
    while(seguir_jugando){
        LettersBag bag(set_config); // Nueva bolsa para la ronda
        vector<char> letras;
        string letras_string = "";
        
        for(int i = 0; i < CANTIDAD_LETRAS; i++){
            if(bag.size() > 0) { // si la bolsa no esta vacia, cogemos una letra aleatoria del conjunto
                int indice = rand() % bag.size(),
                    count = 0; // contador para obtener la posicion

                LettersBag::iterator it = bag.begin();
                
                while(count != indice && it != bag.end()){ // avanzamos it hasta que lleguemos a la posicion indicada o no tengamos mas espacio en bag
                    ++it;
                    count++;
                }

                char c = *it; // obtenemos la letra y la quitamos del conjunto
                bag.erase(c); 
                
                letras.push_back(c); // añadimos al vector la letra obtenida de forma aleatoria
                letras_string += c;
            }
        }

        cout << "Las letras son: " << letras_string << endl; // mostramos las letras
// ---------------------------------------------------------------------

        soluciones.clear(); 
        mejor_solucion = "";
        int tamaño = 0;

// ---------------------------------------------------------------------
        vector<string> soluciones_globales = solver.getSolutions(letras, false); // Llamada al Solver para obtener todas las palabras válidas

        for(string word : soluciones_globales){
            soluciones.insert(word); // insertamos las soluciones en el conjunto
            
            
            if(word.size() > tamaño){ // buscamos la palabra más larga
                tamaño = word.size();
                mejor_solucion = word;
            }
        }
// ---------------------------------------------------------------------

        cout << "Dime tu solucion: " ;
        cin >> solucion_user;
        cout << "\nLa palabra del usuario es: " << solucion_user << endl;

// ---------------------------------------------------------------------
        bool valido = (soluciones.find(solucion_user) != soluciones.end()); // si la palabra del usuario está en la lista de soluciones, es válida.
        
        if (valido)
            cout << "Palabra válida. Longitud: " << solucion_user.size() << endl;
        else
            cout << "Palabra inválida (no existe en el diccionario o no se puede formar con las letras disponibles)." << endl;
        

        cout << "\nMis soluciones son: " << endl; // soluciones del programa
        for(string sol : soluciones)
            cout << sol << "\tLongitud: " << sol.size() << endl;
        
        cout << "\nMejor Solucion (Longitud Máxima): " << mejor_solucion << "\tLongitud: " << tamaño << endl;
// ---------------------------------------------------------------------

        char result = '\0';
        do {
            cout << "¿Quieres seguir jugando [S/N]?";
            char aux;
            cin >> aux;
            if (aux == 'S' || aux == 's')
                result = 's';
            else if ( aux == 'N' || aux == 'n')
                result = 'n';
        } while (result == '\0'); 

        seguir_jugando = (result == 's'); // volver a jugar?
    }
}

void ModoPalabraMayorPuntuacion(Solver & solver, const LetterSet & set_config, const int CANTIDAD_LETRAS, string & solucion_user, set<string> & soluciones, string & mejor_solucion){
    srand(time(NULL));
    bool seguir_jugando = true;

// ---------------------------------------------------------------------
    while(seguir_jugando){
        LettersBag bag(set_config); // Nueva bolsa para la ronda
        vector<char> letras;
        string letras_string = "";
        
        for(int i = 0; i < CANTIDAD_LETRAS; i++){
            if(bag.size() > 0){
                int indice = rand() % bag.size(),
                    count = 0; // contador para obtener la posicion

                LettersBag::iterator it = bag.begin();
                
                while(count != indice && it != bag.end()){ // avanzamos it hasta que lleguemos a la posicion indicada o no tengamos mas espacio en bag
                    ++it;
                    count++;
                }
 
                char c = *it; // obtenemos la letra y la quitamos del conjunto
                bag.erase(c); 
                
                letras.push_back(c); // añadimos al vector la letra obtenida de forma aleatoria
                letras_string += c;
            }
        }
        
        cout << "Las letras son: " << letras_string << endl;
// ---------------------------------------------------------------------

        soluciones.clear();
        mejor_solucion = "";
        int max_score = -1;

// ---------------------------------------------------------------------
        vector<string> soluciones_globales = solver.getSolutions(letras, true);  // Llamada al Solver para obtener todas las palabras válidas

        for(string word : soluciones_globales) {
            soluciones.insert(word); // añadimos los resultados al conjunto de soluciones
            int score = solver.puntosPalabra(word); 
            
            
            if(score > max_score){ // buscamos la palabra de mayor puntuación
                max_score = score;
                mejor_solucion = word;
            } 
            else if(score == max_score){ // si la puntuacion maxima coincide con la puntuacion de la actual, miramos la longitud
                if (word.size() > mejor_solucion.size()) // la de mayor longitud gana
                    mejor_solucion = word;
            }
        }
// ---------------------------------------------------------------------

        cout << "Dime tu solucion: " ;
        cin >> solucion_user;
        cout << "La palabra del usuario es: " << solucion_user << endl;
        
// ---------------------------------------------------------------------
        int user_score = 0;
        bool valido = soluciones.count(solucion_user) > 0;

        if(valido){
            user_score = solver.puntosPalabra(solucion_user);
            cout << "Palabra válida. Puntuación: " << user_score << endl;
        } 
        else
            cout << "Palabra inválida (no existe en el diccionario o no se puede formar con las letras disponibles)." << endl;
        
        cout << "\nMis soluciones son: " << endl; // soluciones del programa
        for(string sol : soluciones)
            cout << sol << "\tPuntuación: " << solver.puntosPalabra(sol) << endl;
        
        cout << "Mejor Solucion (Mayor Puntuación): " << mejor_solucion << "\tPuntuación: " << max_score << endl;
// ---------------------------------------------------------------------

        char result = '\0';
        do {
            cout << "¿Quieres seguir jugando [S/N]?";
            char aux;
            cin >> aux;
            if (aux == 'S' || aux == 's')
                result = 's';
            else if ( aux == 'N' || aux == 'n')
                result = 'n';
        } while (result == '\0');

        seguir_jugando = (result == 's'); // seguir jugando?
    }
}