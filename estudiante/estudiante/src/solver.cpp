#include "solver.h"
//A completar

#include <string>
#include <utility>
#include <vector>

#include "letters_set.h"
#include "dictionary.h"

using namespace std;

bool Solver::poderConstruir(string palabra, vector<char> available_letters){
    bool esta = true;
    for(int i = 0; i < palabra.size() && esta; ++i){
        esta = false;
        for(auto it = available_letters.begin(); it != available_letters.end(); ++it){
            if(palabra[i] == *it){
                esta = true;
                auto it2 = it;
                it = available_letters.erase(it2);
            }
        }
    }
    return esta;
}

vector<string> Solver::getSolutions(const vector<char>& available_letters, bool score_game){
    Dictionary dict;
    vector<string> out = {""};  //para que cuando comparemos con la primera posición(linea34) no haya problema
    for(auto it = dict.begin(); it != dict.end(); ++it){
        if(!score_game){
            if(poderConstruir(*it, available_letters) ){
                if((*it).size() > out[0].size() ){    //comparo solo con el primer elemento, ya que si hay más, todos tendrán su mismo tamaño
                    out.clear();
                    out.push_back(*it);
                }else if((*it).size() == out[0].size() ){
                    out.push_back(*it);
                }
            }
        } else{

        }
        
    }
return out;
}

