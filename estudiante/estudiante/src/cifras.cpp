#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <climits>

#include <time.h>

using namespace std;
/* 
class Cifras{  
    private:
        const vector<int> C = {1,2,3,4,5,6,7,8,9, 10, 25, 50, 75, 100};
        multiset<int> S;  //uso set porque son más eficientes los borrados e inserciones

            // porque no puebas a hacerlo con un multiset ya que los 
            // numeros que te pueden salir en el conjunto pueden estar repetidos

        int objetivo;

     //pruebass
    public:
        Cifras(){
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
        }
};*/

// CREO QUE ESTO SE PUDE HACER CON UN MAP<INT,STRING> 
struct operaciones{
   string op;
   int cantidad;
};

struct solucion{
   int valor;
   operaciones ops;
};

vector<solucion> GeneraOperaciones(solucion actual, int n){
   vector<solucion> v;
      solucion suma;
      suma.valor = actual.valor+n;
      suma.ops.op = actual.ops.op+" "+to_string(actual.valor)+"+"+to_string(n);
      suma.ops.cantidad = actual.ops.cantidad+1;
      v.push_back(suma);
   
      solucion resta;
      resta.valor = actual.valor-n;
      if(resta.valor >= 0){
         resta.ops.op = actual.ops.op+" "+to_string(actual.valor)+"-"+to_string(n);
         resta.ops.cantidad = actual.ops.cantidad+1;
         v.push_back(resta);      
      }
   
      solucion multiplicacion;
      multiplicacion.valor = actual.valor*n;
      multiplicacion.ops.op = actual.ops.op+" "+to_string(actual.valor)+"*"+to_string(n);
      multiplicacion.ops.cantidad = actual.ops.cantidad+1;
      v.push_back(multiplicacion);
   
      solucion division;
   
      if((actual.valor==0 || actual.valor%n == 0) && n != 0){
         division.valor = actual.valor/n;
         division.ops.op = actual.ops.op+" "+to_string(actual.valor)+"/"+to_string(n);
         division.ops.cantidad = actual.ops.cantidad+1;
         v.push_back(division);      
      }
   
   
   
   return v;
}

solucion Cifras(multiset<int> S, int objetivo, solucion actual, solucion best){
   multiset<int> restantes;
   vector<solucion> operaciones;
   if(actual.valor == objetivo && best.valor != objetivo){
      best = actual;
      return best;
   }
   int diferenciaActual = abs(actual.valor-objetivo);
   int diferenciaBest = abs(best.valor-objetivo);
   if(diferenciaActual < diferenciaBest || (diferenciaActual==diferenciaBest && actual.ops.cantidad < best.ops.cantidad )){
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
         //cout << (*it_aux).ops.op << "\n";
         best = Cifras(restantes, objetivo, *it_aux, best);
         //cout << best.valor << ", " << best.ops.op << "\n";
      }
   }
   return best;
}



