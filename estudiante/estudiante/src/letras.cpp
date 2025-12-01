#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

#include "dictionary.h"
#include "letters_bag.h"
#include "letters_set.h"
#include "solver.h"


using namespace std;

void ModoPalabraMasLarga(LettersSet &, const int, const LettersBag &, string &, set<string> &, string &);
void ModoPalabraMayorPuntuacion(LettersSet &, const int, const LettersBag &, string &, set<string> &, string &);

int main(int argc, char *argv[]){
    if(argc != 6)
        return 1; // si no tenemos todos los parametros de entrada salimos del programa
    
    LettersSet fichero(argv[4].toString());     // obtenemos las letras del archivo pasado
    const int CANTIDAD_LETRAS = argv[5].stoi(); // obtenemos la cantidad de laetras a tener
    const LettersBag letras(CANTIDAD_LETRAS);   // contenedor de letras para formar la palabra

    string solucion_usuario = "";               // palabra digitada por el usuario
    set<string> soluciones;                     // contenedor de resultados
    string mejor_solucion = "";                 // almaceno la mejor solucion

    char modo = argv[6];                        // obtengo el modo de juego
    if(modo == L || modo == l)
        ModoPalabraMasLarga(fichero, CANTIDAD_LETRAS, solucion_usuario, soluciones, mejor_solucion);
    else if (modo == P || modo == p)
        ModoPalabraMayorPuntuacion(fichero, CANTIDAD_LETRAS, solucion_usuario, soluciones, mejor_solucion);
    else{
        cerr << "Error... \n\t parametro 6 (modo de juego) no corresponde con lo esperado [P/L]";
        return 1
    }

    return 0;
}


void ModoPalabraMasLarga(LettersSet & fichero, const int CANTIDAD_LETRAS, const LettersBag & letras, string & solucion_usuario, set<string> & soluciones, string & mejor_solucion){

}

void ModoPalabraMayorPuntuacion(LettersSet & fichero, const int CANTIDAD_LETRAS, const LettersBag & letras, string & solucion_usuario, set<string> & soluciones, string & mejor_solucion){
    srand(time(NULL));                              // obtenemos una semilla en este mismo intante
    int puntuacion_palabra = 0;
    bool seguir_jugando = true;

    while ( seguir_jugando ){
        cout << "Las letras son: ";
        string cadena = "";

        multimap<int,char> posicion_letra[CANTIDAD_LETRAS];      // map de la posicion de las letras para manejarlas como un array
        multimap<char,int> puntuacion_letra[CANTIDAD_LETRAS];    // map de puntuacion las letras, dadas una letra

        for( int i = 0; i < CANTIDAD_LETRAS; i++ ){
            char c = letras[rand() % letras.size()];    // obtenemos la letra
            int puntuacion = fichero.get[c].score;      // obtenemos la puntuacion de la letra

            posicion_letra[i] = c;                      // añadimos en la posicion i la letra aleatoria del conjunto
            puntuacion_letra[c] = puntuacion;           // añadimos la puntuacion dada la letra obtenida;

            cadena += "\t" + posicion_letra[i];
        }
        cout << cadena << endl;                     // sacamos por pantalla las letras

        cout << "Dime tu solucion: " ;
        cin >> solucion_usuario;                    // Recogemos la solucion apriori del usuario
        cout << solucion_usuario << endl;           // Imprimimos la solucion
        /*
            HAY QUE COMPROBAR SI LA PALABRA EXISTE SIENDO VALIDA 
        */
        cout << solucion_usuario << "\tPuntuación: "
               << puntuacion_palabra << endl;       // Mostramos la puntuacion de la palabra

        cout << "\nMis soluciones son: " << endl; 
        for( solucion : soluciones )
            cout << solucion << "\tPuntuacion: " + puntuacion_palabra;

        cout << "Mejor Solucion: " << mejor_solucion << endl;
        
        char result = '\0';
        do{
            cout << "¿Quieres seguir jugando [S/N]?";
            char aux;
            cin >> aux;
            if (aux == 'S' || aux == 's')
                result = 's';
            else if ( aux == 'N' || aux == 'n')
                result = 'n';
        }while ( result == '\0') // mientras que no haya resultado, no se hace nada

        seguir_jugando = (result == 's') ? true : false;
    }
    
}