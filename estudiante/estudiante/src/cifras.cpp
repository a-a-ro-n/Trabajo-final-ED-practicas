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
        set<int> opciones;  //uso set porque son más eficientes los borrados e inserciones
        int num_aleatorio;
     //pruebass
    public:
        Cifras(){
            srand(time(NULL));
            int min = 100;
            int max = 1000;
            //genero número aleatorio de 3 cifras
            num_aleatorio = rand()%(min-max+1);
            //cojo 6 números aleatorios de C
            min = 0;
            max = 13;
            for(int i = 0; i < 6; i++){
                opciones.insert(C[rand()%(min-max+1)]);
            }
        }

        string 


}

