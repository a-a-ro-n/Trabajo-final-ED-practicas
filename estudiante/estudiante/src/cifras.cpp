#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <climits>

#include <time.h>

using namespace std;
 
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

        

 


};



