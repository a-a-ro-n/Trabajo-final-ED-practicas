#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "dictionary.h"
#include "letters_bag.h"
#include "letters_set.h"
#include "solver.h"

using namespace std;

void ModoPalabraMasLarga(LettersSet &, const int, const LettersBag &, string &, set<string> &, string &);
void ModoPalabraMayorPuntuacion(LettersSet &, const int, const LettersBag &, string &, set<string> &, string &);

int main(int argc, char *argv[])
{
    if(argc != 6)
        return 1; // si no tenemos todos los parametros de entrada salimos del programa
    
    LettersSet fichero(argv[4].toString());     // obtenemos las letras del archivo pasado
    const int CANTIDAD_LETRAS = argv[5];        // obtenemos la cantidad de laetras a tener
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

    bool seguir_jugando = true;
    while ( seguir_jugando )
    {
        cout << "Las letras son: ";
        string cadena = "";
        for( int i = 0; i < CANTIDAD_LETRAS; i++ )
            cadena += "\t" + letras[i];
        cout << cadena << endl;                     // sacamos por pantalla las letras

        cout << "Dime tu solucion: " ;
        cin >> solucion_usuario;                    // Recogemos la solucion apriori del usuario
        cout << solucion_usuario << endl;           // Imprimimos la solucion
        cout << solucion_usuario << "\tPuntuación: "
               << puntuacion_palabra << endl;       // Mostramos la puntuacion de la palabra

        cout << "\nMis soluciones son: " << endl; 
        for( solucion : soluciones )
            cout << solucion << "\tPuntuacion: " + puntuacion_palabra;

        cout << "Mejor Solucion: " << mejor_solucion << endl;
        
        char result = '\0';
        do
        {
            cout << "¿Quieres seguir jugando [S/N]?";
            char aux;
            cin >> aux;
            if (aux == 'S' || aux == 's')
                result = 's';
            else if ( aux == 'N' || aux == 'n')
                result = 'n';
        }
        while ( result == '\0' ) // mientras que no haya resultado, no se hace nada

        seguir_jugando = (result == 's') ? true : false;
    }
    
}


void ModoPalabraMasLarga(LettersSet &, const int, const LettersBag &, string &, set<string> &, string &)
{

}

void ModoPalabraMayorPuntuacion(LettersSet &, const int, const LettersBag &, string &, set<string> &, string &)
{
    int puntuacion_palabra = 0;
    bool seguir_jugando = true;

    while ( seguir_jugando ){
        cout << "Las letras son: ";
        string cadena = "";
        for( int i = 0; i < CANTIDAD_LETRAS; i++ )
            cadena += "\t" + letras[i];
        cout << cadena << endl;                     // sacamos por pantalla las letras

        cout << "Dime tu solucion: " ;
        cin >> solucion_usuario;                    // Recogemos la solucion apriori del usuario
        cout << solucion_usuario << endl;           // Imprimimos la solucion
        cout << solucion_usuario << "\tPuntuación: "
               << puntuacion_palabra << endl;       // Mostramos la puntuacion de la palabra

        cout << "\nMis soluciones son: " << endl; 
        for( solucion : soluciones )
            cout << solucion << "\tPuntuacion: " + puntuacion_palabra;

        cout << "Mejor Solucion: " << mejor_solucion << endl;
        
        char result = '\0';
        do
        {
            cout << "¿Quieres seguir jugando [S/N]?";
            char aux;
            cin >> aux;
            if (aux == 'S' || aux == 's')
                result = 's';
            else if ( aux == 'N' || aux == 'n')
                result = 'n';
        }
        while ( result == '\0' ) // mientras que no haya resultado, no se hace nada

        seguir_jugando = (result == 's') ? true : false;
    }
    
}