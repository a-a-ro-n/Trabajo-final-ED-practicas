#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <climits>

#include <time.h>

using namespace std;

/**
  *@brief Cifras
  *Utilizamos dos funciones y un struct para calcular las operaciones necesarias para llegar a un número aleatorio de 3 cifras generado en el main, utilizando los números de un que se dan
  *
*/


/**
  *@brief struct solucion
  *Guarda una solución, guardando el valor al que se ha llegado, un string con las operaciones utilizadas para mostrarlas por pantalla y la cantidad de operaciones que han sido necesarias
*/
struct solucion{
   int valor;
    string op;
    int cantidad;
};

/**
  *@brief Calcula las posibles operaciones que se pueden conseguir, dadas una solución actual y un número que se le debe sumar, restar, multiplicar o dividir
  *
  *@param actual es la solución parcial
  *@param n es el número que operamos con actual
  *@return un vector de soluciones. Cada elemento será actual más/menos/por/entre n, según las operaciones que se puedan hacer (p.e. no puede haber números negativos)
*/

vector<solucion> GeneraOperaciones(solucion actual, int n){
   vector<solucion> v;
      solucion suma;
      suma.valor = actual.valor+n;
      if(actual.valor != 0){
        suma.op = actual.op+" "+to_string(actual.valor)+"+"+to_string(n);
        suma.cantidad = actual.cantidad+1;
      }
      v.push_back(suma);
   
      solucion resta;
      resta.valor = actual.valor-n;
      if(resta.valor >= 0){
         resta.op = actual.op+" "+to_string(actual.valor)+"-"+to_string(n);
         resta.cantidad = actual.cantidad+1;
         v.push_back(resta);      
      }
   
      solucion multiplicacion;
      multiplicacion.valor = actual.valor*n;
      if(actual.valor != 0){
        multiplicacion.op = actual.op+" "+to_string(actual.valor)+"*"+to_string(n);
        multiplicacion.cantidad = actual.cantidad+1;
      }
      v.push_back(multiplicacion);
   
      solucion division;
   
      if((actual.valor==0 || actual.valor%n == 0) && n != 0){
         division.valor = actual.valor/n;
         division.op = actual.op+" "+to_string(actual.valor)+"/"+to_string(n);
         division.cantidad = actual.cantidad+1;
         v.push_back(division);      
      }
   
   
   
   return v;
}

/**
  *@brief Calcula la mejor solución para llegar al objetivo con los números del conjunto S
  *@param S es el conjunto de números con los que hay que operar para obtener la solución
  *@param objetivo es el número que hay que alcanzar o acercarse al máximo
  *@param actual es la solucion actual, sobre la que seguiremos operando para llegar a la mejor
  *@param best es la mejor solución hasta el momento
  *@return devuelve una solucion con el valor exacto con el mínimo número de operaciones o la solución más cercana (también con el mínimo de operaciones)
*/

solucion Cifras(multiset<int> S, int objetivo, solucion actual, solucion best){
   multiset<int> restantes;
   vector<solucion> operaciones;
   if(actual.valor == objetivo && best.valor != objetivo){
      best = actual;
      return best;
   }
   int diferenciaActual = abs(actual.valor-objetivo);
   int diferenciaBest = abs(best.valor-objetivo);
   if(diferenciaActual < diferenciaBest || (diferenciaActual==diferenciaBest && /*actual.ops.cantidad < best.ops.cantidad*/ actual.cantidad < best.cantidad)){
      best = actual;
   }
   for (auto it = S.begin(); it != S.end() ; it++){
      restantes = S;
      auto it2 = restantes.find(*it);
      auto it3 = it2;
      it3++;
      restantes.erase(it2,it3);
      operaciones = GeneraOperaciones(actual,*it);
      for(auto it_aux = operaciones.begin(); it_aux != operaciones.end(); ++it_aux){
         best = Cifras(restantes, objetivo, *it_aux, best);
      }
   }
   return best;
}

/**
  *@Genera un multiset S de 6 elementos, escogidos al azar del conjunto C. Genera un número aleatorio de tres cifras al que hay que llegar. Pregunta al usuario su solución.
  * Esta solución no tiene usa paréntesis, hace las operaciones de izquierda a derecha hasta que hay un valor inválido (al usuario se le recomienda usar ..). 
  *Después calcula con Cifras, la mejor solución y la muestra por pantalla
*/

int main(){
   const vector<int> C = {1,2,3,4,5,6,7,8,9, 10, 25, 50, 75, 100};
   multiset<int> S;
   int objetivo;
   srand(time(NULL));
   int min = 100;
   int max = 1000;
   //genero número aleatorio de 3 cifras
   objetivo = (rand()%(max-min+1))+min;
   //cojo 6 números aleatorios de C
   min = 0;
   max = 13;
   for(int i = 0; i < 6; i++){
      S.insert(C[(rand()%(max+1))]);
   }
   
   solucion actual = {0,"",0};
   solucion best = actual;
   
   cout << "El conjunto es " << endl;
   for(auto it = S.begin(); it != S.end(); ++it){
        cout << *it << "\t";
    }

   cout << "El objetivo es " << objetivo << endl;
   solucion salida = Cifras(S,objetivo,actual,best);

   int num;
   int acumulador=0;
   char operador;
   bool valido = true;
    bool primero_valido = true;
   string tu_solucion;
   cout << "Dime tu solución. Usa '..' para terminar " << endl;
   cin >> acumulador;
   if((S.find(acumulador) == S.end())){
        valido = false;
        primero_valido = false;
        cout << "Primer elemento erróneo" << endl;
    } else{
        //si pongo solo S.erase borra todos los repetidos también
        for(auto it = S.begin(); it != S.end();){
            if(*it == acumulador){
                auto it2 = it;
                it = S.erase(it2);
                break;
            }else{
                ++it;
            }
        }
        while(valido){
            cin >> operador;    
            cin >> num;
            if((operador!='+' && operador != '-' && operador != '/' && operador != '*') || (S.find(num) == S.end()) || num < 0 || (operador=='-' && acumulador<=num) || (operador=='/' && num ==0) ){
                valido = false;
            } else{
                tu_solucion += "\t"+to_string(acumulador)+operador+to_string(num);
                for(auto it = S.begin(); it != S.end();){
                    if(*it == num){
                        auto it2 = it;
                        it = S.erase(it2);
                        break;
                    }else{
                        ++it;
                    }
                }
                if(operador == '+'){
                    acumulador += num;
                } else if (operador == '-'){
                    acumulador -= num;
                } else if (operador == '*'){
                    acumulador *= num;
                } else{
                    acumulador /= num;
                }
            }
        }

        cout << "Has llegado al valor: " << acumulador << "mediante las siguientes operaciones: " << tu_solucion << endl;
    }
   

   cout << "La mejor solución es " << salida.valor << ". Para ello, hemos realizado las siguientes operaciones: " <<  salida.op << endl;


}



